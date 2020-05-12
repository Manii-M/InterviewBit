/*
Approach - calculate SPF or each number till A.
taking that PSF calculate all the distinct prime factrs of that number.
Time Complexity - O(sqrt(n)log log n)
*/

int Solution::solve(int A)
{

    vector<bool> prime(A + 1, true);

    prime[0] = prime[1] = false;

    int ans = 0;

    vector<int> spf(A + 1, 0);

    for (int i = 2; i <= sqrt(A); i++)
    {
        if (prime[i])
        {
            spf[i] = i;
            for (int j = i; j * i <= A; j++)
            {
                prime[i * j] = false;
                spf[i * j] = i;
            }
        }
    }

    for (int i = 1; i <= A; i++)
    {
        int count = 0;
        int number = i;

        while (number != 1)
        {
            int spf_n = spf[number];
            if(prime[number])
                spf_n = number;
            while (spf_n != 0 && number % spf_n == 0)
                number /= spf_n;
            count++;
        }
        if (count == 2)
            ans++;
    }
    return ans;
}
