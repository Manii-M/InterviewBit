/**
 * MAX and MIN
Problem Description

Given an array of integers A .

value of a array = max(array) - min(array).

Calculate and return the sum of values of all possible subarrays of A % 109+7.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 1000000



Input Format
The first and only argument given is the integer array A.



Output Format
Return the sum of values of all possible subarrays of A % 10^9+7.



Example Input
Input 1:

 A = [1]
Input 2:

 A = [4, 7, 3, 8]


Example Output
Output 1:

 0
Output 2:

 26


Example Explanation
Explanation 1:

Only 1 subarray exists. Its value is 0.
Explanation 2:

value ( [4] ) = 4 - 4 = 0
value ( [7] ) = 7 - 7 = 0
value ( [3] ) = 3 - 3 = 0
value ( [8] ) = 8 - 8 = 0
value ( [4, 7] ) = 7 - 4 = 3
value ( [7, 3] ) = 7 - 3 = 4
value ( [3, 8] ) = 8 - 3 = 5
value ( [4, 7, 3] ) = 7 - 3 = 4
value ( [7, 3, 8] ) = 8 - 3 = 5
value ( [4, 7, 3, 8] ) = 8 - 3 = 5
sum of values % 10^9+7 = 26
 *
 /* Answer - we need to obeserve that we can just count the contribution of each number as minimum and maximum
 * to do that we will be using stacks to find the count of number of elements less and greater then on both left and right side 
 * 
*/

public
class Solution
{
public
    ArrayList<Integer> FindMax(int start, int flag, ArrayList<Integer> A)
    {
        int k = start, n = A.size();
        Stack<Integer> s = new Stack<Integer>();
        ArrayList<Integer> max_index = new ArrayList<Integer>();
        for (int i = 0; i < n; i++)
            max_index.add(0);
        for (int i = start;;)
        {
            if (start == -1)
            {
                if (i < n)
                    i++;
                if (i >= n)
                    break;
                k++;
            }
            else
            {
                if (i >= 0)
                    i--;
                if (i < 0)
                    break;
                k--;
            }
            if (s.empty())
            {
                s.push(i);
                max_index.set(k, 0);
            }
            else
            {
                if (flag == 1)
                {
                    if (start == -1)
                    {
                        while (!s.empty() && A.get(s.peek()) < A.get(i))
                            s.pop();
                        if (!s.empty())
                            max_index.set(k, i - s.peek() - 1);
                        else
                            max_index.set(k, i);
                        s.push(i);
                    }
                    else
                    {
                        while (!s.empty() && A.get(s.peek()) <= A.get(i))
                            s.pop();
                        if (!s.empty())
                            max_index.set(k, s.peek() - i - 1);
                        else
                            max_index.set(k, n - i - 1);
                        s.push(i);
                    }
                }
                else
                {
                    if (start == -1)
                    {
                        while (!s.empty() && A.get(s.peek()) > A.get(i))
                            s.pop();
                        if (!s.empty())
                            max_index.set(k, i - s.peek() - 1);
                        else
                            max_index.set(k, i);
                        s.push(i);
                    }
                    else
                    {
                        while (!s.empty() && A.get(s.peek()) >= A.get(i))
                            s.pop();
                        if (!s.empty())
                            max_index.set(k, s.peek() - i - 1);
                        else
                            max_index.set(k, n - i - 1);
                        s.push(i);
                    }
                }
            }
        }
        return max_index;
    }
public
    int findMaxCount(ArrayList<Integer> A)
    {
        int n = A.size();
        long max_count = 0, min_count = 0, mod = 1000000007;
        ArrayList<Integer> left_max = FindMax(-1, 1, A);
        ArrayList<Integer> right_max = FindMax(n, 1, A);
        for (int i = 0; i < n; i++)
        {
            long l = (long)(left_max.get(i) + 1);
            long r = (long)(right_max.get(i) + 1);
            long mul = (l * r) % mod;
            long val = (long)(A.get(i));
            max_count += (mul * val) % mod;
            if (max_count >= mod)
                max_count -= mod;
        }
        ArrayList<Integer> left_min = FindMax(-1, 0, A);
        ArrayList<Integer> right_min = FindMax(n, 0, A);
        for (int i = 0; i < n; i++)
        {
            long l = (long)(left_min.get(i) + 1);
            long r = (long)(right_min.get(i) + 1);
            long mul = (l * r) % mod;
            long val = (long)(A.get(i));
            min_count += (mul * val) % mod;
            if (min_count >= mod)
                min_count -= mod;
        }
        return (int)(max_count - min_count);
    }
public
    int solve(ArrayList<Integer> A)
    {
        int mod = 1000000007;
        int max_count = findMaxCount(A);
        if (max_count < 0)
            return mod + max_count;
        return max_count;
    }
}
