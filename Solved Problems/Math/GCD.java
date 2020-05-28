/**
 * gcd(a,b) = gcd(a-b,b) , a > b , chinese research
 * based on this property we can prove the gcd with repeated subtraction which is nothing but % mod
*/
public class Solution {
    public int gcd(int A, int B) {
        if(B==0)
            return A;
        return gcd(B,A%B);
    }
}
