/**
 * Largest Rectangle in Histogram
Problem Description

Given an array of integers A .

A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 1000000000



Input Format
The only argument given is the integer array A.



Output Format
Return the area of largest rectangle in the histogram.



Example Input
Input 1:

 A = [2, 1, 5, 6, 2, 3]
Input 2:

 A = [2]


Example Output
Output 1:

 10
Output 2:

 2


Example Explanation
Explanation 1:

The largest rectangle has area = 10 unit. Formed by A[3] to A[4].
Explanation 2:

Largest rectangle has area 2.
 */
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
    int findMaxArea(ArrayList<Integer> A)
    {
        int m = A.size();
        int max_area = 0;
     
        ArrayList<Integer> left_smaller_elements = findMaxRectangle(-1, A);
        ArrayList<Integer> right_smaller_elements = findMaxRectangle(m, A);

        //calculating the area
        for (int j = 0; j < m; j++)
        {
            int left_index = left_smaller_elements.get(j);   //left small element index
            int right_index = right_smaller_elements.get(j); //right small element index
            max_area = Math.max(max_area, ((right_index - left_index - 1) * A.get(j)));
        }
    

        return max_area;
    }
    public int largestRectangleArea(ArrayList<Integer> A) {
        return findMaxArea(A);
    }
}
