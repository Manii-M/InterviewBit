/*
 *
 * 
 * 
Question - Longest Consecutive Sequence
Problem Description
Given an unsorted integer array A of size N. Find the length of the longest set of consecutive elements from the array A.     


Problem Constraints
1 <= N <= 106 -106 <= A[i] <= 106     


Input Format
First argument is an integer array A of size N.


Output Format
Return an integer denoting the length of the longest set of consecutive elements from the array A.


Example Input
Input 1:
A = [100, 4, 200, 1, 3, 2]
  Input 2:          
A = [2, 1]
      


Example Output
Output 1:
 4
  Output 2:          
 2
      


Example Explanation
Explanation 1:
 The set of consecutive elements will be [1, 2, 3, 4].
  Explanation 2:          
 The set of consecutive elements will be [1, 2].
 /*
 *
 * Approach here we can sort the array and we can colve easily in O(n ^ log(n)) time
 * we can optimize this question by using hashing where we jjust have to keep checking if the greater number exist or not like a cycle
 * if for an element smaller number exist we can skip that number as we will be counting it when we will visit the smaller number
 * so we can keep track of the max Count and return the answer

 */

public
class Solution
{
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
public
    int longestConsecutive(final List<Integer> A)
    {

        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int ele : A)
            map.put(ele, 1);

        int maxCount = 0;

        for (int i = 0; i < A.size(); i++)
        {
            if (!(map.containsKey(A.get(i) - 1))) //skipping the smaller element as we will count when we will visit smaller
            {
                int count = 1, key = A.get(i);
                while (map.containsKey(key + 1)) // checking if bigger number is existing or not
                {
                    count++;
                    key++;
                }

                maxCount = Math.max(maxCount, count);
            }
        }

        return maxCount;
    }
}
