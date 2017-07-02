#include <stack>
#include <sstream>
#include <string>
#include <vector>

#include "ExpressionTree.h"


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ExpressionTree::ExpressionTree(const string& infix)
  : tree(nullptr) // root to null
{
  cout << "Converting from infix   '" << infix << "' to postfix notation\n";
  string postfix = convertInfixToPostfix(infix);  // convert to postfix
  cout << "Converting from postfix '" << postfix << "' to expression tree\n";
  buildTreeFromPostfix(postfix);  // use converted postfix to make tree
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ExpressionTree::~ExpressionTree()
{
  clear(tree);//clear the tree
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool ExpressionTree::isOperator(const string& s) const
{
  return s == "+" || s == "-" || s == "*" || s == "/" || s == "(" || s == ")"; // see if s is one of the valid operators
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int ExpressionTree::opPrecedence(const string& op1, const string& op2) const
{
  //check operator precedence
  int op1Int = (op1 == "/" || op1 == "*") ? 1 : 0;
  int op2Int = (op2 == "/" || op2 == "*") ? 1 : 0;

  return op1Int - op2Int;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Be thankful that I didn't ask for this method in the assignment!
string ExpressionTree::convertInfixToPostfix(const string& infix) const
{
  stack<string> stack; //declare a STL string Stack
  vector<string> result;  //declare a STL string vector

  istringstream in(infix);
  //for each operator or operand
  for(string s; in >> s; )
  {
    if(!isOperator(s))//if operand
      result.push_back(s);  // push to stack
    else if(stack.empty() || stack.top() == "(") //if stack empty if stack top is open bracket ie next var is operand
      stack.push(s);  // push onto stack
    else if(s == "(") // if open bracket
      stack.push(s);  //push to stack
    else if(s == ")") //if close bracket
    {
      //while not open bracket push onto vector
      while(stack.top() != "(")
      {
        result.push_back(stack.top());
        stack.pop();
      }
      stack.pop();// pop off open bracket
    }
    else  // look at precedence of operators
    {
      //find precedence of ops and order properly into vector
      int precedence = opPrecedence(s, stack.top());
      if(precedence > 0)
        stack.push(s);
      else
      {
        result.push_back(stack.top());
        stack.pop();
        stack.push(s);
      }
    }
  }
  while(!stack.empty())
  {
    result.push_back(stack.top());
    stack.pop();
  }

  // Generate postfix form
  string postfix;
  for(const auto& s: result)
    postfix += s + " ";

  return postfix;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Create an expression tree from a postfix expression
// pre-condition:   a valid postfix expression (each part separated by space)
// post-condition:  'tree' points to a valid expression tree
void ExpressionTree::buildTreeFromPostfix(const string& postfix)
{
  /* Algorithm
      create a stack containing ExprNode pointers
      for each string 's' in the postfix expression
        create a new ExprNode containing 's'
        if 's' is an operand
          push the new node to the stack
        else if 's' is an operator
          pop two values from stack, make them children of the new node,
          and and push the node to the stack
        end if
      end for

      at the end, the stack contains one item; the expression tree
   */

  // FIXME - add your implementation of the algorithm here
  //         at the end, instance variable 'tree' must point to the
  //         expression tree you've created

  stack<ExprNode*> stack; // declare stack
  istringstream str(postfix); // define new istringstream
  string s; // string s to hold operator or operand
  while(getline(str, s, ' ')){  //while not at end of line
    //if not operator
    if(!isOperator(s)){
      ExprNode* Node = new ExprNode(s); // new node to push on stack
      stack.push(Node);// push new node to stack
    }else if(isOperator(s)){//if operator
      ExprNode* Node = new ExprNode(s); //new node for operator
       //make children the last 2 things on stack
      Node->left = stack.top();
      stack.pop();
      Node->right = stack.top();
      stack.pop();
      //set tree root to node
      tree = Node;
      stack.push(Node);  //push tree to the stack
    }
  }

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Traverse the expression tree and generate the result
// pre-condition:   an expression tree already exists
//                  (ie, buildTreeFromPostfix() has already been called)
// post-condition:  the expression tree is traversed, and the final
//                  output calculated (the tree is not modified)
double ExpressionTree::evaluate(const ExprNode* root) const
{
  /* Algorithm
      if root is nullptr then return 0.0
      else perform a postorder traversal on the root

      if data at root is an operator
        let right operand be the evaluation of the left child of root
        let left operand be the evaluation of the right child of root
        return the result of combining the left and right children using that operator
      else
        return the data at root converted to a double (hint: use stod)
      end if
   */

  // FIXME - add your implementation of the algorithm here
  //         at the end, the final return value is the overall result

  if(root == nullptr)// if root null return 0
    return 0.0;
  else{//else go through the tree
    if(isOperator(root->data)){//ifoperator
      double right = evaluate(root->left);// recursive evaluate forthe left branch
      double left = evaluate(root->right);// recursive evaluate forthe right branch
      string op = root->data; // operator
      double result = 0.0;  // initialize the result
      //select operation and preform said operation on the right and left values
      if(op == "+")
          result = left + right;
      else if(op == "-")
          result = left - right;
      else if(op == "*")
          result = left * right;
      else if(op == "/")
          result = left / right;
      return result;//return result
    }else{ // if not operator
      return stod(root->data); // return double converted data
    }
  }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Utility function to clear memory
void ExpressionTree::clear(ExprNode* root)
{
  // FIXME - add your implementation of the algorithm here
  //         what type of traversal would be needed to delete nodes?? A: postorder
  //if not nullptr
  if(root != nullptr){
    clear(root->left);  // recursive call to clear through left
    clear(root->right); // recursive call to clear through right
    delete root;  //deallocate root
    root = nullptr; // set to null ptr
  }


}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int main(int ac, char* av[])
{
  ExpressionTree expr1("2 / ( 3 + 7 )"); // create tree
  cout << "Final evaluation: " << expr1.evaluate() << endl; // eval

  cout << endl;

  ExpressionTree expr2("2 / ( 3 - 7 ) * 5");// create tree
  cout << "Final evaluation: " << expr2.evaluate() << endl;// eval 
}
