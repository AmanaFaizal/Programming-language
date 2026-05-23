# Control Stack Evaluator (CSE) Machine

This document describes the runtime model implemented in `src/CSEMachine.cpp/.h`. The CSE Machine evaluates the standardized AST by operating on:

- a `control` list (instructions),
- a `stack` (values/closures), and
- a tree of lexical `Environment` objects.

## Files

- `src/CSEMachine.h` — type definitions: `ItemType`, `Environment`, `CSEItem`, and `CSEMachine` API.
- `src/CSEMachine.cpp` — implementation: AST flattening into `deltas`, the main evaluation loop, and primitive operators.

## Core Data Structures

- `ItemType` — enum of runtime kinds: `INTEGER`, `STRING`, `TRUTH_VALUE`, `DUMMY`, `NIL`, `IDENTIFIER`, `OPERATOR`, `LAMBDA`, `GAMMA`, `ENV_MARKER`, `CLOSURE`, `ETA_CLOSURE`, `TUPLE`, `PRIMITIVE_FUNC`.

- `Environment` — tree node with `id`, `parent`, and `bindings` mapping names to `CSEItem` values. `lookup(name)` climbs parents to find a binding.

- `CSEItem` — runtime value wrapper with fields used by different `ItemType`s:
  - `type`, `value` (string),
  - `delta_index` (for lambdas/closures),
  - `env_ptr` / `previous_env` / `closure_ptr` (env/closure links),
  - `bound_var` / `bound_vars` (parameter names),
  - `tuple_items` (for constructed tuples).

## Compilation: flatten() & Deltas

- The Standardized AST is flattened into a vector of instruction blocks called `deltas`.
  - `deltas[0]` is the top-level delta.
  - Each `lambda` node creates a new delta index for the function body; the `LAMBDA`-style `CSEItem` records that `delta_index` and parameter names.

- `flatten(node, idx)` walks the tree post-order and appends `CSEItem`s into `deltas[idx]`. Special nodes handled during flattening include:
  - `lambda` — allocates a new delta and emits a `LAMBDA` item that records parameter(s) and the new delta index.
  - `->` (conditional) — flattens the boolean test in the current delta and creates two new deltas for `then` and `else`, emitting an `OPERATOR` `beta` that stores those delta indices.
  - Other nodes are converted to `CSEItem`s via `createItemFromNode()` (identifiers, constants, operators, `tau`, `Ystar`, etc.).

## Machine: startup state

- The machine constructs a global environment `PE` (id 0) and sets `current_env = PE`.
- `deltas` is built by `flatten(root, 0)`.
- An `ENV_MARKER` for `PE` is created and pushed to `control` and `stack` to seed evaluation.

## Evaluation loop (summary)

- Loop until `control` is empty; pop the next `item` from `control` and act based on `item->type`.

- Value-like items (INTEGER, STRING, TRUTH_VALUE, DUMMY, NIL, CLOSURE, PRIMITIVE_FUNC, ETA_CLOSURE, and materialized TUPLE values) are pushed onto the `stack`.

- `IDENTIFIER` — resolved via `current_env->lookup(name)`; if not found and the name is `Print` it is treated as a primitive; otherwise an error is raised.

- `LAMBDA` — converted to a `CLOSURE` when encountered at runtime: a closure stores `delta_index`, binding names, and a pointer to the `current_env` (lexical environment).

- `GAMMA` (application) — pops `rand` (argument) and `rator` (function/operator) from the `stack` and dispatches:
  - `CLOSURE`: create a new `Environment` with parent = closure's `env_ptr`; bind parameters (either `bound_vars` tuple extraction or single `bound_var`) to `rand`/tuple items; push an `ENV_MARKER` (stores previous env), set `current_env` to the new env, and push the closure body delta items onto `control`.
  - `PRIMITIVE_FUNC`: if `Ystar`, create an `ETA_CLOSURE` wrapping `rand`; otherwise push `rand` back and call `applyPrimitive(name)` to handle the primitive.
  - `ETA_CLOSURE`: supports the `Ystar` behavior by arranging two `GAMMA` items and re-pushing the closure and the `eta` wrapper to trigger self-application.

- `ENV_MARKER` — restores `current_env` from the marker's `previous_env`; the top-of-stack result is kept and the marker is removed.

- `TUPLE` with value `tau` — when a `tau` operator item is executed, it reads `n` from the item, pops `n` values from `stack`, and constructs a `TUPLE` `CSEItem` with `tuple_items` filled.

- `OPERATOR` — operators are dispatched:
  - `beta` — conditional: pop boolean result, determine index using stored `bound_vars` (the two delta indices), and push the selected delta's items into `control`.
  - `neg` / `not` — handled as unary operators via `applyUnaryOp`.
  - other operator names — handled as binary ops via `applyBinaryOp`.

## Primitive functions (implemented / recognized)

The implementation recognizes a set of primitive names (see `createItemFromNode`):

- `Print` — prints a single value using `printItem()` and pushes a `DUMMY` result.
- `Stern`, `Stem`, `Conc`, `Order`, `Null`, `Isinteger`, `Isstring`, `Istuple`, `Istruthvalue`, `Isfunction`, `ItoS`, `Cond`, `aug`, `Ystar` — recognized as `PRIMITIVE_FUNC` items when encountered as identifiers during flattening.

Note: The present `CSEMachine.cpp` only implements `Print`, `+` (in `applyBinaryOp`) and `not`/`neg` (in `applyUnaryOp`) concretely; other primitives are recognized and would be dispatched via `applyPrimitive` or future implementations.

## Error handling and special cases

- Identifier lookup throws `runtime_error("Undeclared identifier: " + name)` when a non-primitive identifier is not found in the environment chain.
- The machine checks for stack underflow conditions (e.g., in `GAMMA`) and throws descriptive errors.

## Where to look in code

- Delta construction and initial state: `CSEMachine::CSEMachine(shared_ptr<TreeNode> root)` in `src/CSEMachine.cpp`.
- Runtime loop: `CSEMachine::evaluate()` in `src/CSEMachine.cpp`.
- Node → item mapping: `CSEMachine::createItemFromNode(shared_ptr<TreeNode>)`.
- Primitive and operator dispatch: `applyPrimitive`, `applyBinaryOp`, `applyUnaryOp`.

For implementation details and to see exactly which primitives are active or partially implemented, inspect [src/CSEMachine.cpp](src/CSEMachine.cpp) and [src/CSEMachine.h](src/CSEMachine.h).
