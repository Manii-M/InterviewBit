/*
Approach - we can use sliding window.
Simply we have to find out how many number are there in the array which are less_than the given number 
that will be our window size -  if those all are togethere
so we can use a binary array for that 
0 - if less than true
1 - else
[0,1,0,1]
we can have a prefix sum of this binary array.
and at each index it will tell how many number are greater then the given number
then we slide our window from 0 to n-window_size
at look for how many numbers(freater number has to be replaced with smaller numbers ) are required to swap in the windo
*/

int Solution::solve(vector<int> &A, int B)
{
    int window_size = 0, n = A.size();
    for (int i = 0; i < n; i++)
    {
        if (B >= A[i])
        {
            window_size++;
            A[i] = 0;
        }
        else
            A[i] = 1;
    }

    for (int i = 1; i < n; i++)
        A[i] += A[i - 1];

    int min_swap = INT_MAX;

    for (int i = 0; i < n - window_size + 1; i++)
    {
        if (i == 0)
        {
            min_swap = min_swap > (A[i + window_size - 1]) ? A[i + window_size - 1] : min_swap;
        }
        else
        {
            min_swap = min_swap > (A[i + window_size - 1] - A[i - 1]) ? (A[i + window_size - 1] - A[i - 1]) : min_swap;
        }
    }
    if (min_swap == INT_MAX)
        min_swap = 0;
    return min_swap;
}
