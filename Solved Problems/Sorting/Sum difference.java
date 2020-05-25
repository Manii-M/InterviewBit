/**
 * Approach - to understand the contribution of each number in making the subsets
*/
public
class Solution
{

public
    int solve(ArrayList<Integer> A)
    {

        Collections.sort(A);
        int pow = 1;
        long mod = 1000000007, sum = 0, max = 0, min = 0;

        for (int i = 0; i < A.size(); i++)
        {

            min = (min * 2) % 1000000007;

            min = (min + A.get(i)) % 1000000007;
        }

        for (int i = A.size() - 1; i >= 0; i--)
        {

            max = (max * 2) % 1000000007;

            max = (max + A.get(i)) % 1000000007;
        }

        long ans = (max - min + 1000000007) % 1000000007;

        return (int)ans;
    }
}