/**
 * Question - 
 * Boring substring
Problem Description

Given a string A of lowercase English alphabets. Rearrange the characters of the given string A such that there is no boring substring in A.

A boring substring has the following properties:

Its length is 2.
Both the characters are consecutive, for example - "ab", "cd", "dc", "zy" etc.(If the first character is C then the next character can be either (C+1) or (C-1)).
Return 1 if it possible to rearrange the letters of A such that there are no boring substring in A, else return 0.



Problem Constraints
1 <= |A| <= 100



Input Format
The only argument given is string A.



Output Format
Return 1 if it possible to rearrange the letters of A such that there are no boring substring in A, else return 0.



Example Input
Input 1:

 A ="abcd"
Input 2:

 A = "aab"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 String A can be rearranged into "cadb" or "bdac" 
Explanation 2:

 No arrangement of string A can make it free of boring substrings.

Solution Approach -- No specific knowledge is requires to solve this question you just need to observe and find an existing pattern hidden in the parities of ASCII value of characters.

‘a’ must be present near ‘c’ ,similarly ‘c’ must be near ‘e’ as we can see odd characters can be put aside each other and there will be no boring substring in it.

Like: “acegik…” No boring substring present in this string.

Similarly for even characters.

Now just traverse in the string and form two strings one containing the odd characters and other even characters.
Sort both of them and check if placing them together doesn’t make a boring substring at their join point.

For example:
A = “abcdefg”
So ,
odd = “aceg”
even= “bdf”

Check the string s= odd+even or s=even+odd doesn’t contain any boring substring.

Time Complexity : O(	A	)
*/
bool check(string s)
{
    bool ok = true;
    for (int i = 0; i + 1 < s.size(); ++i)
        ok &= (abs(s[i] - s[i + 1]) != 1);
    return ok;
}

int solveit(string s)
{
    string odd = "", even = "";
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] % 2 == 0)
            odd += s[i];
        else
            even += s[i];
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    if (check(odd + even))
        return 1;
    else if (check(even + odd))
        return 1;
    return 0;
}
int Solution::solve(string A)
{
    return solveit(A);
}