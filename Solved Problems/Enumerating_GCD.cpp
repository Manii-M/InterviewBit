/*
Approach - GCD(A,A+1 ....B)
case 1. GCD(A,A+1) -> GCD(A+1-A,A) -> GCD(1,A) -> 1
        so if GCD is 1 it can not be greater then 1 qny further.
        so the answer will be 1.
case 2. if A==B then GCD(A,B) = A or B.
*/
string Solution::solve(string A, string B)
{
    if (A == B)
        return A;
    return "1";
}

