/*
Approach - here the approach is to find the possible combinations of the equation |A[i] - A[j]| + |i - j| 
case 1. i>j && A[i]>A[j]
    Eq - A[i]-A[j]+i-j
        (A[i]+i)-(A[j]+j)

case 2. i>j && A[i]<A[j]
    Eq - A[j]-A[i]+i-j
        (A[j]-j)-(A[i]-i)

case 3. i<j && A[i]<A[j]
    Eq - A[j]-A[i]+j-i
        (A[j]+j)-(A[i]+i)

case 4. i<j && A[i]>A[j]
    Eq - A[i]-A[j]+j-i
        (A[i]-i)-(A[j]-j)

here we observer case 1 and case 3 are same and case 2 and case 4 are same. so we just have to check for 
the two equation and there maximum and the minimum and their diffrence's maximum. which ca be done in o(n) time.

///////////////////////////////////////////////////////////
int Solution::maxArr(vector<int> &A) {
    
    int max1=INT_MIN,max2=INT_MIN,min1=INT_MAX,min2=INT_MAX;
    for(int i=0;i<A.size();i++){
        
        max1=A[i]+i>max1?A[i]+i:max1;
        
        min1=A[i]+i<min1?A[i]+i:min1;
        
        max2=A[i]-i>max2?A[i]-i:max2;
        
        min2=A[i]-i<min2?A[i]-i:min2;
        
        
    }
    
    return (max1-min1)<(max2-min2)?max2-min2:max1-min1;
    
}
//////////////////////////////////////////////////////////

Approach 2 - we see the combination of the mod on the equation |A[i] - A[j]| + |i - j|
+- and +- total = 4 combinations of signs 
+ + 
+ - 
- + 
- -
we can just calculate the max and min for (+ +,+ -) combination and theer difference's maximum will be ABS maximmum sum.

*/


int findingAbsoluteMaximum(vector<int> &v)
{

    int max = INT_MIN, min = INT_MAX;
    int result_sum = INT_MIN;
    int signCombinationArray[2];

    for (int j = 0; j <= 1; j++)
    {
        int k = 1;
        int num = j;
        while (k >= 0)
        {
            int d = num & 1;
            num >>= 1;
            if (d == 0)
                signCombinationArray[k] = 1; //Positive Sign
            else
                signCombinationArray[k] = -1; //Negative Sign
            k--;
        }
        for (int i = 0; i < v.size(); i++)
        {
            int value = signCombinationArray[0] * v[i] + signCombinationArray[1] * i;
            max = max < value ? value : max;
            min = min > value ? value : min;
        }
        result_sum = result_sum > max - min ? result_sum : max - min;
        max = INT_MIN;
        min = INT_MAX;
    }
    return result_sum;
}

int Solution::maxArr(vector<int> &A)
{
    return findingAbsoluteMaximum(A);
}
