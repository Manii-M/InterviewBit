public
class Solution
{
public
    int solve(ArrayList<Integer> A, ArrayList<Integer> B)
    {
        HashMap<Integer, Integer> x_map = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> y_map = new HashMap<Integer, Integer>();
        long answer = 0;
        for (int i = 0; i < A.size(); i++) //counting how many points has similar x co-ordinate and similar y co-ordinate so they will be parallel to x-axis and y-axis
        {
            int x = A.get(i);
            int y = B.get(i);
            if (x_map.containsKey(x))
                x_map.put(x, x_map.get(x) + 1);
            else
                x_map.put(x, 1);
            if (y_map.containsKey(y))
                y_map.put(y, y_map.get(y) + 1);
            else
                y_map.put(y, 1);
        }
        int mod = 1000000007;

        for (int i = 0; i < A.size(); i++)
        {
            int x_freq = x_map.get(A.get(i)); //taking out the frequency of each point
            int y_freq = y_map.get(B.get(i));

            if (x_freq >= mod)
                x_freq -= mod;
            if (y_freq >= mod)
                y_freq -= mod;
            answer += (long)(x_freq - 1) * (y_freq - 1);
            answer %= mod;
        }
        return (int)(answer);
    }
}
