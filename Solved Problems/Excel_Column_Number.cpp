//it is similar to converting binary to decimal taking base 26 and multiplying the position of the charcter (1-26)
//https://www.geeksforgeeks.org/find-excel-column-number-column-title/ can refer to this
/**
 * Approach - this is similar to binary represantation of decimal numbers
 * here 26 charcter representation of decimal numbers till 26 and further.
 * so we have to convert 26 charcter representation to decimal 
*/
int Solution::titleToNumber(string A)
{

    int number = 0;
    for (int i = 0; i < A.size(); i++)
    {
        int ch = A[i] % 65;
        number += pow(26, A.size() - i - 1) * (ch + 1);
    }
    return number;
}

string Solution::convertToTitle(int A)
{
    string s = "";
    while (A)
    {
        int remainder = A % 26;
        s = (char)((remainder > 0 ? remainder : 26) + 64) + s;
        A = remainder == 0 ? A - 1 : A;
        A /= 26;
    }
    return s;
}
