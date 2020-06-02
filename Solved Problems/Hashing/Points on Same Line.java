/**
 * Points on same line
Problem Description

Given two array of integers A and B describing a pair of (A[i], B[i]) coordinates in 2D plane. A[i] describe x coordinates of the ith point in 2D plane whereas B[i] describes the y-coordinate of the ith point in 2D plane.

Find and return the maximum number of points which lie on the same line.



Problem Constraints
1 <= (length of the array A = length of array B) <= 1000

-105 <= A[i], B[i] <= 105



Input Format
First argument is an integer array A.
Second argument is an integer array B.



Output Format
Return the maximum number of points which lie on the same line.



Example Input
Input 1:

 A = [-1, 0, 1, 2, 3, 3]
 B = [1, 0, 1, 2, 3, 4]
Input 2:

 A = [3, 1, 4, 5, 7, -9, -8, 6]
 B = [4, -8, -3, -2, -1, 5, 7, -4]


Example Output
Output 1:

 4
Output 2:

 2


Example Explanation
Explanation 1:

 The maximum number of point which lie on same line are 4, those points are {0, 0}, {1, 1}, {2, 2}, {3, 3}.
Explanation 2:

 Any 2 points lie on a same line.
 /*
 * Approach - slope will be the same for the points which is on the same line
*/


public
class Solution
{

public
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
public
    int solve(ArrayList<Integer> A, ArrayList<Integer> B)
    {
        int answer = 0;

        for (int i = 0; i < A.size() - 1; i++)
        {
            HashMap<String, Integer> map = new HashMap<String, Integer>();

            int same_points = 0, vertical_points = 0;

            int x1 = A.get(i), y1 = B.get(i);

            int current_max = 0;

            for (int j = i + 1; j < A.size(); j++)
            {
                int x2 = A.get(j), y2 = B.get(j);

                if (x1 == x2 && y1 == y2)
                {
                    same_points++;
                }
                else if (x1 == x2)
                {
                    vertical_points++;
                }

                else
                {
                    int dy = y2 - y1;
                    int dx = x2 - x1;
                    int g = gcd(dx, dy);
                    dy /= g;
                    dx /= g;

                    String slope = dx + " " + dy; //making a pair
                    if (map.containsKey(slope))
                        map.put(slope, map.get(slope) + 1);
                    else
                        map.put(slope, 1);
                    current_max = Math.max(current_max, map.get(slope)); //keeping max frequency with same slope
                }

                current_max = Math.max(current_max, vertical_points); //checking if vertical points are more then the similar slops point
            }
            //   map.forEach((k,v)-> System.out.println(k.x+ " "+k.y+" "+v));
            answer = Math.max(answer, (current_max + same_points + 1)); //taking out the maximum icluding similar points and 1 is the current point
        }
        return answer;
    }
}
