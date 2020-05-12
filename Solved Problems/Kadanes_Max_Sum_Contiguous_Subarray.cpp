/*Approach - kadanes alogoritham
concept - there are cases.
case 1. if max_till_now is negative we'll not add it to sum.
case 2. if max_till_now is positive. we'll keep adding the elements in to that untill it becomes negative and keep checking for the max at each iteration.

*/
int Solution::maxSubArray(const vector<int> &A)
{

    int max_so_far = INT_MIN, max_till_now = 0;

    for (int i = 0; i < A.size(); i++)
    {
        max_till_now += A[i];

        if (max_till_now > max_so_far)
            max_so_far = max_till_now;

        if (max_till_now < 0)
            max_till_now = 0;
    }
    return max_so_far;
}
