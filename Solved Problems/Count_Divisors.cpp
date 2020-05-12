/*
Approach - calculate SPF of each number in the array then count all prime factors and based on that calculate all divisors of the number
TIme Complexity - O(sqrt(n)log log (n)) 
*/

void CalculateSPFandPrimeNumbers(vector<int> &v, vector<bool> &prime)
{

    int m = 1000001;

    for (int i = 2; i <= sqrt(m); i++)
    {
        if (prime[i])
        {
            v[i] = i;
            for (int j = i; (long long int)j * i <= m; j++)
            {
                prime[i * j] = false;
                v[i * j] = i;   
            }
        }
    }
}

vector<int> Solution::solve(vector<int> &A)
{
    int answer = 1;

    vector<int> SPFArray(1000001, 0);

    vector<bool> prime(1000001, true);

    CalculateSPFandPrimeNumbers(SPFArray, prime);
    int total = 1;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] <= 1)
            continue;
        if (!prime[A[i]])
        {
            int number = A[i];
            int count = 0;
            while (number != 1)
            {
                int SPF = SPFArray[number];//smallest prime factor for each array element
                int count = 0;
                if (prime[number])
                    SPF = number;

                while (SPF != 0 && number % SPF == 0)
                {
                    number /= SPF;
                    count++;
                }
                total *= (count + 1); //total number of divisors product of all prime divisors + 1.
            }
            A[i] = total;//total divisors 
        }
        else
            A[i] = 2;
        total = 1;
    }
    return A;
}