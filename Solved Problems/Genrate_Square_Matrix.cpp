/**
 * Approach - if we dry run any example there is a pattern.
 * so after every travesal we will generate all the sides of the current size matrix 
 * and we will be left with one submatrix of size (curr.row-1,curr.col-1)
 * and we have to keep doing the same thing until we reach the center element which 1x1 matrix.
 * and there is a pattern to traverse it.
*/
vector<vector<int>> Solution::generateMatrix(int A)
{

    vector<vector<int>> v(A, vector<int>(A, 0));
    int siz = A - 1, ele = 1;

    for (int i = 0; i <= siz; i++)
    {

        int start = i, end = i, dir = 0;
        if (dir == 0)
        {

            while (end <= siz)
            {
                v[start][end] = ele;
                ele++;
                end++;
            }
            dir = 1;
            start++;
            end--;
        }
        if (dir == 1)
        {

            while (start <= siz)
            {
                v[start][end] = ele;
                ele++;
                start++;
            }
            dir = 2;
            start--;
            end--;
        }
        if (dir == 2)
        {
            while (end >= i) // to make sure it stays inside the new matrix
            {
                v[start][end] = ele;
                ele++;
                end--;
            }
            end++;
            start--;
            dir = 3;
        }
        if (dir == 3)
        {
            while (start >= (i + 1))
            {
                v[start][end] = ele;
                ele++;
                start--;
            }
        }
        siz--;
    }
    return v;
}
