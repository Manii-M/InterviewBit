/**
 * Approach - we have n^2 approach keeping left pointer and look for the right pointer.
 * another O(n) approach is - to keep track of right side pointer once it has reached we wont have to decrease it - observation.
*/
vector<int> Solution::maxone(vector<int> &A, int B)
{
    int max_length = INT_MIN, l = 0, r = 0, start, end, count_z = 0;
    while (r < A.size())
    {

        if (count_z <= B)
        {
            if (A[r] == 0)
                count_z++;
            r++;
        }

        if (count_z > B)
        {
            if (A[l] == 0)
                count_z--;
            l++;
        }

        if ((r - l + 1) > max_length)
        {
            max_length = r - l + 1;
            start = l;
            end = r;
        }
    }
    vector<int> answer;
    for (int i = start; i < end; i++)
    {
        answer.push_back(i);
    }
    return answer;
}
