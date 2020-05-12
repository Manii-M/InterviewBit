public
class Solution
{
    boolean possible(int dist, ArrayList<Integer> A, int cows)
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
        int maxi = A.get(A.size() - 1) - A.get(0);
        while (mini <= maxi)
        {
            int mid = mini + (maxi - mini) / 2;
            if (possible(mid, A, B))
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
