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
 /*
  * Approacch - use merge and before merging count the inversions for the given condition
*/
void merge(vector<int> &A, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[i + start];

    for (int i = 0; i < n2; i++)
        R[i] = A[i + mid + 1];

    int i = 0, j = 0;
    for (int k = start; k <= end; k++)
    {
        if (j >= n2 || (i < n1 && L[i] <= R[j]))
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}
int merge_sort(vector<int> &A, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        int count = merge_sort(A, start, mid) + merge_sort(A, mid + 1, end);
        int j = mid + 1;
        for (int i = start; i <= mid; i++)
        {
            while (j <= end && A[i] > A[j] * 2LL)
                j++;
            count += j - (mid + 1);
        }
        merge(A, start, mid, end);
        return count;
    }
    return 0;
}

int Solution::solve(vector<int> &A)
{

    return merge_sort(A, 0, A.size() - 1);
}
