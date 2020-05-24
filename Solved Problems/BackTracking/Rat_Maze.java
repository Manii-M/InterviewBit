/**
 * Approach - we can see for each cell we jave 4 possible direction to move.
 * we will keep moving until we find the possible solution.
*/
public
class Solution
{

public
    void findPossiblePaths(ArrayList<ArrayList<Integer>> A, int row, int col, int ZeroCount, int visitedCount, Inte path, int n, int m)
    {

        if (row >= 0 && row < n && col >= 0 && col < m && A.get(row).get(col) == 2)
        {
            if (visitedCount == ZeroCount)
                path.x++;
            return;
        }

        if (row >= 0 && row < n && col >= 0 && col < m)
        {
            if (A.get(row).get(col) >= 0)
            {
                A.get(row).set(col, -1);

                findPossiblePaths(A, row, col + 1, ZeroCount, visitedCount + 1, path, n, m);

                findPossiblePaths(A, row + 1, col, ZeroCount, visitedCount + 1, path, n, m);

                findPossiblePaths(A, row - 1, col, ZeroCount, visitedCount + 1, path, n, m);

                findPossiblePaths(A, row, col - 1, ZeroCount, visitedCount + 1, path, n, m);

                A.get(row).set(col, 0);
            }
        }
    }

public
    int solve(ArrayList<ArrayList<Integer>> A)
    {
        int ZeroCount = 0, start = 0, end = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A.get(i).size(); j++)
            {
                if (A.get(i).get(j) == 0)
                    ZeroCount++;
                if (A.get(i).get(j) == 1)
                {
                    start = i;
                    end = j;
                }
            }
        }

        Inte path = new Inte();
        path.x = 0;

        findPossiblePaths(A, start, end, ZeroCount, -1, path, A.size(), A.get(0).size());
        return path.x;
    }

public
    class Inte
    {
    public
        int x = 0;
    }
}
