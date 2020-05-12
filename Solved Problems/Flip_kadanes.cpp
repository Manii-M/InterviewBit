/**
 * Approach is modified kadanes algoritham to find the mximum sum sub array.
 * consider 0 - 1 and 1 - -1 we'll have to find the max sum sub array 
*/
vector<int> Solution::flip(string A)
{

    vector<int> v;
    int max_ends_here = 0, max_so_far = 0;
    int new_start_index = 0, end_index = 0, start_index = -1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '0')
            max_ends_here += 1;
        else
            max_ends_here += -1;
        if (max_ends_here < 0)
        {
            new_start_index = i + 1; //from next element we can have the maximum
            max_ends_here = 0;
        }
        if (max_so_far < max_ends_here)
        {
            start_index = new_start_index; //this will remain same untill new max sum
            end_index = i;
            max_so_far = max_ends_here;
        }
    }
    if (start_index != -1)
    {
        v.push_back(start_index + 1);
        v.push_back(end_index + 1);
    }

    return v;
}
