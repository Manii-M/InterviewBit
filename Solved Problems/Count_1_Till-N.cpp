/*
Let’s just figure out the number of 1s at one’s place, a number of 1s in second place and so on. We will add all these occurrences of 1s. 
At one’s place:
up to 10, there is 1 one.
up to 20, there are 2 one’s.
.
.
up to 131, there are 14 one’s
up to 13x(x>1), there are 14 one’s. Number of 1’s at one’s position = (n/10) + (n%10!=0) 
for 10's place 

At 10's place
up to 100, there is 10 one
up to 200, thhere is 20 one
.
.
up to 1x1, there 20 one
as at 10's place x>1 . in that case we will have to count (up to 100 - 10,up to 200 which are 110,111,112,113,114,115,116,117,118,119 -> 10)

*/

int Solution::solve(int n)
{

    if (n <= 0)
        return 0;
    int Quetionet = n, decimalPlace = 1, countOne = 0;
    do
    {
        int remainder = Quetionet % 10;

        Quetionet /= 10;
        countOne += Quetionet * decimalPlace;

        if (remainder == 1)
            countOne += n % decimalPlace + 1;

        if (remainder > 1)
            countOne += decimalPlace;

        decimalPlace *= 10;

    } while (Quetionet > 0);

    return countOne;
}
