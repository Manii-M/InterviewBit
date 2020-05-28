/**
 * Question - Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Example :

n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1
 *
 * Approach - find out the numbers of 5's and 2's from 1 to n.
 * as 2 will always occure before 5 so only need to count number of 5's
*/
public class Solution {
    public int trailingZeroes(int A) {
        int count=0;
        while((A/5)>0)
        {
            count+=A/5;
            A/=5;
        }
        return count;
    }
}