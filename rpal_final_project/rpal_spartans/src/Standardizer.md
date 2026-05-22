# AST Standardizer

The Standardizer modifies the parsed Abstract Syntax Tree (AST) into a standard, simplified form before it is evaluated by the CSE Machine. This step maps higher-level syntactic sugar (such as nested function declarations, let-bindings, and simultaneous declarations) into core lambda-calculus representations.

## Files

- `src/Standardizer.h`: Declares the `Standardizer` class.
- `src/Standardizer.cpp`: Implements the tree-walking transformation rules.

## Standardization Rules

The Standardizer performs a post-order traversal (standardizing children first) and maps nodes as follows:

| AST Construct                  | Original Node Structure       | Standardized Structure                                         | Explanation                                                                                |
| ------------------------------ | ----------------------------- | -------------------------------------------------------------- | ------------------------------------------------------------------------------------------ |
| **Let-Binding**                | `let ( = X E ) P`             | `gamma ( lambda X P ) E`                                       | Invokes the body `P` as a lambda applied to the initialization value `E`.                  |
| **Where-Clause**               | `where P ( = X E )`           | `gamma ( lambda X P ) E`                                       | Identical semantics to let-binding.                                                        |
| **Function Definition Form**   | `fcn_form f V1 V2 ... Vn E`   | `(= f (lambda V1 (lambda V2 ... (lambda Vn E))))`              | Translates n-ary parameters into a curried function definition.                            |
| **Simultaneous Definition**    | `and (= X1 E1) (= X2 E2) ...` | `(= ( , X1 X2 ... ) ( tau E1 E2 ... ))`                        | Combines identifiers into a comma-list and values into a tuple.                            |
| **Recursive Definition**       | `rec (= X E)`                 | `(= X (gamma Ystar (lambda X E)))`                             | Wraps the definition with the fixed-point combinator `Ystar` to support recursion.         |
| **Infix Operator Application** | `@ E1 N E2`                   | `gamma ( gamma N E1 ) E2`                                      | Curries the binary operation `N` applied to `E1` and `E2`.                                 |
| **Conditional Expression**     | `-> B T E`                    | `gamma ( gamma ( gamma Cond B ) (lambda () T) ) (lambda () E)` | Evaluates conditional branching dynamically by wrapping then/else blocks in dummy lambdas. |
| **N-ary Lambdas**              | `lambda V1 V2 ... Vn E`       | `lambda V1 (lambda V2 ... (lambda Vn E))`                      | Translates multi-variable lambdas into curried single-variable lambdas.                    |

## Parameter Tupling vs Currying

If a lambda has a variable list defined inside parentheses (e.g., `lambda (x, y). E`), it indicates parameter tupling. The Standardizer handles this by introducing a temporary variable `T++` and mapping it to:
`lambda T++. (gamma (lambda x. (gamma (lambda y. E) (gamma T++ 2))) (gamma T++ 1))`
This pulls elements out of the tuple `T++` by indexing them during parameter binding.

## What We Did

- Resolved standardizer conflicts by removing manual overrides for boolean `not` and unary `neg` (which are evaluated as native operators by the CSE machine instead of standardized terms).
- Fixed the tree restructuring logic to ensure sibling nodes are correctly re-linked when a node is replaced by its standardized version.

## Implementation notes (accurate to `Standardizer.cpp`)

- Public API
  - `Standardizer::standardize(shared_ptr<TreeNode> root)` — entry point; performs a recursive post-order transformation and returns the transformed root.

- Key helpers
  - `makeNode(type, value)` — convenience constructor for `TreeNode` wrapper nodes.
  - `detachSiblings(start)` — extracts a flat `vector` of sibling nodes starting at `start`, breaking sibling links (used for argument/param lists).
  - `makeGamma(left, right)` — builds a `gamma` application linking `left` and `right`.
  - `createLambda(V, E)` — canonicalizes lambda forms. Handles:
    - Tuple parameter lists (`V->type == ","`) by creating a single temporary identifier `T++` and generating nested `gamma`/`lambda` expressions that extract tuple components by index,
    - Single-parameter or already-curried lambdas by producing `lambda V E` (simple link).

- Node-by-node transformations
  - `let (= X E) P` -> `gamma (lambda X P) E` — converts local value bindings into an application of a one-arg lambda.
  - `where P (= X E)` -> `gamma (lambda X P) E` — same as `let`, but source order differs; the standardizer detaches siblings and rewires accordingly.
  - `within (= X1 E1) (= X2 E2)` -> `= X2 (gamma (lambda X1 E2) E1)` — rewrites the `within` as a nested application and produces an `=` node for the second binding.
  - `rec (= X E)` -> `= X (gamma Ystar (lambda X E))` — introduces a `Ystar` (fixed-point primitive) wrapper to support recursion.
  - `fcn_form P V1 V2 ... Vn E` -> `= P (lambda V1 (lambda V2 ... (lambda Vn E)))` — curried function form becomes nested lambdas.
  - `and (= X1 E1) (= X2 E2) ...` -> `= ( , X1 X2 ... ) ( tau E1 E2 ... )` — simultaneous definitions are converted to a comma-list of identifiers and a `tau` tuple of expressions.
  - `@ E1 N E2` -> `gamma ( gamma N E1 ) E2` — infix operator application is expanded into two curried `gamma` applications.
  - `-> B T E` -> compiled into a `beta` operator: the standardizer emits separate deltas for `T` and `E` and replaces `->` with an operator node `beta` that records the two delta indices.
  - `lambda` nodes
    - Tuple parameter lists are transformed via `createLambda` (see above).
    - Multiple variables written in sequence are converted to nested single-arg `lambda` nodes (curried form).

## Examples

- Tuple lambda

Input:

```text
lambda (x, y) . x
```

Becomes (conceptually):

```text
lambda T++. (gamma (lambda x. (gamma (lambda y. x) (gamma T++ 2))) (gamma T++ 1))
```

- `let` example

Input:

```text
let (= x 5) (+ x 1)
```

Becomes:

```text
gamma (lambda x (+ x 1)) 5
```

## Notes and caveats

- The standardizer rewires sibling pointers when a node is replaced; every transformation returns a node whose `sibling` has been set to the original node's `sibling` so the parent context remains valid.
- The special temporary identifier `T++` is deliberately unique and used only inside the generated lambda for tuple parameter extraction.
- The implementation intentionally keeps `not` and `neg` as operators (not desugared) because `CSEMachine` implements them as native unary operators.

For implementation details, see [src/Standardizer.cpp](src/Standardizer.cpp) and the `createLambda` / `flatten` helpers referenced there.
