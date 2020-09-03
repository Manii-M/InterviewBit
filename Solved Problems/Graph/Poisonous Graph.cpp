#define lli long long int
lli mod = 998244353;
lli fastpow(int v, int p)
{
    if (p == 0)
        return 1;
    lli answer = 1, value = v;
    while (p > 0)
    {
        if (p & 1)
            answer = answer * value;
        answer %= mod;
        p >>= 1;
        value *= value;
        value %= mod;
    }

    return answer % mod;
}

int Solution::solve(int A, vector<vector<int>> &B)
{
    vector<int> list[A];
    if (B.size() == 0)
        return fastpow(3, A); //when no edges
    for (int i = 0; i < B.size(); i++)
    {
        list[B[i][0] - 1].push_back(B[i][1] - 1);
        list[B[i][1] - 1].push_back(B[i][0] - 1);
    }

    vector<int> color(A, -1);
    queue<int> q;
    bool Bipartite = true;

    for (int i = 0; i < A; i++)
    {
        if (color[i] != -1)
            continue;
        if (list[i].size() == 0) //for disconnected nodes
            continue;
        q.push(i);
        color[i] = 0; //red
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            vector<int> adj = list[top];
            for (int i = 0; i < adj.size(); i++)
            {
                if (color[adj[i]] == -1)
                {
                    color[adj[i]] = 1 - color[top]; //green
                    q.push(adj[i]);
                }
                else if (color[adj[i]] == color[top])
                {
                    Bipartite = false;
                    break;
                }
            }
        }
    }

    if (!Bipartite)
        return 0;

    lli red = 0, green = 0, discon = 0;

    for (int i = 0; i < A; i++)
    {
        if (color[i] == 0)
            green++;
        else if (color[i] == 1)
            red++;
        else
            discon++;
    }

    lli answer = 0;
    green = fastpow(2, green);
    red = fastpow(2, red);
    answer = (((red + green) % mod) * (fastpow(3, discon) % mod)) % mod;

    return answer;
}
