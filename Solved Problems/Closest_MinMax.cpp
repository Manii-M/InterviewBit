/*
Approach 1. we can find out max and min. then take all subarrays and ,
if min and max is there then take minimum of their lenghts. TC- O(n^2).

Approach 2. find max and min element of the array.
now check when we encounter the last max and last min in the array.
explanation - if we have last min already we just have to see for last max 
(if already encountered else next max will be the next maximum) .
and the minimum of the difference of the last min and last max indices will be our closest maxmin.

*/

int Solution::solve(vector<int> &A)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        if (min > A[i])
            min = A[i];
        if (max < A[i])
            max = A[i];
    }

    if (min == max)
        return 1;

    int last_min = -1, last_max = -1;
    int min_length = A.size();

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == max) //maximum
        {
            if (last_min != -1) //last min exists then calculate length.
                min_length = min_length > i - last_min + 1 ? i - last_min + 1 : min_length;
            last_max = i; //always change the index even if last min is not there
        }
        if (A[i] == min)
        {
            if (last_max != -1)
                min_length = min_length > i - last_max + 1 ? i - last_max + 1 : min_length;
            last_min = i;
        }
    }
    return min_length;
}
