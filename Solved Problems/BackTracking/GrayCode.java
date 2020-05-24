/**
 * Approach - ther is a mirror pattern in graycode of sequence bassed on that we can generate all graycodes
*/
public
class Solution
{
public
    void generateGrayCode(ArrayList<Integer> grayCodes, int N)
    {
        if (N == 1)
        {
            grayCodes.add(0);
            grayCodes.add(1);
            return;
        }
        generateGrayCode(grayCodes, N - 1);
        for (int i = grayCodes.size() - 1; i >= 0; i--)
            grayCodes.add(grayCodes.get(i) + (1 << (N - 1)));
    }
public
    ArrayList<Integer> grayCode(int a)
    {
        ArrayList<Integer> grayCodes = new ArrayList<Integer>();
        generateGrayCode(grayCodes, a);
        return grayCodes;
    }
}
