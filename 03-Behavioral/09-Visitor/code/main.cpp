#include<iostream>
#include<vector>

using namespace std;


/*
============================================================
VISITOR DESIGN PATTERN
============================================================

REAL WORLD USE CASE:
--------------------

Compiler Abstract Syntax Tree (AST)

AST Nodes:
-----------
1. NumberLiteral
2. VariableNode
3. BinaryExpression
4. FunctionCall

Operations Needed:
------------------
1. Pretty Printing
2. Code Generation
3. Semantic Analysis
4. Optimization
5. Type Checking

PROBLEM:
--------
Without Visitor Pattern:

Every AST node class would contain:
- print()
- generateCode()
- optimize()
- analyze()
- checkTypes()

Huge violation of:
- Single Responsibility Principle
- Open Closed Principle

SOLUTION:
---------
Move operations into separate visitor classes.

============================================================
*/




/*
============================================================
FORWARD DECLARATIONS
============================================================
*/

class NumberLiteral;
class VariableNode;
class BinaryExpression;
class FunctionCall;




/*
============================================================
VISITOR INTERFACE
============================================================
*/

class ASTVisitor {

public:

    virtual void visit(
        NumberLiteral* node
    ) = 0;

    virtual void visit(
        VariableNode* node
    ) = 0;

    virtual void visit(
        BinaryExpression* node
    ) = 0;

    virtual void visit(
        FunctionCall* node
    ) = 0;

    virtual ~ASTVisitor() {}
};




/*
============================================================
AST NODE INTERFACE
============================================================
*/

class ASTNode {

public:

    virtual void accept(
        ASTVisitor* visitor
    ) = 0;

    virtual ~ASTNode() {}
};




/*
============================================================
CONCRETE AST NODES
============================================================
*/

class NumberLiteral
    : public ASTNode {

public:

    int value;

    NumberLiteral(
        int value
    )
        : value(value)
    {}

    void accept(
        ASTVisitor* visitor
    ) override {

        visitor->visit(this);
    }
};




class VariableNode
    : public ASTNode {

public:

    string variableName;

    VariableNode(
        const string& variableName
    )
        : variableName(variableName)
    {}

    void accept(
        ASTVisitor* visitor
    ) override {

        visitor->visit(this);
    }
};




class BinaryExpression
    : public ASTNode {

public:

    ASTNode* left;

    ASTNode* right;

    string op;

    BinaryExpression(
        ASTNode* left,
        ASTNode* right,
        const string& op
    )
        :
        left(left),
        right(right),
        op(op)
    {}

    void accept(
        ASTVisitor* visitor
    ) override {

        visitor->visit(this);
    }
};




class FunctionCall
    : public ASTNode {

public:

    string functionName;

    vector<ASTNode*> arguments;

    FunctionCall(
        const string& functionName
    )
        : functionName(functionName)
    {}

    void addArgument(
        ASTNode* arg
    ) {

        arguments.push_back(arg);
    }

    void accept(
        ASTVisitor* visitor
    ) override {

        visitor->visit(this);
    }
};




/*
============================================================
PRETTY PRINT VISITOR
============================================================
*/

class PrettyPrintVisitor
    : public ASTVisitor {

public:

    void visit(
        NumberLiteral* node
    ) override {

        cout
            << node->value;
    }



    void visit(
        VariableNode* node
    ) override {

        cout
            << node->variableName;
    }



    void visit(
        BinaryExpression* node
    ) override {

        cout << "(";

        node->left->accept(this);

        cout
            << " "
            << node->op
            << " ";

        node->right->accept(this);

        cout << ")";
    }



    void visit(
        FunctionCall* node
    ) override {

        cout
            << node->functionName
            << "(";

        for(int i = 0;
            i < node->arguments.size();
            i++) {

            node->arguments[i]
                ->accept(this);

            if(i != node->arguments.size() - 1) {

                cout << ", ";
            }
        }

        cout << ")";
    }
};




/*
============================================================
CODE GENERATION VISITOR
============================================================
*/

class CodeGenerationVisitor
    : public ASTVisitor {

public:

    void visit(
        NumberLiteral* node
    ) override {

        cout
            << "PUSH "
            << node->value
            << endl;
    }



    void visit(
        VariableNode* node
    ) override {

        cout
            << "LOAD "
            << node->variableName
            << endl;
    }



    void visit(
        BinaryExpression* node
    ) override {

        node->left->accept(this);

        node->right->accept(this);

        cout
            << "EXECUTE "
            << node->op
            << endl;
    }



    void visit(
        FunctionCall* node
    ) override {

        for(auto arg : node->arguments) {

            arg->accept(this);
        }

        cout
            << "CALL "
            << node->functionName
            << endl;
    }
};




/*
============================================================
SEMANTIC ANALYSIS VISITOR
============================================================
*/

class SemanticAnalysisVisitor
    : public ASTVisitor {

public:

    void visit(
        NumberLiteral* node
    ) override {

        cout
            << "[Semantic] Number is valid"
            << endl;
    }



    void visit(
        VariableNode* node
    ) override {

        cout
            << "[Semantic] Checking variable: "
            << node->variableName
            << endl;
    }



    void visit(
        BinaryExpression* node
    ) override {

        cout
            << "[Semantic] Validating binary expression"
            << endl;

        node->left->accept(this);

        node->right->accept(this);
    }



    void visit(
        FunctionCall* node
    ) override {

        cout
            << "[Semantic] Checking function call: "
            << node->functionName
            << endl;

        for(auto arg : node->arguments) {

            arg->accept(this);
        }
    }
};




/*
============================================================
TYPE CHECK VISITOR
============================================================
*/

class TypeCheckVisitor
    : public ASTVisitor {

public:

    void visit(
        NumberLiteral* node
    ) override {

        cout
            << "[TypeCheck] int"
            << endl;
    }



    void visit(
        VariableNode* node
    ) override {

        cout
            << "[TypeCheck] variable type resolved"
            << endl;
    }



    void visit(
        BinaryExpression* node
    ) override {

        cout
            << "[TypeCheck] checking operator compatibility"
            << endl;

        node->left->accept(this);

        node->right->accept(this);
    }



    void visit(
        FunctionCall* node
    ) override {

        cout
            << "[TypeCheck] validating function arguments"
            << endl;

        for(auto arg : node->arguments) {

            arg->accept(this);
        }
    }
};




/*
============================================================
OPTIMIZATION VISITOR
============================================================
*/

class OptimizationVisitor
    : public ASTVisitor {

public:

    void visit(
        NumberLiteral* node
    ) override {

        cout
            << "[Optimizer] Constant detected"
            << endl;
    }



    void visit(
        VariableNode* node
    ) override {

        cout
            << "[Optimizer] Variable optimization"
            << endl;
    }



    void visit(
        BinaryExpression* node
    ) override {

        cout
            << "[Optimizer] Optimizing binary expression"
            << endl;

        node->left->accept(this);

        node->right->accept(this);
    }



    void visit(
        FunctionCall* node
    ) override {

        cout
            << "[Optimizer] Optimizing function call"
            << endl;

        for(auto arg : node->arguments) {

            arg->accept(this);
        }
    }
};




/*
============================================================
CLIENT
============================================================
*/

int main() {


    /*
    ========================================================
    AST CREATION

    print(5 + x)

    ========================================================
    */

    ASTNode* number =
        new NumberLiteral(5);

    ASTNode* variable =
        new VariableNode("x");

    ASTNode* expression =
        new BinaryExpression(
            number,
            variable,
            "+"
        );

    FunctionCall* function =
        new FunctionCall("print");

    function->addArgument(expression);




    /*
    ========================================================
    PRETTY PRINT
    ========================================================
    */

    cout
        << "=========== PRETTY PRINT ==========="
        << endl;

    PrettyPrintVisitor prettyPrinter;

    function->accept(
        &prettyPrinter
    );

    cout << endl << endl;




    /*
    ========================================================
    CODE GENERATION
    ========================================================
    */

    cout
        << "=========== CODE GENERATION ========="
        << endl;

    CodeGenerationVisitor codeGen;

    function->accept(
        &codeGen
    );

    cout << endl;




    /*
    ========================================================
    SEMANTIC ANALYSIS
    ========================================================
    */

    cout
        << "=========== SEMANTIC ANALYSIS ======="
        << endl;

    SemanticAnalysisVisitor semantic;

    function->accept(
        &semantic
    );

    cout << endl;




    /*
    ========================================================
    TYPE CHECKING
    ========================================================
    */

    cout
        << "=========== TYPE CHECKING ==========="
        << endl;

    TypeCheckVisitor typeChecker;

    function->accept(
        &typeChecker
    );

    cout << endl;




    /*
    ========================================================
    OPTIMIZATION
    ========================================================
    */

    cout
        << "=========== OPTIMIZATION ============"
        << endl;

    OptimizationVisitor optimizer;

    function->accept(
        &optimizer
    );



    return 0;
}