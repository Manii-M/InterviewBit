/*
Approach - see all the combination of the equation and take out max and min for each combination their diff's max will be answer.
*/
int findingMax(vector<int> &v, vector<int> &B, vector<int> &C, vector<int> &D)
{
    int max = INT_MIN, min = INT_MAX;

    int result = INT_MIN;

    int signCombination[5];

    for (int j = 1; j <= 32; j++)
    {
        int k = 4;
        int num = j;
        while (k >= 0)
        {
            int d = num & 1;
            num >>= 1;
            if (d == 1)
                signCombination[k] = 1; //1 means -
            else
                signCombination[k] = -1; //-1 negative
            k--;
        }
        for (int i = 0; i < v.size(); i++)
        {
            int value = signCombination[0] * v[i] + signCombination[1] * B[i] + signCombination[2] * C[i] + signCombination[3] * D[i] + signCombination[4] * i;
            max = max < value ? value : max;
            min = min > value ? value : min;
        }
        result = result > max - min ? result : max - min;
        max = INT_MIN;
        min = INT_MAX;
    }

    return result;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
{

    return findingMax(A, B, C, D);
}
