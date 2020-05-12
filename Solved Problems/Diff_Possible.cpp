/**
 * Question - Diffk
 * Given an array 'A' of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
 * Approach 1 - Brute force we can use too loop and for each element i we can look for the element j
 * TC - O(n^2)
 * Approach 2 - as we see the array is sorted we can have two pointers approach
 * but for this approch first array should be sorted which is give.
 * second if array is sorted are we able to make a clear decision on incrementing and decrementing pointer.
 * thirs and very important is from where we initiliaze our pointers so we can clear the second term.
 * 
 * 
*/
int Solution::diffPossible(vector<int> &A, int B)
{
    int i = 0, j = 1;
    while (i < j && j < A.size())
    {
        if (A[j] - A[i] > B)
        {
            i++;
            if (i == j)
                j++;
        }
        else if (A[j] - A[i] < B)
            j++;
        else if (A[j] - A[i] == B)
            return 1;
    }
    return 0;
}
