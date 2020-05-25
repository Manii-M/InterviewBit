void finfAllSubsets(vector<int> A, int cur_index, int n, vector<int> subset, map<vector<int>, int> &answer)
{
    if (cur_index == n)
    {
        answer[subset] = 0;
        return;
    }

    vector<int> temp(subset);
    subset.push_back(A[cur_index]);
    finfAllSubsets(A, cur_index + 1, n, subset, answer);
    finfAllSubsets(A, cur_index + 1, n, temp, answer);
}

vector<vector<int>> Solution::subsetsWithDup(vector<int> &A)
{
    vector<int> subset;
    map<vector<int>, int> answer;
    vector<vector<int>> real_answer;
    sort(A.begin(), A.end());
    finfAllSubsets(A, 0, A.size(), subset, answer);

    for (auto it = answer.begin(); it != answer.end(); it++)
        real_answer.push_back(it->first);
    return real_answer;
}
