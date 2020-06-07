/**
 * Same Cyclic Permutations
Given two String A, B of same length.

Find the number of cyclic permutations of B that are same as A.

Input Format

Given two arguments A, B of type String.
Output Format

Return a single integer N, i.e number of Cyclic Permuations of B same as A.
Constraints

1 <= length(A) = length(B) <= 1e5
Example

Example Input :
    A = aba
    B = aba

Example Output :
    1

Explanation :
    All cyclic permutations of B are :
    1. aba
    2. baa
    3. aab
    here cyclic permutations 1 is same as A so ans is 1.
 /*
 * Approach - Using Z - Algoritham
*/
public
class Solution
{
public
    ArrayList<Integer> calculateZ(String z_input)
    {
        int left = 0, right = 0, len = z_input.length();

        ArrayList<Integer> z_arr = new ArrayList<Integer>();

        for (int i = 0; i < len; i++)
            z_arr.add(0);

        for (int k = 1; k < len; k++)
        {
            if (k > right) //when we have no z_box available
            {
                left = right = k;
                while (right < len && z_input.charAt(right) == z_input.charAt(right - left))
                    right++;
                z_arr.set(k, right - left);
                right--;
            }
            else
            {
                //inside the z_box
                int k1 = k - left; //current char to check the z value with
                if (z_arr.get(k1) < right - k + 1)
                {
                    z_arr.set(k, z_arr.get(k1)); //if not going out of right upper bound then put the same value
                }
                else
                {
                    left = k; //decrese the size of the z_box from left to k
                    while (right < len && z_input.charAt(right) == z_input.charAt(right - left))
                        right++;
                    z_arr.set(k, right - left);
                    right--;
                }
            }
        }
        return z_arr;
    }
public
    int solve(String A, String B)
    {
        String z_input = A + "$" + B + B;
        ArrayList<Integer> z_arr = calculateZ(z_input);
        int count = 0;
        for (int ele : z_arr)
        {
            if (ele == A.length())
                count++;
        }
        return count - 1;
    }
}
