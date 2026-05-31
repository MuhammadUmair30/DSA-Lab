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

// Manual stack
class Stack
{
public:
    ExprNode* arr[100];
    int top;

    Stack()
    {
        top = -1;
    }

    void push(ExprNode* node)
    {
        arr[++top] = node;
    }

    ExprNode* pop()
    {
        return arr[top--];
    }

    ExprNode* peek()
    {
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

// Inorder (Infix)
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

// Preorder (Prefix)
void printPrefix(ExprNode* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    printPrefix(root->left);
    printPrefix(root->right);
}

// Postorder (Postfix)
void printPostfix(ExprNode* root)
{
    if (root == NULL)
        return;

    printPostfix(root->left);
    printPostfix(root->right);
    cout << root->data << " ";
}

// Evaluation
int evaluate(ExprNode* root)
{
    if (root->left == NULL && root->right == NULL)
        return root->data[0] - '0';

    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    if (root->data == "+") return leftVal + rightVal;
    if (root->data == "-") return leftVal - rightVal;
    if (root->data == "*") return leftVal * rightVal;

    return 0;
}

int main()
{
    string postfix[] = { "3", "5", "+", "8", "2", "-", "*" };
    int n = 7;

    Stack st;

    for (int i = 0; i < n; i++)
    {
        string symbol = postfix[i];

        if (symbol != "+" && symbol != "-" && symbol != "*")
        {
            st.push(new ExprNode(symbol));
        }
        else
        {
            ExprNode* op = new ExprNode(symbol);

            ExprNode* right = st.pop();
            ExprNode* left = st.pop();

            op->left = left;
            op->right = right;

            st.push(op);
        }
    }

    ExprNode* root = st.peek();

    cout << "Infix Expression: ";
    printInfix(root);
    cout << endl;

    cout << "Prefix Expression: ";
    printPrefix(root);
    cout << endl;

    cout << "Postfix Expression: ";
    printPostfix(root);
    cout << endl;

    cout << "\nFinal Answer: " << evaluate(root);

    return 0;
}

//This program builds and evaluates an expression tree from a given postfix expression using a manually
//implemented stack.The expression used is 3 5 + 8 2 - *, which represents the infix expression(3 + 5)* (8 - 2).
//First, a class ExprNode is created to represent each node of the tree.Each node stores a value(operand or 
//operator) and has two pointers, left and right, to connect child nodes.Since the program avoids using the built
//- in stack library, a custom Stack class is implemented using an array, where nodes are pushed, popped, and 
//accessed from the top index.
//The main logic scans the postfix expression from left to right.If the current symbol is an operand(like 3, 5, 8,
//2), it is turned into a node and pushed onto the stack.If the symbol is an operator, two nodes are popped from 
//the stack : the first popped becomes the right child and the second becomes the left child.A new operator node 
//is then created, connected with these two children, and pushed back onto the stack.After processing the entire 
//expression, the remaining node in the stack becomes the root of the expression tree.
//Once the tree is constructed, different recursive traversal functions are used to display the expression in 
//various forms.Inorder traversal prints the infix expression with brackets, preorder traversal prints the prefix 
//form, and postorder traversal prints the postfix form.Finally, the evaluate function recursively computes the 
//result of the expression tree by solving left and right subtrees and applying the operator at each node.The 
//final result of the expression(3 + 5)* (8 - 2) is calculated step by step and produces the output 48.