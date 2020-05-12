/**
 * Approach we will have to identify the farthest maximum size container.
 * so we' can put our pointers at starting and end which ever is minimum.
 * we'll move that pointer as we have calculated the max area for that height
*/
int Solution::maxArea(vector<int> &A)
{
    if (A.size() <= 1)
        return 0;
    int i = 0, j = A.size() - 1, answer = INT_MIN;
    while (i < j)
    {
        int mini = min(A[i], A[j]);

        int container_area = mini * (j - i);
        
        answer = max(answer, container_area);
        if (mini == A[i])
            i++;
        else
            j--;
    }
    return answer;
}
