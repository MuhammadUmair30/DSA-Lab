#include <iostream>
using namespace std;
class ExprNode
{
public:
    string data;
    ExprNode* left;
    ExprNode* right;

    ExprNode(string value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void printInfix(ExprNode* root)
{
    if (root == NULL)
        return;

    if (root->left != NULL || root->right != NULL)
        cout << "( ";

    printInfix(root->left);

    cout << root->data << " ";

    printInfix(root->right);

    if (root->left != NULL || root->right != NULL)
        cout << ") ";
}

void printPrefix(ExprNode* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    printPrefix(root->left);
    printPrefix(root->right);
}

void printPostfix(ExprNode* root)
{
    if (root == NULL)
        return;

    printPostfix(root->left);
    printPostfix(root->right);

    cout << root->data << " ";
}

int evaluate(ExprNode* root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root->data[0] - '0';
    }

    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    if (root->data == "+")
        return leftValue + rightValue;

    if (root->data == "-")
        return leftValue - rightValue;

    if (root->data == "*")
        return leftValue * rightValue;

    return 0;
}

int main()
{
    ExprNode* n3 = new ExprNode("3");
    ExprNode* n5 = new ExprNode("5");
    ExprNode* n8 = new ExprNode("8");
    ExprNode* n2 = new ExprNode("2");

    ExprNode* plus = new ExprNode("+");
    ExprNode* minus = new ExprNode("-");
    ExprNode* multiply = new ExprNode("*");

    plus->left = n3;
    plus->right = n5;

    minus->left = n8;
    minus->right = n2;

    multiply->left = plus;
    multiply->right = minus;

    cout << "Infix Expression: ";
    printInfix(multiply);

    cout << endl;

    cout << "Prefix Expression: ";
    printPrefix(multiply);

    cout << endl;

    cout << "Postfix Expression: ";
    printPostfix(multiply);

    cout << endl << endl;

    cout << "Evaluation:" << endl;
    cout << "3 + 5 = 8" << endl;
    cout << "8 - 2 = 6" << endl;
    cout << "8 * 6 = 48" << endl;

    cout << "Final Answer: " << evaluate(multiply);

    return 0;
}

//This program creates an expression tree for the expression :
//(3 + 5)* (8 - 2)
//The operators(+, -, *) are stored in internal nodes, while the numbers(3, 5, 8, 2) are stored in leaf nodes.
//The program prints :
//Infix expression using inorder traversal
//Prefix expression using preorder traversal
//Postfix expression using postorder traversal
//The evaluate() function calculates the answer recursively.Instead of using stoi(), the program converts a 
//character digit into an integer using:
//root->data[0] - '0'
//For example :
//'5' - '0' = 5

