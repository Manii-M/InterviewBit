/**
 *Alternate positive and negative elements
Problem Description
Given an array of integers A, arrange them in an alternate fashion such that every non-negative number is followed by negative and vice-versa, starting from a negative number, maintaining the order of appearance. The number of non-negative and negative numbers need not be equal. If there are more non-negative numbers they appear at the end of the array. If there are more negative numbers, they too appear at the end of the array. Note: Try solving with O(1) extra space.   


Problem Constraints
1 <= length of the array <= 7000
-109 <= A[i] <= 109


Input Format
The first argument given is the integer array A.


Output Format
Return the modified array.


Example Input
Input 1:
 A = [-1, -2, -3, 4, 5]
Input 2:
 A = [5, -17, -100, -11]
  


Example Output
Output 1:
 [-1, 4, -2, 5, -3]
Output 2:
 [-17, 5, -100, -11]
  


Example Explanation
Explanation 1:
A = [-1, -2, -3, 4, 5]
Move 4 in between -1 and -2, A => [-1, 4, -2, -3, 5]
Move 5 in between -2 and -3, A => [-1, 4, -2, 5, -3]
/*
Approach - to mainatain the relative order we will iterate through the array and find positive element and shift it nex to found nexegative element
similarly if array does not start from the negative element we will find first positive and shift that to it's place 
TC - O(n^2)
SC -O(1)
One more approach which takes SC - O(n) and TC -O(n)
where we store all postive numbers in one array and negative numbers in one array and merge them
 *
*/
public
class Solution
{
public
    int findNextPositive(ArrayList<Integer> A, int start, int mod)
    {
        for (int i = start; i < A.size(); i++)
        {
            if (mod == 0)
            {
                if (A.get(i) < 0)
                    return i;
            }
            else
            {
                if (A.get(i) >= 0)
                    return i;
            }
        }
        return -1;
    }
public
    ArrayList<Integer> solve(ArrayList<Integer> A)
    {

        for (int i = 0; i < A.size(); i++)
        {
            int next_positive = -1;

            if (i % 2 == 0 && A.get(i) < 0)
                continue;
            if (i % 2 == 0 && A.get(i) >= 0)
                next_positive = findNextPositive(A, i, 0);
            else
                next_positive = findNextPositive(A, i, 1);
            if (next_positive != -1)
            {
                int k = i, j = next_positive;
                while (j - 1 >= 0 && k != j)
                {
                    int swap = A.get(j);
                    A.set(j, A.get(j - 1));
                    A.set(j - 1, swap);
                    j--;
                }
            }
        }
        return A;
    }
}