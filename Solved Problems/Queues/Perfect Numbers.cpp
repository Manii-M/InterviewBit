/**
 * Perfect Numbers
Problem Description

Given an integer A, you have to find the Ath Perfect Number.

A Perfect Number has the following properties:

It comprises only 1 and 2.

The number of digits in a Perfect number is even.

It is a palindrome number.

For example 11, 22, 112211 are Perfect numbers, where 123, 121, 782, 1 are not.



Problem Constraints
1 <= A <= 100000



Input Format
The only argument given is an integer A.



Output Format
Return a string that denotes the Ath Perfect Number.



Example Input
Input 1:

 A = 2
Input 2:

 A = 3


Example Output
Output 1:

 22
Output 2:

 1111


Example Explanation
Explanation 1:

First four perfect numbers are:
1. 11
2. 22
3. 1111
4. 1221
Explanation 2:

First four perfect numbers are:
1. 11
2. 22
3. 1111
4. 1221
 /*
  *
  * Approach - use queue to generate all the possible numbers but there is and observation 
  * You can optimize the code further by making the following observation:

Generate strings using the queue, the next perfect number will be:

str + reverse(str)

For example, if the 's' that you obtain from the front of the queue is "122" then the corresponding perfect number is "122221".

In this way, the memory utilized will be reduced greatly since you will only need to generate strings with length upto half of what you were previously generating.
*/

string Solution::solve(int A)
{
    queue<string> q;
    q.push("1");
    q.push("2");
    int count = 0;
    while (count < A)
    {
        for (char i = '1'; i <= '2'; i++)
        {
            string s = q.front();
            s.push_back(i);
            q.push(s);
        }
        count++;
        if (count == A)
        {
            string str = q.front();
            string s = str;
            reverse(str.begin(), str.end());
            return s + str;
        }
        q.pop();
    }
    return "";
}
