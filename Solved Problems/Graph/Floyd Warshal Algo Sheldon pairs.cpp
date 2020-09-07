vector<int> Solution::solve(int A, int B, int C, vector<int> &D, vector<int> &E, vector<int> &F, vector<int> &G, vector<int> &H) {
    vector<vector<int>> mat(A,vector<int>(A,INT_MAX));
    for(int i=0;i<B;i++)
    {
        if(mat[D[i]-1][E[i]-1]==INT_MAX)
        {
            mat[D[i]-1][E[i]-1]=F[i];
            mat[E[i]-1][D[i]-1]=F[i];
        }
        else
        {
             mat[D[i]-1][E[i]-1] = min(mat[D[i]-1][E[i]-1],F[i]);
             mat[E[i]-1][D[i]-1] = min(mat[E[i]-1][D[i]-1],F[i]);
        }
    }
    for(int d=0;d<A;d++)
        mat[d][d]=0;
 
    for(int i=0;i<A;i++)
    {
        for(int j=0;j<A;j++)
        {
            for(int k=0;k<A;k++)
            {
               
                if(i!=j && i!=k && mat[j][k]>(long long int)mat[j][i]+mat[i][k])
                    mat[j][k] = mat[j][i]+mat[i][k];
                  if(i!=j && i!=k && mat[k][j]>(long long int)mat[k][i]+mat[i][j])
                    mat[k][j] = mat[k][i]+mat[i][j];
            }
        }
    }
    vector<int> answer;
    for(int i=0;i<C;i++)
    {
        int val = min(mat[G[i]-1][H[i]-1],mat[H[i]-1][G[i]-1]);
        if(val!=INT_MAX)
            answer.push_back(val);
        else 
            answer.push_back(-1);
        
    }
    return answer;
    
}