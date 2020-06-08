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
 *
 * Approach - use stack to identify the signs before '(' and before each charcter
 * TC- O(n)
*/
public
class Solution
{
public
    String kato(String A)
    {
        int sign = 1;
        int[] signs = new int[26];
        Stack<Integer> s = new Stack<Integer>();
        for (int i = 0; i < A.length(); i++)
        {
            if (A.charAt(i) == '(')
            {
                s.push(i);
                if (i > 0 && A.charAt(i - 1) == '-')
                    sign *= -1;
            }
            else if (A.charAt(i) == ')')
            {
                while (!s.empty() && s.peek() != '(')
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
        String answer = "";
        for (int i = 0; i < A.length(); i++)
        {
            if (A.charAt(i) >= 97 && A.charAt(i) <= 123)
            {

                if (signs[A.charAt(i) - 97] == -1)
                    answer = answer + "-" + A.charAt(i);
                else if (answer.length() > 0)
                    answer += "+" + A.charAt(i);
                else
                    answer += A.charAt(i);
            }
        }
        return answer;
    }
public
    int solve(String A, String B)
    {

        String a = kato(A);
        String b = kato(B);
        // System.out.println(a);
        // System.out.println(b);
        return a.equals(b) ? 1 : 0;
        // return 0;
    }
}
