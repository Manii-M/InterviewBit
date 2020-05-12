/*
Approach - we have to see what will be the next string in this permutation.
start from end - check till what index string is in descending order. min_index
swap the elements - swap the element with the minimum on right side but greater min_index.
sort - sort the string from min_index+1 to end. or alternative is we can reverse the same length which saves log(n) time.
*/


int findingSortIndex(vector<int> &A, int start)
{
    int swap_index = -1;
    int num = A[start - 1];

    for (int i = start; i < A.size(); i++)
    {
        if (swap_index < A[i] && A[i] > num)
        {
            swap_index = i;
        }
    }
    return swap_index;
}

vector<int> finNextPermutation(vector<int> &A)
{
    int DescOrder = 0;//if already in descnding order
    for (int i = A.size() - 1; i > 0; i--)
    {
        if (A[i - 1] < A[i])
        {
            DescOrder = 1;
            int min = findingSortIndex(A, i);
            if (min != -1)
            {
                int swap = A[i - 1]; //swapping the elements just greater then the 
                A[i - 1] = A[min];
                A[min] = swap;
                sort(A.begin() + i, A.end());
                break;
            }
        }
    }

    if (!DescOrder) //return sorted order
        sort(A.begin(), A.end());

    return A;
}

vector<int> Solution::nextPermutation(vector<int> &A)
{
    return finNextPermutation(A);
}
