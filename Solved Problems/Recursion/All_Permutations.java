/**
 * Question - All Unique Permutations
 * Problem Description
 * Given an array A of size N denoting collection of numbers that might contain duplicates, return all possible unique permutations. NOTE: No 2 entries in the permutation sequence should be the same.
 * WARNING: DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. Example : next_permutations in C++ / itertools.permutations in python.
 * If you do, we will disqualify your submission retroactively and give you penalty points.
 * Example - 
 * Problem Description
Given an array A of size N denoting collection of numbers that might contain duplicates, return all possible unique permutations. NOTE: No 2 entries in the permutation sequence should be the same.
WARNING: DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.
  


Problem Constraints
1 <= N <= 9


Input Format
Only argument is an integer array A of size N.


Output Format
Return a 2-D array denoting all possible unique permutation of the array.


Example Input
Input 1:
 
A = [1, 1, 2]
  Input 2:        
 
A = [1, 2]
     


Example Output
Output 1:
 
[ [1,1,2]
  [1,2,1]
  [2,1,1] ]

Output 2:        
 
[ [1, 2]
  [2, 1] ]

/*
 * Approach - Try to figure out the recursion here 
 * observations - how many position a element at can be
 * we are fixing first elment and finding all the combination for that
 * similarly for next index we have to do the same
 * so recursion
 * 
*/
public
class Solution
{
public
    void findAllPermutations(ArrayList<Integer> A, int cur_index, ArrayList<ArrayList<Integer>> all_permutations)
    {
        if (cur_index == A.size() - 1)
        {
            all_permutations.add(new ArrayList<Integer>(A));
            return;
        }
        ArrayList<Integer> check_duplicates = new ArrayList<Integer>();
        for (int i = cur_index; i < A.size(); i++)
        {
            if (!(check_duplicates.contains(A.get(i))))
            {
                Collections.swap(A, i, cur_index);
                findAllPermutations(A, cur_index + 1, all_permutations);
                Collections.swap(A, i, cur_index);
                check_duplicates.add(A.get(i));
            }
        }
    }
public
    ArrayList<ArrayList<Integer>> permute(ArrayList<Integer> A)
    {
        ArrayList<ArrayList<Integer>> all_permutations = new ArrayList<ArrayList<Integer>>();
        findAllPermutations(A, 0, all_permutations);
        return all_permutations;
    }
}
