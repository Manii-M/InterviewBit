//Approach - very simple approach is maintaining a charcter frequency map.
//counting the numbers which are repeated in the string including the current charcter.
//decrementing the frequency as it has already been placed
//then counting the number which are less than current charcter.
//multiplying  less_than * fact[size-1]* modinverse(repeat); imp - multiply together.
//mod inverse is to get the inverse of the repeated charcters by fermats little theorem.
//imilar code will work for non repeated charcters as well as thier are no repeated charcter we dont do anything with repeated.
/*
this method is fast power method to calculate the power in log(n) time where n is the power.
*/
long long int modinverse(long long int base, int power, int mod)
{
    long long int result = 1;
    while (power > 0)
    {
        if (power & 1 == 1)
            result = (result * base) % mod;
        power >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

int Solution::findRank(string s)
{
    map<char, int> freq;

    if (s.size() <= 1)
        return 1;
    vector<long long int> fact(s.size() + 1);
    fact[0] = 1;
    fact[1] = 1;
    fact[2] = 2;
    for (int i = 0; i < s.size(); i++)
        freq[s[i]]++;

    for (int i = 3; i <= s.size(); i++)
        fact[i] = (fact[i - 1] * i) % 1000003;

    long long int nrank = 1;
    for (int i = 0; i < s.size(); i++)
    {
        long long int repeat = 1, less_than = 0;

        for (auto it = freq.begin(); it != freq.end(); it++)
            repeat = (repeat * fact[it->second]) % 1000003;

        freq[s[i]]--;

        for (auto it = freq.begin(); it != freq.end(); it++)
            if (s[i] > it->first)
                less_than += it->second;

        nrank += ((less_than * fact[s.size() - 1 - i] % 1000003 * modinverse(repeat, 1000001, 1000003)) % 1000003) % 1000003;
    }
    return (nrank) % 1000003;
}