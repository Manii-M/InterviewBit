/**
 * B Closest Points to Origin
Problem Description
We have a list A, of points(x,y) on the plane. Find the B closest points to the origin (0, 0). Here, the distance between two points on a plane is the Euclidean distance. You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in.) NOTE: Euclidean distance between two points P1(x1,y1) and P2(x2,y2) is sqrt( (x1-x2)^2 + (y1-y2)^2 ).     


Problem Constraints
1 <= B <= length of the list A <= 100000
-100000 <= A[i][0] <= 100000
-100000 <= A[i][1] <= 100000


Input Format
The argument given is list A and an integer B.


Output Format
Return the B closest points to the origin (0, 0) in any order.


Example Input
Input 1:
 A = [ 
       [1, 3],
       [-2, 2] 
     ]
 B = 1
Input 2:
 A = [
       [1, -1],
       [2, -1]
     ] 
 B = 1
 


Example Output
Output 1:
 [ [-2, 2] ]
Output 2:
 [ [1, -1] ]
 


Example Explanation
Explanation 1:
 The Euclidean distance will be sqrt(10) for point [1,3] and sqrt(8) for point [-2,2].
 So one closest point will be [-2,2].
Explanation 2:
 The Euclidean distance will be sqrt(2) for point [1,-1] and sqrt(5) for point [2,-1].
 So one closest point will be [1,-1].
 * Approach - take all distnce find out and keep in a map
*/
vector<vector<int>> Solution::solve(vector<vector<int>> &A, int B)
{
    map<long long int, vector<int>> m;
    for (int i = 0; i < A.size(); i++)
    {
        vector<int> co_ordinate = A[i];
        long long int x = (long long int)co_ordinate[0] * co_ordinate[0] + (long long int)co_ordinate[1] * co_ordinate[1];
        m[x].push_back(co_ordinate[0]);
        m[x].push_back(co_ordinate[1]);
    }

    auto it = m.begin();
    vector<vector<int>> answer;

    for (int j = 0; j < B && it != m.end(); j++)
    {
        vector<int> co = it->second;
        for (int i = 0; i < co.size() && answer.size() < B; i += 2)
        {
            vector<int> a;
            a.push_back(co[i]);
            a.push_back(co[i + 1]);
            answer.push_back(a);
        }
        it++;
    }
    return answer;
}
