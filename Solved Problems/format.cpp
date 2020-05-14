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
