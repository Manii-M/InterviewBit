/**
 * Evaluate Expression
Problem Description

An arithmetic expression is given by a charater array A of size N. Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or operator.



Problem Constraints
1 <= N <= 105



Input Format
The only argument given is character array A.



Output Format
Return the value of arithmetic expression formed using reverse Polish Notation.



Example Input
Input 1:
    A =   ["2", "1", "+", "3", "*"]
Input 2:
    A = ["4", "13", "5", "/", "+"]


Example Output
Output 1:
    9
Output 2:
    6


Example Explanation
Explaination 1:
    starting from backside:
    * : () * ()
    3 : () * (3)
    + : (() + ()) * (3)
    1 : (() + (1)) * (3)
    2 : ((2) + (1)) * (3)
    ((2) + (1)) * (3) = 9
Explaination 2:
    + : () + ()
    / : () + (() / ())
    5 : () + (() / (5))
    1 : () + ((13) / (5))
    4 : (4) + ((13) / (5))
    (4) + ((13) / (5)) = 6
/*Approach - use stack and solve when we have any operator take out two operands from top of the stack and put it back again in the stack
TC - O(n)
*/
public
class Solution
{
public
    int operator(String c)
    {
        switch (c)
        {
        case "+":
            return 0;
        case "-":
            return 1;
        case "*":
            return 2;
        case "/":
            return 3;
        default:
            return -1;
        }
    }
public
    int evalRPN(ArrayList<String> A)
    {
        Stack<Integer> s = new Stack<Integer>();

        for (int i = 0; i < A.size(); i++)
        {
            if (A.get(i).equals("+") || A.get(i).equals("-") || A.get(i).equals("*") || A.get(i).equals("/"))
            {
                int opertr = operator(A.get(i));
                int b = s.pop();
                int a = s.pop();
                if (opertr == 0)
                    s.push(a + b);
                else if (opertr == 1)
                    s.push(a - b);
                else if (opertr == 2)
                    s.push(a * b);
                else if (opertr == 3)
                    s.push(a / b);
            }
            else
                s.push(Integer.parseInt(String.valueOf(A.get(i))));
        }
        return s.peek();
    }
}
