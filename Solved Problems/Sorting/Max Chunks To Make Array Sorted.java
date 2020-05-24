/**
 * Max Chunks To Make Sorted
Problem Description
Given an array of integers A of size N that is a permutation of [0, 1, 2, ..., (N-1)], if we split the array into some number of "chunks" (partitions), and individually sort each chunk. After concatenating them, the result equals the sorted array. What is the most number of chunks we could have made?  


Problem Constraints
1 <= N <= 100000
0 <= A[i] < N


Input Format
The only argument given is the integer array A.


Output Format
Return the maximum number of chunks that we could have made.


Example Input
Input 1:
 A = [1, 2, 3, 4, 0]
Input 2:
 A = [2, 0, 1, 3]
 


Example Output
Output 1:
 1
Output 2:
 2
 


Example Explanation
Explanation 1:
 A = [1, 2, 3, 4, 0]
 To get the 0 in the first index, we have to take all elements in a single chunk.
Explanation 2:
 A = [2, 0, 1, 3] 
 We can divide the array into 2 chunks.
 First chunk is [2, 0, 1] and second chunk is [3].
 /**
  * Approach -  to get the maximum chunks some observation is in each subarray all elements should be there from [i, j]
  */
 
public
class Solution
{

public
    int solve(ArrayList<Integer> A)
    {

        int i = 0, j = 0, count = 0, mini = 0, maxi = 0;
        while (i < A.size() && j < A.size() && i <= j)
        {
            mini = Math.min(A.get(j), mini);
            maxi = Math.max(A.get(j), maxi);

            if (mini == i && maxi == j)
            {
                count++;
                j++;
                i = j;
                maxi = i;
                mini = j;
            }
            else
                j++;
        }
        return count;
    }
}
