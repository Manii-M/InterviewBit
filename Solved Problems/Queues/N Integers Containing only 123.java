/**
 * Question -
 * N integers containing only 1, 2 & 3
Problem Description

Given an integer A. Find and Return first positive A integers in ascending order containing only digits 1, 2 and 3.

NOTE: All the A integers will fit in 32 bit integer.



Problem Constraints
1 <= A <= 29500



Input Format
The only argument given is integer A.



Output Format
Return an integer array denoting the first positive A integers in ascending order containing only digits 1, 2 and 3.



Example Input
Input 1:

 A = 3
Input 2:

 A = 7


Example Output
Output 1:

 [1, 2, 3]
Output 2:

 [1, 2, 3, 11, 12, 13, 21]


Example Explanation
Explanation 1:

 Output denotes the first 3 integers that contains only digits 1, 2 and 3.
Explanation 2:

 Output denotes the first 3 integers that contains only digits 1, 2 and 3.
 /*
 * Approach - It will be a BFS tree and we use a queue to generate all the numbers
 * 
*/
public
class Solution
{
public
    ArrayList<Integer> solve(int A)
    {
        Queue<Integer> q = new LinkedList<Integer>();
        ArrayList<Integer> answer = new ArrayList<Integer>();
        answer.add(1);
        q.add(1);
        if (A == 1)
            return answer;
        answer.add(2);
        q.add(2);
        if (A == 2)
            return answer;
        answer.add(3);
        q.add(3);

        while (answer.size() < A)
        {
            for (int j = 1; j <= 3 && answer.size() < A; j++)
            {
                int num = 10 * q.peek() + j;
                q.add(num);
                answer.add(num);
            }
            q.remove();
        }

        return answer;
    }
}
