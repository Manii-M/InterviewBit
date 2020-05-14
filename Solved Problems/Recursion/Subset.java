/**
 * Question - Given a set of distinct integers, A, return all possible subsets. NOTE:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
   


Problem Constraints
1 <= |A| <= 16
INTMIN <= A[i] <= INTMAX


Input Format
First and only argument of input contains a single integer array A.


Output Format
Return a vector of vectors denoting the answer.


Example Input
Input 1:
 
A = [1]
  Input 2:          
 
A = [1, 2, 3]
      


Example Output
Output 1:
 
[
    []
    [1]
]
  Output 2:          
 
[
 []
 [1]
 [1, 2]
 [1, 2, 3]
 [1, 3]
 [2]
 [2, 3]
 [3]
]
      


Example Explanation
Explanation 1:
 You can see that these are all possible subsets.
  Explanation 2:          
You can see that these are all possible subsets.

/*
 * 
 * Approach - each element has two possibilities -
 *  it will be in the subset or it won't be in the subset -  so number of subsets 2^n
 * we can generate all binarys from o to 2^n -1  and based on the set bits we can have all subsets
 * Appeoach 2 - as each element has 2 possibilities we can draw a tree including the current element and excluding the current element
 * it is kind of fixing the element in at current index and observer the recursion
 * 
*/
public
class Solution
{
public
    void findAllSubsets(ArrayList<Integer> A, ArrayList<Integer> subset, ArrayList<ArrayList<Integer>> all_subsets, int cur_index)
    {
        if (cur_index == A.size())
        {
            all_subsets.add(new ArrayList<Integer>(subset));
            return;
        }

        ArrayList<Integer> including_element = new ArrayList<Integer>(subset);
        including_element.add(A.get(cur_index));
        findAllSubsets(A, including_element, all_subsets, cur_index + 1); //including the element to form a set 
        findAllSubsets(A, subset, all_subsets, cur_index + 1); //sending the subset which did not select the current index
    }
public
    ArrayList<ArrayList<Integer>> subsets(ArrayList<Integer> A)
    {
        ArrayList<ArrayList<Integer>> all_subsets = new ArrayList<ArrayList<Integer>>();
        Collections.sort(A); // sorting the element to get the answer in lexographic order
        findAllSubsets(A, new ArrayList<Integer>(), all_subsets, 0);
        Collections.sort(
            all_subsets, new Comparator<ArrayList<Integer>>() {
                @Override public int compare(ArrayList<Integer> a, ArrayList<Integer> b)
                {
                    int an = a.size();
                    int bn = b.size();
                    for (int i = 0; i < Math.min(an, bn); i++)
                    {
                        int cmp = Integer.compare(a.get(i), b.get(i));
                        if (cmp != 0)
                            return cmp;
                    }
                    return Integer.compare(a.size(), b.size());
                }
            });
        return all_subsets;
    }
}
