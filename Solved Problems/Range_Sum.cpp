/*
Refere to this link - https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
to understand matrix exponential to get nth Fibonnaci 
*/
typedef long long int lint;
lint mod = 1000000007;
void Multiply(lint F[2][2], lint M[2][2])
{
    lint x = lint(F[0][0] * M[0][0]) % mod + lint(F[0][1] * M[1][0]) % mod;
    lint y = lint(F[0][0] * M[0][1]) % mod + lint(F[0][1] * M[1][1]) % mod;
    lint z = lint(F[1][0] * M[0][0]) % mod + lint(F[1][1] * M[1][0]) % mod;
    lint w = lint(F[1][0] * M[0][1]) % mod + lint(F[1][1] * M[1][1]) % mod;

    F[0][0] = x % mod;
    F[0][1] = y % mod;
    F[1][0] = z % mod;
    F[1][1] = w % mod;
}

void nthFibonnaci(int n, lint matrixC[2][2])
{
    if (n == 0 || n == 1)
        return;

    lint matrix[2][2] = {{1, 1}, {1, 0}};
    nthFibonnaci(n / 2, matrixC);
    Multiply(matrixC, matrixC);
    if (n % 2 != 0)
        Multiply(matrixC, matrix);
}

int Solution::solve(int A, int B)
{
    lint matrix[2][2] = {{1, 1}, {1, 0}};

    nthFibonnaci(B + 1, matrix);

    lint b = matrix[0][0];

    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 0;

    nthFibonnaci(A, matrix);
    lint a = matrix[0][0];
    lint ans = (b - a) % mod;
    return (int)(ans + mod) % mod;
}
