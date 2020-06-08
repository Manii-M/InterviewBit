/**
 * Sort stack using another stack
Problem Description

Given a stack of integers A, sort it using another stack.

Return the array of integers after sorting the stack using another stack.



Problem Constraints
1 <= |A| <= 5000

0 <= A[i] <= 1000000000



Input Format
The only argument given is the integer array A.



Output Format
Return the array of integers after sorting the stack using another stack.



Example Input
Input 1:

 A = [5, 4, 3, 2, 1]
Input 2:

 A = [5, 17, 100, 11]


Example Output
Output 1:

 [1, 2, 3, 4, 5]
Output 2:

 [5, 11, 17, 100]


Example Explanation
Explanation 1:

 Just sort the given numbers.
Explanation 2:

 Just sort the given numbers.

*/
public
class Solution
{
public
    ArrayList<Integer> solve(ArrayList<Integer> A)
    {
        Stack<Integer> s = new Stack<Integer>();

        for (int i = 0; i < A.size(); i++)
        {
            if (s.empty())
            {
                s.push(A.get(i));
            }
            else
            {
                if (s.peek() >= A.get(i))
                    s.push(A.get(i));
                else
                {
                    Stack<Integer> m = new Stack<Integer>();
                    while (!s.empty() && s.peek() < A.get(i))
                    {
                        m.push(s.pop());
                    }
                    s.push(A.get(i));
                    while (!m.empty())
                    {
                        s.push(m.pop());
                    }
                }
            }
        }
        ArrayList<Integer> answer = new ArrayList<Integer>();
        while (!s.empty())
            answer.add(s.pop());
        return answer;
    }
}
