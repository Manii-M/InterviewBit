/**
 * Longest Balanced Substring
Problem Description

Given a string A made up of multiple brackets of type "[]" , "()" and "{}" find the length of the longest substring which forms a balanced string .

Conditions for a string to be balanced :

Blank string is balanced ( However blank string will not be provided as a test case ).
If B is balanced : (B) , [B] and {B} are also balanced.
If B1 and B2 are balanced then B1B2 i.e the string formed by concatenating B1 and B2 is also balanced.


Problem Constraints
0 <= |A| <= 106



Input Format
First and only argument is an string A.



Output Format
Return an single integer denoting the lenght of the longest balanced substring.



Example Input
Input 1:

 A = "[()]"
Input 2:

 A = "[(])"


Example Output
Output 1:

 4
Output 2:

 0


Example Explanation
Explanation 1:

 Substring [1:4] i.e "[()]" is the longest balanced substring of length 4.
Explanation 2:

 None of the substring is balanced so answer is 0.
*/
int Solution::LBSlength(const string A)
{
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;
    int n = A.length();
    int left[n];
    for (int i = 0; i < n; i++)
    {
        left[i] = -1;
        if (A[i] == '(')
            s1.push(i);
        else if (A[i] == '[')
            s2.push(i);
        else if (A[i] == '{')
            s3.push(i);
        else if (A[i] == ')')
        {
            if (!s1.empty())
            {
                left[i] = s1.top();
                s1.pop();
            }
        }
        else if (A[i] == ']')
        {
            if (!s2.empty())
            {
                left[i] = s2.top();
                s2.pop();
            }
        }
        else if (A[i] == '}')
        {
            if (!s3.empty())
            {
                left[i] = s3.top();
                s3.pop();
            }
        }
    }
    int dp[n], answer = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 0;
        if (left[i] != -1)
        {
            if (i - left[i] == 1)
            {
                if (i - 2 >= 0)
                    dp[i] = dp[i - 2] + 2;
                else
                    dp[i] = 2;
            }
            else if (dp[i - 1] == i - left[i] - 1)
                dp[i] = dp[i - 1] + dp[left[i] > 0 ? left[i] - 1 : 0] + 2;
        }
        if (dp[i] > answer)
            answer = dp[i];
    }

    return answer;
}
