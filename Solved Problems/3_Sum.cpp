/**
 * Question - Problem Description
 * Given an array A of N integers, find three integers in A such that the sum is closest to a given number B.
 *  Return the sum of those three integers. Assume that there will only be one solution.
 * Approach 1 - Brute force is we can run three loops and for each element we can find possible pairs
 * and check the minimum abs difference.
 * Appproach 2- if we sort the array fix one of the element
 * A[i]+A[j]+A[k]
 * i is fixed 
 * so in sorteed array we have to find the pair A[j]+A[k] whose sum should be closest to B
 * now problem reduced to finding two pairs which can be done in O(n) time.
 * and fixing each element will take O(n)
 * so the tie complexity is - O(n^2)+O(nlogn)
 * 
*/
int Solution::threeSumClosest(vector<int> &A, int B)
{
    int mini = INT_MAX;
    int answer = 0;
    sort(A.begin(), A.end());
    int i = 0;
    while (i < A.size() - 2)
    {
        int left = i + 1;
        int right = A.size() - 1;

        while (left < right)
        {

            int sum = A[i] + A[left] + A[right];
            int diff = abs(sum - B);
            if (diff == 0)
                return B;
            if (diff < mini)
            {
                mini = diff;
                answer = sum;
            }
            if (sum < B)
                left++;
            else
                right--;
        }
        i++;
    }

    return answer;
}
