/**
 *  Question - 
 * Find if there is a sub-array with 0 sum
Problem Description
Given an array of integers A, find and return whether the given array contains a non-empty subarray with a sum equal to 0. If the given array contains a sub-array with sum zero return 1 else return 0.   


Problem Constraints
1 <= |A| <= 100000 -10^9 <= A[i] <= 10^9   


Input Format
The only argument given is the integer array A.


Output Format
Return whether the given array contains a subarray with a sum equal to 0.


Example Input
Input 1:
 A = [1, 2, 3, 4, 5]
  Input 2:            
 A = [-1, 1]
       


Example Output
Output 1:
 0
  Output 2:            
 1
       


Example Explanation
Explanation 1:
 No subarray has sum 0.
  Explanation 2:            
 The array has sum 0.
  *
/*
  * Approach - here is to use prefix sum if at any point the prefix sum is repeating then we have one sub array whose sum is repeating
  * and we can aso find the max length of the subaarya which has sum zero keeping the index in hashmap and take max
*/
public
class Solution
{
public
    int solve(ArrayList<Integer> A)
    {
        HashMap<Long, Long> map = new HashMap<Long, Long>();

        int maxLen = 0;

        map.put(0L, -1L);

        long prefixSum = (long)(A.get(0));

        if (prefixSum == 0)
            return 1;
        map.put(prefixSum, 0L);
        for (int i = 1; i < A.size(); i++)
        {
            prefixSum += A.get(i);
            if (map.containsKey(prefixSum))
                return 1;

            map.put(prefixSum, (long)(i));
        }
        return 0;
    }
}
