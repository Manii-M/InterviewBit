/**
 * Question
 * Infix to Postfix
Problem Description

Given string A denoting an infix expression. Convert the infix expression into postfix expression.

String A consists of ^, /, *, +, -, (, ) and lowercase english alphabets where lowercase english alphabets are operands and ^, /, *, +, - are operators.

Find and return the postfix expression of A.

NOTE:

^ has highest precedence.
/ and * have equal precedence but greater than + and -.
+ and - have equal precedence and lowest precedence among given operators.


Problem Constraints
1 <= length of the string <= 500000



Input Format
The only argument given is string A.



Output Format
Return a string denoting the postfix conversion of A.



Example Input
Input 1:

 A = "x^y/(a*z)+b"
Input 2:

 A = "a+b*(c^d-e)^(f+g*h)-i"


Example Output
Output 1:

 xy^az*///b+
 /***
  * /
Output 2:

 "abcd^e-fgh*+^*+i-"


Example Explanation
Explanation 1:

 Ouput dentotes the postfix expression of the given input.
 /*
 * Approach - use the stack to convert it from infix to postfix
 * TC - O(n)
 * SC - O(n)
*/
/*
 * Approach - use the stack to convert it from infix to postfix
 * TC - O(n)
 * SC - O(n)
*/
public
class Solution
{
public
    int precedence(char ch)
    {
        switch (ch)
        {
        case '^':
            return 2;
        case '*':
            return 1;
        case '/':
            return 1;
        default:
            return 0;
        }
    }
public
    String solve(String A)
    {
        StringBuilder postfix = new StringBuilder();
        Stack<Character> s = new Stack<Character>();
        for (int i = 0; i < A.length(); i++)
        {
            if (A.charAt(i) >= 'a' && A.charAt(i) <= 'z')
            {
                postfix.append(A.charAt(i));
            }
            else
            {
                if (A.charAt(i) == '(' || (!s.empty() && s.peek() == '('))
                    s.push(A.charAt(i));
                else if (A.charAt(i) == ')')
                {
                    while (!s.empty() && s.peek() != '(')
                        postfix.append(s.pop());
                    s.pop();
                }
                else
                {
                    while (!s.empty() && s.peek() != '(' && precedence(s.peek()) >= precedence(A.charAt(i)))
                        postfix.append(s.pop());
                    s.push(A.charAt(i));
                }
            }
        }
        while (!s.empty())
            postfix.append(s.pop());
        return postfix.toString();
    }
}
