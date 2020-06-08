/**
 * Question - All Subarrays
Problem Description

Given an integer array A of size N. You have to generate it's all subarrays having the size greater than 1.

Then for each subarray find Bitwise XOR of its maximum and second maximum element.

Find and return the maximum value of XOR among all subarrays.



Problem Constraints
2 <= N <= 105

1 <= A[i] <= 107



Input Format
Only argument is an integer array A.



Output Format
Return an integer, i.e maximum value of XOR of maximum and 2nd maximum element among all subarrays.



Example Input
Input 1:

 A = [2, 3, 1, 4]
Input 2:

 A = [1, 3]


Example Output
Output 1:

 7
Outnput 2:

 2


Example Explanation
Explanation 1:

 All subarrays of A having size greater than 1 are:
 Subarray            XOR of maximum and 2nd maximum no.
 1. [2, 3]           1
 2. [2, 3, 1]        1
 3. [2, 3, 1, 4]     7
 4. [3, 1]           2
 5. [3, 1, 4]        7
 6. [1, 4]           5
So maximum value of Xor among all subarrays is 7.
Explanation 2:

 Only subarray is [1, 3] and XOR of maximum and 2nd maximum is 2.
 /*
 * Approach - Brute force is to take out all the subarrays and chek the first max and second max and get the answer which will require n^3 time complexity
 * we optimise is using stack
 * Approach - we consider each element the 2nd maximum element and find out the lef maximum of it and right maximum of it that will be a valid subarray 
 * and take the xor for left max and right max and their maximum will be the answer.
 * we can find the left_max and left_max using stack which is very good application of stack 
 * TC - O(n);
 * SC-O(n)
*/
public
class Solution
{
public
    void preCalculateMax(int start, ArrayList<Integer> A, ArrayList<Integer> left_max)
    {
        Stack<Integer> s = new Stack<Integer>();
        int n = A.size(), k = 0;
        if (start != -1) //checking are we calculating the right_max or left_max
            k = n - 1;
        for (int i = start;;)
        {
            if (start == -1)
            {
                if (i < n)
                    i++;
                if (i >= n)
                    break;
            }
            else
            {
                if (i >= 0)
                    i--;
                if (i < 0)
                    break;
            }

            if (s.empty())
            {
                s.push(i);
                left_max.set(k, i);
                if (start == -1)
                    k++;
                else
                    k--;
            }
            else
            {
                if (A.get(s.peek()) > A.get(i))
                {
                    left_max.set(k, s.peek());
                    if (start == -1)
                        k++;
                    else
                        k--;
                    s.push(i);
                }
                else
                {
                    while (!s.empty() && A.get(s.peek()) <= A.get(i))
                        s.pop();

                    if (!s.empty()) //if not empty top element is maximum or current element is maximum
                        left_max.set(k, s.peek());
                    else
                        left_max.set(k, i);
                    s.push(i);

                    if (start == -1)
                        k++;
                    else
                        k--;
                }
            }
        }
    }
public
    int solve(ArrayList<Integer> A)
    {

        //first find the left max and right max of the array
        ArrayList<Integer> left_max = new ArrayList<Integer>();
        ArrayList<Integer> right_max = new ArrayList<Integer>();
        for (int i = 0; i < A.size(); i++)
        {
            left_max.add(0);
            right_max.add(0);
        }
        preCalculateMax(-1, A, left_max);
        preCalculateMax(A.size(), A, right_max);
        int answer = 0;
        for (int i = 0; i < A.size(); i++)
        {
            int second_max = A.get(i);
            int left_m = A.get(left_max.get(i));
            int right_m = A.get(right_max.get(i));
            answer = Math.max(answer, second_max ^ left_m);
            answer = Math.max(answer, second_max ^ right_m);
        }
        return answer;
    }
}
