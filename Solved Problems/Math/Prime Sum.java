/**
 * find prime(a)+prime(b)==Number
 * input will always be an even number
 * Time Complexity is - O(n)
 * Space Complexity is - O(1) 
*/

public
class Solution
{
    /**
     * function to check if the number is prime or not
    */
public
    boolean isPrime(int N)
    {
        if (N <= 1)
            return false;

        for (int i = 2; i <= Math.sqrt(N); i++)
        {
            if (N % i == 0)
                return false;
        }
        return true;
    }
public
    ArrayList<Integer> primesum(int A)
    {

        ArrayList<Integer> Answer = new ArrayList<Integer>();
        int i = 2, j = A - 2;

        if (A == 4) //special case 
        {
            Answer.add(i);
            Answer.add(j);
            return Answer;
        }
        while (i < j)
        {
            boolean result_i = isPrime(i);
            boolean result_ai = isPrime(j);
            int sum = i + j;
            //if both are prime numbers and sum==A return the answer 
            //else move the pointers based on the sum
            if (result_i && result_ai)
            {
                if (sum == A)
                {
                    Answer.add(i);
                    Answer.add(j);
                    return Answer;
                }
                if (sum < A)
                    i++;
                else
                    j--;
            }

            //one of the number is prime move that pointer
            if (!result_ai)
                j--;
            if (!result_i)
                i++;

            // checking if both are not prime than decision is based on the sum
            if (!result_i  && !result_ai) 
            {
                if (sum < A)
                    i++;
                else
                    j--;
            }
        }
        return Answer;
    }
}
