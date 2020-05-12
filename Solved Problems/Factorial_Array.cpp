/*
Approach - factorail of number will have prime factors less then that number only which is all primee numbers less then that number
example - !5 - 1 x 2 x 3 x 4 x 5 - 120 PRime Factors  - 2 3 5 which are less then 5

Two number will have same non empty set of prime factors if their max prime factor is same.
 i.e. [5, 6, 7, 10] => maxPrimeFactor(5) = 5 and maxPrimeFactor(6) = 5 that means both have same number of
 prime factor which is [2,3,5] , maxPrimeFactor(7) = 7 and maxPrimeFactor(10) = 7 that means both have same
 number of prime factor which is [2,3,5,7].
 and between two prime numbers all numbers will have similar prime factor 

 Time Complexity  - O(n(logn) (log log max(Array)))
*/

void checkPrime(int maxi, vector<bool> &prime)
{
    for (int i = 2; i <= sqrt(maxi); i++)
    {
        if (prime[i])
        {
            for (int j = i; (long long int)j * i <= maxi; j++)
                prime[i * j] = false;
        }
    }
}

int Solution::solve(vector<int> &A)
{
    sort(A.begin(), A.end());//sort the array
    int maxii = A[A.size() - 1];//find prime numbers till maximum
    vector<bool> prime(maxii + 1, true);
    checkPrime(maxii + 1, prime);
    int total = 0;
    int checked = A.size() - 1;
    for (int i = maxii; i >= 2; i--)
    {
        int count = 0;
        if (prime[i])
        {
            int j = checked;
            while (j >= 0 && A[j] >= i)
            {
                count++;
                j--;
            }

            checked = j;
        }

        total += pow(2, count) - 1; //counting subsequence
    }
    return total;
}
