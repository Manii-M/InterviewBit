/**
 * Largest Number
Problem Description
Given a array A of non negative integers, arrange them such that they form the largest number. Note: The result may be very large, so you need to return a string instead of an integer.   


Problem Constraints
1 <= len(A) <= 100000
0 <= A[i] <= 2*109


Input Format
First argument is an array of integers.


Output Format
Return a string representing the largest number.


Example Input
Input 1:
 A = [3, 30, 34, 5, 9]
Input 2:
 A = [2, 3, 9, 0]
  


Example Output
Output 1:
 "9534330"
Output 2:
 "9320"
 


Example Explanation
Explanation 1:
 A = [3, 30, 34, 5, 9]
 Reorder the numbers to [9, 5, 34, 3, 30] to form the largest number.
Explanation 2:
 Reorder the numbers to [9, 3, 2, 0] to form the largest number 9320. 
 /*
 Approach - modify the comparator of sorting function
*/
public
class Solution
{
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
public
    String largestNumber(final List<Integer> list)
    {
        ArrayList<String> copy = new ArrayList<String>();

        for (int i = 0; i < list.size(); i++)
            copy.add(Integer.toString(list.get(i)));

        Collections.sort(
            copy, new Comparator<String>() {
                @Override public int compare(String X, String Y)
                {

                    String XY = X + Y;
                    String YX = Y + X;

                    return XY.compareTo(YX) > 0 ? -1 : 1;
                }
            });

        StringBuilder sb = new StringBuilder("");

        for (String s : copy)
        {
            sb.append(s);
        }

        return sb.toString().charAt(0) == '0' ? "0" : sb.toString();
    }
}