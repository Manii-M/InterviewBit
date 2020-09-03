int Solution::solve(vector<int> &v, vector<int> &w, int cap) {
    int n=v.size();
    int maxVal[n+1][cap+1];
    for (int i=0;i<=n;i++)
    {

        for (int j=0;j<=cap;j++)
        {
            if (i==0 || j==0)
                maxVal[i][j]=0;
            else
                maxVal[i][j] = max(j>=w[i-1]?v[i-1]+maxVal[i-1][j-w[i-1]]:0, maxVal[i-1][j]);
        }
    }
    return maxVal[n][cap];
}
