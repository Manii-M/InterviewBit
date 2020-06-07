/**
 * Question - GENERAL

This is a timed test. Please keep a track of the time remaining on the top of the page
If you feel the question is unclear, feel free to try out different inputs and check the expected output for them
HINTS ACCESS

Each question has a list of hints to help you incase you are stuck. Do note that all of the hints will have score deductions associated with it. The score deduction for a hint is mentioned on the problem page in the hints section.
Hypothetically, if a problem is worth 50 points, and if you see a hint with 50% deduction; the final score you get will be 25 post solving the problem successfully.

CODE IMPLEMENTATION

You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a doubt? Checkout Sample Codes for more details.
PLAGIARISM

Your code submission will be checked for plagiarism post test completion. If the code is found to be similar to another, such an incident will be communicated to the company contact ( recruiter / hiring manager ).
To prevent plagiarism, we advice not to switch tabs or windows during the test. Any such activity will be recorded and will be available for the company contact to see.

Help Requests Raised: 0 / Resolved: 0
ALL QUESTIONS
S1 
 Q1
 Q2
 Q4
 Q3

Get Response in
30 mins
Raise Help Request when stuck and get help within 30 mins
  Ask for Help (TA)
Bookmark

bookmark-empty
Longest Common Prefix
Problem Description

Given the array of strings A, you need to find the longest string S which is the prefix of ALL the strings in the array.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

For Example: longest common prefix of "abcdefgh" and "abcefgh" is "abc".



Problem Constraints
0 <= sum of length of all strings <= 1000000



Input Format
The only argument given is an array of strings A.



Output Format
Return the longest common prefix of all strings in A.



Example Input
Input 1:

A = ["abcdefgh", "aefghijk", "abcefgh"]
Input 2:

A = ["abab", "ab", "abcd"];


Example Output
Output 1:

"a"
Output 2:

"ab"


Example Explanation
Explanation 1:

Longest common prefix of all the strings is "a".
Explanation 2:

Longest common prefix of all the strings is "ab".
 /*
 * Approach - go through each string and check charcter is matching or not and count the max matched charcters 
 * TC - (n*m)
*/
public
class Solution
{
public
    String longestCommonPrefix(ArrayList<String> A)
    {

        int matched = 0, flag = 1;
        String max_prefix = "";
        if (A.size() == 0)
            return "";
        if (A.size() == 1)
            return A.get(0);
        while (flag == 1)
        {
            for (int i = 0; i < A.size() - 1; i++)
            {

                if (matched < A.get(i).length() && matched < A.get(i + 1).length() && A.get(i).charAt(matched) == A.get(i + 1).charAt(matched))
                    flag = 1;

                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                matched++;
            else
                break;
        }
        return A.get(0).substring(0, matched);
    }
}
