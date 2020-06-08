/**
 * Redundant Braces
Problem Description

Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'.

Chech whether A has redundant braces or not.

NOTE: A will be always a valid expression.



Problem Constraints
1 <= |A| <= 1000



Input Format
The only argument given is string A.



Output Format
Return 1 if A has redundant braces, else return 0.



Example Input
Input 1:

 A = "((a+b))"
Input 2:

 A = "(a+(a+b))"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 ((a+b)) has redundant braces so answer will be 1.
Explanation 2:

 (a+(a+b)) doesn't have have any redundant braces so answer will be 0.
 /*
 * Approach - a paranthesis is valid if there a arithematic opeartor is there in between  else it is redundant
 * TC - O(n)
*/
public
class Solution
{
public
    int braces(String A)
    {
        Stack<Character> s = new Stack<Character>();
        for (int i = 0; i < A.length(); i++)
        {
            int flag = 0;
            if (A.charAt(i) == ')')
            {
                if (!s.empty() && s.peek() == '(')
                    return 1;
                while (!s.empty() && s.peek() != '(')
                {
                    if (s.peek() == '+' || s.peek() == '-' || s.peek() == '*' || s.peek() == '/')
                        flag = 1;
                    s.pop();
                }
                s.pop();
                if (flag == 0)
                    return 1;
            }
            else
                s.push(A.charAt(i));
        }

        return 0;
    }
}
