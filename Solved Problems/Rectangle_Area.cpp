//we will be finding the co-ordinate for the overlapping rectangle which will
/**
 * Approach - first of all every rectangle will have four sides
 * so the common rectangle will form it's sides using the given two rectangles 8 8 sides 
 * we have to figure out the BL and TR cordinates for the rectangle
*/

int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H)
{

    int x, y;
    x = min(C, G) - max(A, E);
    if (x < 0)
        x = 0;
    y = min(H, D) - max(B, F);
    if (y < 0)
        y = 0;
    return x * y;
}
