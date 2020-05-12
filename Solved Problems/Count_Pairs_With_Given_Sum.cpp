/**
 * Approach here is two pointer approach if we see an example
 * 1 2 3 4 5 and sum - 5
 * so if we see 1 + = 6, 6>5 so after 5 if we add anything 1 will  alway make greater sum not less sum so we can make desicion here.
 * similarly if we see sum = 7 and 1 + 5 = 6 , 6<7 so adding 1 to lessernumbers than 5 will never give us the sum so we can increase
 * the 1 to 2 and 2 + 5 = 7 which is the required sum.
 * this is two pointer approach 
 * sum factors to remember in two pointer approach
 * 1. sorted
 * 2. make desicion skip sum elements
 * 3. identify initialize the pointer 
*/
int Solution::solve(vector<int> &A, int B)
{

    int count = 0, i = 0, j = A.size() - 1;
    while (i < j)
    {
        if (A[i] + A[j] > B)
            j--;
        else if (A[i] + A[j] < B)
            i++;
        else if (A[i] + A[j] == B)
        {
            count++;
            i++;
            j--;
        }
    }
    return count;
}
