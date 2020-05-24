/**
 * SIXLETS
Problem Description
Given a array of integers A of size N and an integer B. Return number of non-empty subsequences of A of size B having sum <= 1000.   


Problem Constraints
1 <= N <= 20 1 <= A[i] <= 1000 1 <= B <= N   


Input Format
The first argument given is the integer array A. The second argument given is the integer B.   


Output Format
Return number of subsequences of A of size B having sum <= 1000.


Example Input
Input 1:
    A = [1, 2, 8]
    B = 2
Input 2:
    A = [5, 17, 1000, 11]
    B = 4
  


Example Output
Output 1:
3
Output 2:
0
  


Example Explanation
Explanation 1:
 {1, 2}, {1, 8}, {2, 8}
 Explanation 1: 
 No valid subsequence

 Approach - first see there is recursion or not in the question
 then identify the backtracking
 and try to find out three things 
 1. Number of choices to make
 2. Constraints and when to backtrack
 3. Base Condition
*/

public
class Solution
{
public
    void allSubsequences(int[] A, int B, int cur_index, int sum, int subseq_size, Inte count)
    {
        if (subseq_size == B)
        {
            if (sum >= 0)
            {
                count.x++;
            }
            return;
        }
        if (cur_index == A.length)
            return;
        if (sum < 0)
            return;
        for (int i = cur_index; i < A.length; i++)
        {
            subseq_size++;
            allSubsequences(A, B, i + 1, sum - A[i], subseq_size, count);
            subseq_size--;
        }
    }
public
    int solve(int[] A, int B)
    {
        Inte count = new Inte();
        allSubsequences(A, B, 0, 1000, 0, count);
        return count.x;
    }
public
    class Inte
    {
        int x = 0;
    }
}
