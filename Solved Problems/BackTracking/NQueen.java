/**
 * Approach - Draw the tree and understand the when we have to backtrack and put the queen
*/
public
class Solution
{
public
    boolean isSafe(ArrayList<StringBuilder> Board, int row, int col, int N)
    {
        //check if any queen present in the current upper side of column
        for (int i = row; i >= 0; i--)
            if (Board.get(i).charAt(col) != '.')
                return false;

        //check for upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (Board.get(i).charAt(j) != '.')
                return false;

        //chekc for upper right diagonal
        for (int i = row, j = col; i >= 0 && j < N; i--, j++)
            if (Board.get(i).charAt(j) != '.')
                return false;

        return true;
    }
public
    boolean NQueen(ArrayList<ArrayList<String>> answer, ArrayList<StringBuilder> Board, int N, int row)
    {

        if (row >= N)
        {
            ArrayList<String> newstr = new ArrayList<String>();
            for (int i = 0; i < Board.size(); i++)
            {
                newstr.add(Board.get(i).toString());
            }

            answer.add(newstr);
            return true;
        }
        boolean result = false;
        for (int col = 0; col < N; col++)
        {

            if (isSafe(Board, row, col, N))
            {
                Board.get(row).setCharAt(col, 'Q');

                result = NQueen(answer, Board, N, row + 1) || result;

                Board.get(row).setCharAt(col, '.');
            }
        }

        return result;
    }

public
    ArrayList<ArrayList<String>> solveNQueens(int a)
    {
        ArrayList<ArrayList<String>> answer = new ArrayList<ArrayList<String>>();
        ArrayList<StringBuilder> Board = new ArrayList<StringBuilder>();
        ArrayList Q = new ArrayList<String>();
        StringBuilder str = new StringBuilder();

        for (int i = 0; i < a; i++)
            str.append('.');
        for (int i = 0; i < a; i++)
            Board.add(new StringBuilder(str));

        boolean canPlace = NQueen(answer, Board, a, 0);

        return answer;
    }
}
