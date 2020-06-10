/**
 * Maximum Rectangle
Given a 2D binary matrix of integers A containing 0's and 1's of size N x M.

Find the largest rectangle containing only 1's and return its area.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.


Input Format

The only argument given is the integer matrix A.
Output Format

Return the area of the largest rectangle containing only 1's.
Constraints

1 <= N, M <= 1000
0 <= A[i] <= 1
For Example

Input 1:
    A = [   [0, 0, 1]
            [0, 1, 1]
            [1, 1, 1]   ]
Output 1:
    4

Input 2:
    A = [   [0, 1, 0, 1]
            [1, 0, 1, 0]    ]
Output 2:
    1
 *
 /* Approach - observe the pattern that for consecutive one we will make histogram and
 * see for each height we can see we can include the height >= to current height toward left and right
 * so we wll have to find the just smaller elements on it's left and right 
 * and finding just smaller and greater is one of stack application
 * and find the answer
*/
public
class Solution
{

public
    ArrayList<Integer> findMaxRectangle(int start, ArrayList<Integer> row) //function to find max rectangel area for each row
    {

        ArrayList<Integer> smaller = new ArrayList<Integer>();

        for (int i = 0; i < row.size(); i++)
            smaller.add(0);

        Stack<Integer> s = new Stack<Integer>();

        int k = row.size();

        if (start == -1)
            k = -1;

        for (int i = start;;)
        {
            if (start == -1)
            {
                if (i < row.size())
                    i++;
                if (i >= row.size())
                    break;
                k++;
            }
            else
            {
                if (i >= 0)
                    i--;
                if (i < 0)
                    break;
                k--;
            }

            if (s.empty())
            {
                s.push(i);
                if (start == -1)
                    smaller.set(k, -1);
                else
                    smaller.set(k, start);
            }
            else
            {
                while (!s.empty() && row.get(s.peek()) >= row.get(i))
                    s.pop();

                if (!s.empty())
                    smaller.set(k, s.peek());
                else if (start == -1)
                    smaller.set(k, -1);
                else
                    smaller.set(k, start);

                s.push(i);
            }
        }
        return smaller;
    }

public
    int findMaxArea(ArrayList<ArrayList<Integer>> A)
    {
        int n = A.size(), m = A.get(0).size();
        int max_area = 0;
        for (int i = 0; i < n; i++)
        {
            ArrayList<Integer> left_smaller_elements = findMaxRectangle(-1, A.get(i));
            ArrayList<Integer> right_smaller_elements = findMaxRectangle(m, A.get(i));

            //calculating the area
            for (int j = 0; j < m; j++)
            {
                int left_index = left_smaller_elements.get(j);   //left small element index
                int right_index = right_smaller_elements.get(j); //right small element index
                max_area = Math.max(max_area, ((right_index - left_index - 1) * A.get(i).get(j)));
            }
        }

        return max_area;
    }

public
    int solve(ArrayList<ArrayList<Integer>> A)
    {
        int n = A.size(), m = A.get(0).size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (i > 0 && A.get(i).get(j) == 1)
                    A.get(i).set(j, A.get(i - 1).get(j) + A.get(i).get(j));
        }

        return findMaxArea(A);
    }
}
