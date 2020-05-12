/*
some observations are 
if array is -  1 2 3 4 6 7
then FMI - 8
if array is - 10 1 3 4 5 6
then FMI - 2
if there are negative numbers we can ignore them as they will never be the answer.
if there are postive numbers which are greater than the size of the array then that number must be taking place of the
smallest integer as one of index(the number) will be missing from the array
so we will have to assign each element to it's corresponding index in the array //there will be duplicate in the array to handle them check and assign negative at their place.
if any number that is not present at it's index that will be our smallest element.
else all are present then n+1 is the answer.

*/

int Solution::firstMissingPositive(vector<int> &A)
{
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        if (A[i] >= 1 && A[i] <= n && A[i] != i + 1)
        {
            if (A[A[i] - 1] == A[i]) //number is already present at it's index
                A[i] = -1;
            else
            {
                int swap = A[A[i] - 1];
                A[A[i] - 1] = A[i];
                A[i] = swap;
                i--; //the swapped number can be in the range 1<=number<=n so we dont skip that keep checking for the swapped number as well
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}
