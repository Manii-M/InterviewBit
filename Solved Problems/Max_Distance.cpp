/* Approach sort the array hacing it original indices.
then all elements will be in the sorted order. A[i]<=A[j] one condition satisfied.
i<=j this should also be satisfy to get the maximum j-i.
we just need to find out the minimum of i at each index and 'subtract it from the original indes of that.
*/
int Solution::maximumGap(const vector<int> &A)
{
    vector<pair<int, int>> sorted;

    int n = A.size();

    for (int i = 0; i < n; i++)
        sorted.push_back(make_pair(A[i], i));

    sort(sorted.begin(), sorted.end());

    int minimum_from_left = INT_MAX,answer = 0;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = sorted[i];
        minimum_from_left = minimum_from_left < p.second ? minimum_from_left : p.second;
        int val = p.second - minimum_from_left;

        if (val > answer)
            answer = val;
    }

    return answer;
}
