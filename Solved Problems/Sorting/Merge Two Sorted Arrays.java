public
class Solution
{
    // DO NOT MODIFY THE LIST. IT IS READ ONLY

public
    ArrayList<Integer> solve(final List<Integer> A, final List<Integer> B)
    {
        ArrayList<Integer> answer = new ArrayList<Integer>();
        int i = 0, j = 0;
        while (i < A.size() && j < B.size())
        {
            if (A.get(i) <= B.get(j))
            {
                answer.add(A.get(i));
                i++;
            }
            else if (A.get(i) > B.get(j))
            {
                answer.add(B.get(j));
                j++;
            }
        }

        while (i < A.size())
        {
            answer.add(A.get(i));
            i++;
        }
        while (j < B.size())
        {
            answer.add(B.get(j));
            j++;
        }
        return answer;
    }
}