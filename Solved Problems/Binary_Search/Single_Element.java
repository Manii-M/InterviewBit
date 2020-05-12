/**
 * Approach 1 - we cna solve this problem by taking XOR operation in  array that is O(n) approach
 * we want it to reduce the time complexity  
 * so we have to think of in the way of binary search 
 * let's plot graph and observer
 * basically 1st observation is that the single number will alwats lie on even index.
 * 2nd observation is a number lies on the even index and not having the side element is similar that is our answer
 * and if side elements are same i can make a comment where our lies i mean which side of the array 
 * 
*/
public
class Solution
{
public
    int solve(ArrayList<Integer> A)
    {
        int low = 0, high = A.size() - 1, mid = 0;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (!(mid + 1 < A.size() && mid - 1 >= 0))
                break;
            int element = A.get(mid);
            if (element != A.get(mid + 1) && element != A.get(mid - 1))
                return A.get(mid);
            else if (element == A.get(mid + 1))
                if ((mid + 1) % 2 == 0)
                    high = mid - 1;
                else
                    low = mid + 1;
            else if (element == A.get(mid - 1))
                if ((mid - 1) % 2 == 0)
                    low = mid + 1;
                else
                    high = mid - 1;
            else
                return A.get(mid);
        }
        return A.get(mid);
    }
}
