/**
 * Question  - 
 * Sum of min and max
Problem Description

Given an array A of both positive and negative integers.

Your task is to compute sum of minimum and maximum elements of all sub-array of size B.

NOTE: Since the answer can be very large, you are required to return the sum modulo 109 + 7.



Problem Constraints
1 <= size of array A <= 105

-109 <= A[i] <= 109

1 <= B <= size of array



Input Format
The first argument denotes the integer array A.
The second argument denotes the value B



Output Format
Return an integer that denotes the required value.



Example Input
Input 1:

 A = [2, 5, -1, 7, -3, -1, -2]
 B = 4
Input 2:

 A = [2, -1, 3]
 B = 2


Example Output
Output 1:

 18
Output 2:

 3


Example Explanation
Explanation 1:

 Subarrays of size 4 are : 
    [2, 5, -1, 7],   min + max = -1 + 7 = 6
    [5, -1, 7, -3],  min + max = -3 + 7 = 4      
    [-1, 7, -3, -1], min + max = -3 + 7 = 4
    [7, -3, -1, -2], min + max = -3 + 7 = 4   
    Sum of all min & max = 6 + 4 + 4 + 4 = 18 
Explanation 2:

 Subarrays of size 2 are : 
    [2, -1],   min + max = -1 + 2 = 1
    [-1, 3],   min + max = -1 + 3 = 2
    Sum of all min & max = 1 + 2 = 3 
 /*
 * Approach- use queue to maintaint he minimum and maximum element of each window and store them and find the answer
*/
public
class Solution
{
public
    int solve(ArrayList<Integer> A, int B)
    {
        Deque<Integer> dq_max = new LinkedList<Integer>();
        Deque<Integer> dq_min = new LinkedList<Integer>();
        ArrayList<Integer> max_index = new ArrayList<Integer>();
        ArrayList<Integer> min_index = new ArrayList<Integer>();

        for (int i = 0; i < B; i++)
        {
            if (dq_min.peek() == null || dq_max.peek() == null)
            {
                if (dq_min.peek() == null)
                    dq_min.add(i);
                if (dq_max.peek() == null)
                    dq_max.add(i);
            }
            else
            {
                while (dq_max.peek() != null && A.get(dq_max.peekLast()) <= A.get(i))
                    dq_max.pollLast();
                dq_max.addLast(i);
                while (dq_min.peek() != null && A.get(dq_min.peekLast()) >= A.get(i))
                    dq_min.pollLast();
                dq_min.addLast(i);
            }
        }

        max_index.add(A.get(dq_max.peekFirst()));
        min_index.add(A.get(dq_min.peekFirst()));

        for (int i = 1; i < A.size() - B + 1; i++)
        {
            if (dq_min.peek() == null || dq_max.peek() == null)
            {
                if (dq_min.peek() == null)
                    dq_min.addLast(i);
                if (dq_max.peek() == null)
                    dq_max.addLast(i);
            }
            else
            {
                while (dq_max.peek() != null && (dq_max.peekFirst() < i || A.get(dq_max.peekLast()) <= A.get(B + i - 1)))
                {
                    if (dq_max.peekFirst() < i)
                    {
                        dq_max.pollFirst();
                    }
                    if (dq_max.peek() != null && A.get(dq_max.peekLast()) <= A.get(B + i - 1))
                    {
                        dq_max.pollLast();
                    }
                }
                dq_max.addLast(B + i - 1);
                max_index.add(A.get(dq_max.peekFirst()));
                while (dq_min.peek() != null && (dq_min.peekFirst() < i || A.get(dq_min.peekLast()) >= A.get(B + i - 1)))
                {
                    if (dq_min.peekFirst() < i)
                    {
                        dq_min.pollFirst();
                    }
                    if (dq_min.peek() != null && A.get(dq_min.peekLast()) >= A.get(B + i - 1))
                    {
                        dq_min.pollLast();
                    }
                }
                dq_min.addLast(B + i - 1);
                min_index.add(A.get(dq_min.peekFirst()));
            }
        }
        int mod = 1000000007;
        long answer = 0;
        for (int i = 0; i < min_index.size(); i++)
        {
            answer = (answer % mod + max_index.get(i) % mod + min_index.get(i) % mod) % mod;
            if (answer >= mod)
                answer -= mod;
        }
        if (answer < 0)
            return (int)(mod + answer);
        return (int)(answer);
    }
}
