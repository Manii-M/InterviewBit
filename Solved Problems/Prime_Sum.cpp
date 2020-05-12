/*
Approach - calculate both the diff and the remaining is prime or not 
*/
bool prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> Solution::primesum(int A)
{
    vector<int> v;
    int diff = 2;
    int remaining = A - diff;
    while (true)
    {
        if (prime(remaining) && prime(diff))
        {
            v.push_back(diff);
            v.push_back(A - diff);
            break;
        }
        else
        {
            diff++;
            remaining--;
        }
    }
    return v;
}
