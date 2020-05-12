/**
 * Approach - binary search in answer space
 * three steps to make sure
 * 1. brute force - linear searc is there or not
 * 2. find the definite answer space
 * 3. is the answer function is monotunous function or not
 * Approach for this problem is
 * 1. brute force
 *      we will have to checkfor the each distance we can put all the cows in the stall array
 *      k=1,2,3,4, .... max - min
 *      so we are doing a linear search to figure out the answer on k
 * 
 * 2. answer space 
 *      as we are searching for each possible distance our answer space will be
 *      [1,A[n-1]-A[0]] array is sorted.
 * 3. is function monotnous or not
 *      so we have litmus test also to verify this.
 *      F(k) = for k distance we can put all the cows in the stall 
 *      k`<= k is also hold true
 *      similarly
 *      F(k) = at k distance if can not any one of the cow
 *      k`>=k holds false
 * so based on these observation we can do binary search on the answer
 * time complexity - sort nlogn + nlog(max-min)
 * O(nlog(max-min))
 * 
*/
public
class Solution
{
    boolean can_put_all_cows_at_distance_mid(int dist, ArrayList<Integer> A, int cows)
    {
        int count = 1;
        int prev_pos = A.get(0);
        for (int i = 1; i < A.size(); i++)
        {
            int curr_pos = A.get(i);
            if ((curr_pos - prev_pos) >= dist)
            {
                count++;
                prev_pos = curr_pos;
            }
        }
        if (count >= cows)
            return true;
        return false;
    }
public
    int solve(ArrayList<Integer> A, int B)
    {

        int answer = 0;
        Collections.sort(A);
        int mini = 1;
        int maxi = A.get(A.size() - 1) - A.get(0); //answer space [1,A[n-1]-A[0]]
        while (mini <= maxi)
        {
            int mid = mini + (maxi - mini) / 2;
            if (can_put_all_cows_at_distance_mid(mid, A, B))
            {
                answer = mid;
                mini = mid + 1;
            }
            else
                maxi = mid - 1;
        }
        return answer;
    }
}
