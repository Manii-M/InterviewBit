//remove 3 distinct elements
//in the end it  will one or two majority elements.

int Solution::repeatedNumber(const vector<int> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A.size() < 3)
        return A[0];
    int me1, me2, count1 = 0, count2 = 0, count = 0;
    for (int i = 0; i < A.size(); i++)
    {

        if (count1 > 0 && me1 == A[i])
        {
            count1++;
        }
        else if (count2 > 0 && me2 == A[i])
        {
            count2++;
        }
        else if (count1 == 0)
        {
            me1 = A[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            me2 = A[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    if (count1 == 0 && count2 == 0)
        return -1;

    count1 = 0;
    count2 = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (me1 == A[i])
            count1++;
        if (me2 == A[i])
            count2++;
    }
    if (count1 > A.size() / 3)
        return me1;
    if (count2 > A.size() / 3)
        return me2;
    return -1;
}
