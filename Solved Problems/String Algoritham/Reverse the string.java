/**
 * Question - Reverse the String
Problem Description

Given a string A of size N.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.


Problem Constraints
1 <= N <= 105



Input Format
The only argument given is string A.



Output Format
Return the string A after reversing the string word by word.



Example Input
Input 1:
    A = "the sky is blue"
Input 2:
    A = "this is ib"  


Example Output
Output 1:
    "blue is sky the"
Output 2:
    "ib is this"    


Example Explanation
Explanation 1:
    We reverse the string word by word so the string becomes "the sky is blue".
Explanation 2:
    We reverse the string word by word so the string becomes "this is ib".
 /*
 * Approach - Reverse the string
*/
public
class Solution
{
public
    String solve(String A)
    {
        ArrayList<String> words = new ArrayList<String>();
        for (int i = 0; i < A.length(); i++)
        {
            int start = i;
            while (i < A.length() && A.charAt(i) != ' ')
                i++;

            if (start < i)
                words.add(A.substring(start, i));
        }
        String answer = "";
        for (int i = words.size() - 1; i >= 0; i--)
        {
            answer = answer + words.get(i);
            if (i != 0)
                answer += " ";
        }
        return answer;
    }
}
