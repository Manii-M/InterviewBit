/**
 * Question - Anagrams
Problem Description

Given an array A of N strings, return all groups of strings that are anagrams.

Represent a group by a list of integers representing the index(1-based) in the original list. Look at the sample case for clarification.

NOTE: Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp'.



Problem Constraints
1 <= N <= 104

1 <= |A[i]| <= 104

Each string consists only of lowercase characters.

Sum of length of all the strings doesn't exceed 107



Input Format
Single Argument A which is an array of strings.



Output Format
Return a two-dimensional array where each row describes a group.

Note:

Ordering of the result :
You should not change the relative ordering of the strings within the group suppose within a group containing A[i] and A[j], A[i] comes before A[j] if i < j.



Example Input
Input 1:

 A = [cat, dog, god, tca]
Input 2:

 A = [rat, tar, art]


Example Output
Output 1:

 [ [1, 4],
   [2, 3] ]
Output 2:

 [ [1, 2, 3] ]


Example Explanation
Explanation 1:

 "cat" and "tca" are anagrams which correspond to index 1 and 4 and "dog" and "god" are another set of anagrams which correspond to index 2 and 3.
 The indices are 1 based ( the first element has index 1 instead of index 0).
Explanation 2:

 All three strings are anagrams.
 *
 * Approach - for this question think in the way of hashing and get the idea
 */

public
class Solution
{
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
public
    ArrayList<ArrayList<Integer>> anagrams(final List<String> A)
    {
        HashMap<ArrayList<Integer>, ArrayList<Integer>> map = new HashMap<ArrayList<Integer>, ArrayList<Integer>>();

        for (int j = 0; j < A.size(); j++)
        {
            String str = A.get(j);
            ArrayList<Integer> freq = new ArrayList<Integer>(26);
            for (int i = 0; i < 26; i++)
                freq.add(0);

            for (int i = 0; i < str.length(); i++) //taking the frequency of the char in the string
            {
                int char_index = str.charAt(i) - 97;
                freq.set(char_index, freq.get(char_index) + 1);
            }

            if (map.containsKey(freq))
            {
                ArrayList<Integer> value = map.get(freq);
                value.add(j + 1);
                map.put(freq, value);
            }
            else
            {
                ArrayList<Integer> value = new ArrayList<Integer>();
                value.add(j + 1);
                map.put(freq, value);
            }
        }
        return new ArrayList<ArrayList<Integer>>(map.values());
    }
}
