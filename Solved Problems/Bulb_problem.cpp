//approach is very simple we have to check for the off bulb each time
//so off will be 0
//and each time we encounter 0 we switch it on all right side bulb will toggle.
//so off will be on and on will off
//instead of mainting their states we can just have the count
// if ccount is even bulb is in it's original state.
//if count is odd buld is not in it's original state if it 0 we consider it as 1 vise versa
int Solution::bulbs(vector<int> &A)
{
    int count = 0;
    for (int i = 0; i < A.size(); i++)
    {

        if (count % 2 == 0 && A[i] == 0)
        {
            count++;
        }
        else
        {
            if (count % 2 != 0 && A[i] == 1)
            {
                count++;
            }
        }
    }
    return count;
}
