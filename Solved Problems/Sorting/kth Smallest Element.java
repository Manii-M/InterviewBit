public
class Solution
{
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
public
    int kthsmallest(final List<Integer> a, int B)
    {
        ArrayList<Integer> A = new ArrayList<Integer>(a);
        Collections.sort(A);
        return A.get(B - 1);
    }
}