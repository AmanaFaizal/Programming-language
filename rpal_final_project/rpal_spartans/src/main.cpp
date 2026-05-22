#include "Parser.h"
#include "Standardizer.h"
#include "CSEMachine.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Usage: ./rpal20 [-ast|-st] <filename>\n";
        return 1;
    }

    bool printAST = false;
    bool printStandardized = false;
    
    string filename;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-ast") == 0) {
            printAST = true;
        } else if (strcmp(argv[i], "-st") == 0) {
            printStandardized = true;
        } else {
            filename = argv[i];
        }
    }

    if (filename.empty()) {
        cerr << "Error: No input file specified.\n";
        return 1;
    }
    
    try {
        Parser parser(filename);
        auto ast = parser.parse();
        
        if (printAST) {
            parser.printAST(ast);
            return 0;
        }
        
        Standardizer st;
        auto standardizedTree = st.standardize(ast);
        
        if (printStandardized) {
            parser.printAST(standardizedTree);
        } else {
            CSEMachine machine(standardizedTree);
            machine.evaluate();
        }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
