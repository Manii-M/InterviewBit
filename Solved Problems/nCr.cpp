/**
 * here we have to find the value of nCr 
 * formula is - nCr = n-1Cr+n-1Cr-1
 * using precomputtation and using above formula we can calculate the next value of nCr
 * this is also pascal triangle.
 * 
*/
int Solution::solve(int A, int B, int C)
{
    vector<vector<int>> mat(A);

    if (A == B)
        return 1;

    for (int i = 0; i < A; i++)
    {
        mat[i] = vector<int>(B + 2);
        int min = B + 1 > i + 1 ? i + 1 : B + 1;
        for (int j = 0; j <= min; j++)
        {

            int n = i + 1, r = j;

            if (n == r || r == 0)
                mat[i][j] = 1;
            else
                mat[i][j] = (mat[i - 1][j - 1] % C + mat[i - 1][j] % C) % C;

            if (i + 1 == A && j == B)
                return mat[i][j];
        }
    }

    return 0;
}
/**
 * this code is for the modinverse where we have given the modulo as prime number
 * so using fermats little theorem - a^p = 1 mod p
*/
// int modInverse(int base,int mod){

// }

// int fastpower(int base,int power,int mod){
//   long long int result =1;

//   while(power>1 && base!=1){
//       if(power%2==1)
//           result = base;
//         power=power>>1;
//         base = (base%mod * base%mod)%mod;

//   }
//  return (int)((result%mod * base%mod)%mod);
// }
// int Solution::solve(int A, int B, int c) {
//   vector<int> fact(A+1,1);
//   for(int i=2;i<=A;i++)
//   {
//      fact[i]=(fact[i-1]%c*i%c)%c;
//      cout<<fact[i]<<" ";
//   }

//   return (fact[A] * fastpower(fact[A-B],c-2,c)%c * fastpower(fact[B],c-2,c)%c)%c;
// }
