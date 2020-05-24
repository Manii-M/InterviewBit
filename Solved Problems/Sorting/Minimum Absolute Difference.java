public
class Solution
{
public
    int solve(ArrayList<Integer> A)
    {
        Collections.sort(A);
        int mini = Integer.MAX_VALUE;
        for (int i = 0; i < A.size() - 1; i++)
            mini = Math.min(mini, Math.abs(A.get(i) - A.get(i + 1)));
        return mini;
    }
}