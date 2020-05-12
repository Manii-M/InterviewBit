/*
example -
        N = 9
        N = 2 + 3 + 4
        N = 5 + 4
N can be represented as 
N = (x+1)+(x+2)+(x+3) ..... (x+k)
9 = (1+1)+(1+2)+(1+3)
so the 1 >= k <= N and x = 1

so the sum of all k = k*(k-1)/2
and and sum of all x = kx
so N = kx+(k*(k-1))/2


kx = N - (k*(k-1))/2
so it's given the k > 0 and x > 0

so RHS N - (k*(k-1))/2 > 0
after simplification
k(k-1) < 2N 
k < sqrt(2N)


so just have to calculate -- 
(N-(k*(k-1)/2)%k == 0 and increment ans+=1;
*/

int Solution::solve(int A)
{
    int ans = 0;
    for (int d = 1; d * (d + 1) / 2 <= A; d++)
    {
        int a = 2 * A + d - d * d;
        int b = 2 * d;
        if (a % b == 0)
            ans++;
    }
    return ans;
}
