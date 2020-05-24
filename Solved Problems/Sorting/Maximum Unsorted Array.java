/**
 * Maximum Unsorted Subarray
Problem Description
Given an array A of non-negative integers of size N. Find the minimum sub-array Al, Al+1 ,..., Ar such that if we sort(in ascending order) that sub-array, then the whole array should get sorted. If A is already sorted, output -1.


Problem Constraints
1 <= N <= 1000000
1 <= A[i] <= 1000000


Input Format
First and only argument is an array of non-negative integers of size N.


Output Format
Return an array of length 2 where First element denotes the starting index(0-based) and second element denotes the ending index(0-based) of the sub-array. If the array is already sorted, return an array containing only one element i.e. -1.


Example Input
Input 1:
A = [1, 3, 2, 4, 5]
Input 2:
A = [1, 2, 3, 4, 5]
   


Example Output
Output 1:
[1, 2]
Output 2:
[-1]
   


Example Explanation
Explanation 1:
If we sort the sub-array A1, A2, then the whole array A gets sorted.
   Explanation 2:  
A is already sorted.

Approach - find the first occurence of unsorted subarray from and right
and find out the minimum and maximum element of first occured element on left side.
then see those maximum and minimum are not going to expand the size of the subarray
by checking if they are occuring in 0 to s and n-1 to e


*/
public
class Solution
{
public
    ArrayList<Integer> subUnsort(ArrayList<Integer> A)
    {
        ArrayList<Integer> answer = new ArrayList<Integer>();
        int start = -1, end = -1;
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (A.get(i) > A.get(i + 1))
            {
                start = i;
                break;
            }
        }
        if (start == -1)
        {
            answer.add(-1);
            return answer;
        }

        for (int i = A.size() - 1; i > 0; i--)
        {
            if (A.get(i) < A.get(i - 1))
            {
                end = i;
                break;
            }
        }

        int mini = A.get(start), maxi = A.get(start);

        for (int i = start + 1; i <= end; i++)
        {
            if (A.get(i) < mini)
                mini = A.get(i);
            if (A.get(i) > maxi)
                maxi = A.get(i);
        }

        for (int i = 0; i < start; i++)
        {

            if (A.get(i) > mini)
            {
                start = i;
                break;
            }
        }

        for (int i = A.size() - 1; i > end; i--)
        {
            if (A.get(i) < maxi)
            {
                end = i;
                break;
            }
        }

        answer.add(start);
        answer.add(end);
        return answer;
    }
}
