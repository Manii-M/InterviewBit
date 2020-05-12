/*
Approach - 0 1 1 2 3 5 8 13 21 
observe before every even number there are two odd numbers.
so we should count how many pair of 3 in the range can be for every pair of 3 there will be two odd numbers 
*/
int Solution::solve(int A, int B)
{
    int count = 0;
    if (A % 3 == 1) // if two odd numbers are there including A
    {
        count += 2;
        A = A + 2; //so increase it by 2 to take out the number of odd in between A and B
    }
    else
    {
        if (A % 3 == 2) // if 1 odd number are there including A
        {
            count++;
            A++; //so increase it by 1 to take out the number of odd in between A and B
        }
    }

    count += ((B - A) / 3) * 2;
    count += (B % 3);
    return count;
}
