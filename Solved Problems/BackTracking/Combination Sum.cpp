void findAllSubsets(vector<int> A, int cur_index, int n, map<vector<int>, int> &answer, int sum, vector<int> subset)
{
    if (cur_index == n)
        return;
    if (sum == 0)
    {
        answer[subset] = 0;
        return;
    }
    if (sum < 0)
        return;

    for (int i = cur_index; i < A.size(); i++)
    {
        subset.push_back(A[i]);
        findAllSubsets(A, i, n, answer, sum - A[i], subset);
        subset.pop_back();
    }
}
vector<vector<int>> Solution::combinationSum(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    map<vector<int>, int> answer;
    vector<int> subset;
    vector<vector<int>> real_answer;
    findAllSubsets(A, 0, A.size(), answer, B, subset);

    for (auto it = answer.begin(); it != answer.end(); it++)
    {
        real_answer.push_back(it->first);
    }
    return real_answer;
}
