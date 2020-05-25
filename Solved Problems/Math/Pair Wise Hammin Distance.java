/**
 * Question - Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.

For example,

HammingDistance(2, 7) = 2, as only the first and the third bit differs in the binary representation of 2 (010) and 7 (111).

Given an array of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array.
Return the answer modulo 1000000007.

Example

Let f(x, y) be the hamming distance defined above.

A=[2, 4, 6]

We return,
f(2, 2) + f(2, 4) + f(2, 6) + 
f(4, 2) + f(4, 4) + f(4, 6) +
f(6, 2) + f(6, 4) + f(6, 6) = 

0 + 2 + 1
2 + 0 + 1
1 + 1 + 0 = 8

Approach - one approach is two take xor of each pair and count the set bits*2 and we'll have the answer
TC - O(n^2)
SC - O(1)
another approach is to count number of (set bits * unset bits * 2) at each position for all the elements
TC - O(n)
SC - O(1)
*/
public
class Solution
{
    // DO NOT MODIFY THE LIST. IT IS READ ONLY

public
    int hammingDistance(final List<Integer> A)
    {
        long answer = 0, mod = 1000000007;
        for (int i = 0; i < 32; i++)
        {
            long count = 0;

            for (int j = 0; j < A.size(); j++)
            {
                if ((A.get(j) & (1 << i)) >= 1)
                    count++;
            }

            answer += (count % mod * (A.size() - count) % mod * 2) % mod;//set bits count* unset bits count * 2
            if (answer >= mod)
                answer -= mod;
        }
        return (int)(answer % mod);
    }
}
