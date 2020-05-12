/**
 * Approach one - we can use brute force method and find the element TC - O(n)
 * better time cpmplexity is we can think of binary search as array is sroted and rotated
 * plot a graph based on the index and the elements in the array and observer
 * we can see there is pivot element for which we make decision ans figure out where will the current elment lies in firt part or second
 * that way we can solve this question in O(logn)
*/
public
class Solution
{
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
public
    int search(final List<Integer> A, int B)
    {
        int low = 0, high = A.size() - 1, n = A.size() - 1, pivot = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (A.get(mid) > A.get(n))
                low = mid + 1;
            if (A.get(mid) <= A.get(n))
            {
                pivot = mid;
                high = mid - 1;
            }
        }

        if (B == A.get(pivot))
            return pivot;

        low = B < A.get(n) ? pivot : 0;
        high = B > A.get(n) ? pivot - 1 : n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (A.get(mid) == B)
                return mid;
            if (A.get(mid) < B)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
}
