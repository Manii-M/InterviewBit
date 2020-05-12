/*
Approach - to add one number in the last digit and see if it is greater then 9 then keep adding the carry int o elements.
*/
vector<int> Solution::plusOne(vector<int> &v)
{
    int carry = 1, CheckingZeros = 0;
    vector<int> A;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (carry == 1)
        {
            if (carry + v[i] > 9)
            {
                v[i] = 0;
                carry = 1;
            }
            else
            {
                v[i] = v[i] + carry;
                carry = 0;
            }
        }
        else
        {
            break;
        }
        if (i == 0 && carry == 1) //when input is 999 we need to add one more space into that.
            v.insert(v.begin(), 1);
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0 && CheckingZeros == 0)
            continue;
        else
        {
            A.push_back(v[i]);
            CheckingZeros = 1;
        }
    }

    return A;
}
