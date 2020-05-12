/*Approach - subtract minimum of the left max and the right max from building height == water_trapped on each building
formula = (min(left_max,right_max)-height of building)
*/
int Solution::trap(const vector<int> &A)
{

    int sizeOfArray = A.size();
    if (sizeOfArray == 1)
        return 0;

    vector<int> rightSideMax(sizeOfArray);

    rightSideMax[sizeOfArray - 1] = A[sizeOfArray - 1]; // to store the right max traverse from end

    for (int i = sizeOfArray - 2; i >= 0; i--)
        rightSideMax[i] = rightSideMax[i + 1] < A[i] ? A[i] : rightSideMax[i + 1]; //storing right_max of each element in the array

    int max_left = A[0]; //left_max can be found out while traversing throught the array

    int water_trapped = 0;

    for (int i = 1; i < sizeOfArray - 1; i++)
    {
        if (max_left < A[i])
                max_left = A[i];
        water_trapped += (max_left < rightSideMax[i] ? max_left : rightSideMax[i]) - A[i];//calculatin total trapped water
    }
    return water_trapped;
}
