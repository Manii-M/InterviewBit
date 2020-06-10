/**
 * Check two bracket expressions
Problem Description

Given two strings A and B. Each string represents an expression consisting of lowercase english alphabets, '+', '-', '(' and ')'.

The task is to compare them and check if they are similar. If they are similar return 1 else return 0.

NOTE: It may be assumed that there are at most 26 operands from ‘a’ to ‘z’ and every operand appears only once.



Problem Constraints
1 <= length of the each String <= 100



Input Format
The arguments given are string A and String B.



Output Format
Return 1 if they represent the same expression else return 0.



Example Input
Input 1:

 A = "-(a+b+c)"
 B = "-a-b-c"
Input 2:

 A = "a-b-(c-d)"
 B = "a-b-c-d"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 The expression "-(a+b+c)" can be written as "-a-b-c" which is equal as B. 
Explanation 2:

 Both the expression are different.
/*pproach - we will use stack to and we will see before every opening '(' is there any sign and keep updating the sign variable
and when we see ')' we will remove the opening '(' and again update the sign variable bases on the sign just before the '('.
 *
 * TC - O(n)
 * SC - O(n)
*/
/*pproach - we will use stack to and we will see before every opening '(' is there any sign and keep updating the sign variable
and when we see ')' we will remove the opening '(' and again update the sign variable bases on the sign just before the '('.
 *
 * TC - O(n)
 * SC - O(n)
*/
public
class Solution
{
public
    ArrayList<Integer> solveExpression(String A)
    {
        int sign = 1;
        int[] signs = new int[26];
        Stack<Integer> s = new Stack<Integer>();
        ArrayList<Integer> a_signs = new ArrayList<Integer>();
        for (int i = 0; i < 26; i++)
            a_signs.add(1);
        for (int i = 0; i < A.length(); i++)
        {
            if (A.charAt(i) == '(')
            {
                s.push(i);
                if (i > 0 && A.charAt(i - 1) == '-') //checking any sign just before the '('
                    sign *= -1;
            }
            else if (A.charAt(i) == ')') //removing the open '(' and updating the sign
            {
                while (!s.empty() && A.charAt(s.peek()) != '(')
                    s.pop();

                if (!s.empty() && s.peek() > 0 && A.charAt(s.peek() - 1) == '-')
                    sign *= -1;

                if (!s.empty())
                    s.pop();
            }
            else if (A.charAt(i) >= 'a' && A.charAt(i) <= 'z')
            {
                int ch_sign = 1;
                if (i > 0 && A.charAt(i - 1) == '-')
                    ch_sign = -1;
                signs[A.charAt(i) - 97] = sign * ch_sign;
            }
        }

        for (int i = 0; i < A.length(); i++)
        {
            if (A.charAt(i) >= 'a' && A.charAt(i) <= 'z')
                a_signs.set(A.charAt(i) - 97, signs[A.charAt(i) - 97]);
        }
        return a_signs;
    }
public
    int solve(String A, String B)
    {
        ArrayList<Integer> a_signs = solveExpression(A);
        ArrayList<Integer> b_signs = solveExpression(B);
        for (int i = 0; i < 26; i++)
            if (a_signs.get(i) != b_signs.get(i))
                return 0;
        return 1;
    }
}
