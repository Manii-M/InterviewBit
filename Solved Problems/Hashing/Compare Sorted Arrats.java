/**
 * Compare Sorted Subarrays
Problem Description

Given an array A of length N. You have to answer Q queires.

Each query will contain 4 integers l1, r1, l2 and r2. If sorted segment from [l1, r1] is same as sorted segment from [l2 r2] then answer is 1 else 0.

NOTE The queries are 0-indexed.



Problem Constraints
0 <= A[i] <= 100000
1 <= N <= 100000
1 <= Q <= 100000



Input Format
First argument is an array A.
Second will be 2-D array B denoting queries with dimension Q * 4.
Consider ith query as l1 = B[i][0], r1 = B[i][1], l2 = A[i][2], r2 = B[i][3].



Output Format
Return an array of length Q with answer of the queries in the same order in input.



Example Input
Input 1:

 A = [1, 7, 11, 8, 11, 7, 1]
 B = [ 
       [0, 2, 4, 6]
     ]
Input 2:

 A = [1, 3, 2]
 B = [
       [0, 1, 1, 2]
     ] 


Example Output
Output 1:

 [1]
Output 2:

 [0]


Example Explanation
Explanation 1:

 (0, 2) -> [1, 7, 11]
 (4, 6) -> [11, 7, 1]
 Both are same when sorted hence 1.
Explanation 2:

 (0, 1) -> [1, 3]
 (1, 2) -> [3, 2] 
 Both are different when sorted hence -1.
 *
 * Approach - give random key to each number which will decrease the collison then take prefix sum which will solve the problem easily
*/
public
class Solution
{
public
    ArrayList<Integer> solve(ArrayList<Integer> A, ArrayList<ArrayList<Integer>> B)
    {
        HashMap<Integer, Long> mapped_a = new HashMap<Integer, Long>();
        long range = 1000000000;
        for (int element : A)
        {
            if (!(mapped_a.containsKey(element)))
            {
                mapped_a.put(element, (long)(Math.random() * range));
            }
        }

        ArrayList<Long> prefix_sum_of = new ArrayList<Long>();
        ArrayList<Integer> answer = new ArrayList<Integer>();

        prefix_sum_of.add(mapped_a.get(A.get(0)));

        for (int i = 1; i < A.size(); i++)
            prefix_sum_of.add(prefix_sum_of.get(i - 1) + mapped_a.get(A.get(i)));

        for (int i = 0; i < B.size(); i++)
        {
            int l1 = B.get(i).get(0);
            int r1 = B.get(i).get(1);
            int l2 = B.get(i).get(2);
            int r2 = B.get(i).get(3);
            long first = prefix_sum_of.get(r1);
            long second = prefix_sum_of.get(r2);
            if (l1 > 0)
            {
                first = prefix_sum_of.get(r1) - prefix_sum_of.get(l1 - 1);
            }

            if (l2 > 0)
            {
                second = prefix_sum_of.get(r2) - prefix_sum_of.get(l2 - 1);
            }

            if (first == second)
            {
                answer.add(1);
            }
            else
                answer.add(0);
        }
        return answer;
    }
}
