/*
 *
 * Question - Longest Substring Without Repeat
Problem Description
Given a string A, find the length of the longest substring without repeating characters.


Problem Constraints
1 <= size(A) <= 106 String consists of lowerCase,upperCase characters and digits are also present in the string A.    


Input Format
Single Argument representing string A.


Output Format
Return an integer denoting the maximum possible length of substring without repeating characters.


Example Input
Input 1:
 A = "abcabcbb"
Input 2:
 A = "AaaA"


Example Output
Output 1:
 3
Output 2:
 2


Example Explanation
Explanation 1:
 Substring "abc" is the longest substring without repeating characters in string A.
Explanation 2:
 Substring "Aa" or "aA" is the longest substring without repeating characters in string A.
 /*
 * Approach - we will be validating the subarray until we find the duplicate character by using hashing
 * TC - in worste case it will be O(n^2) 
 * SC - O(n)
 */

public
class Solution
{
public
    int lengthOfLongestSubstring(String A)
    {
        int maxLen = 0;

        for (int i = 0; i < A.length() - 1; i++)
        {
            int j = i;
            HashMap<Character, Integer> map = new HashMap<Character, Integer>();
            while (j + 1 < A.length() && A.charAt(j) != A.charAt(j + 1) && !(map.containsKey(A.charAt(j + 1))))
            {
                map.put(A.charAt(j), 0);
                j++;
            }
            maxLen = Math.max(maxLen, j - i);
        }
        return maxLen + 1;
    }
}
