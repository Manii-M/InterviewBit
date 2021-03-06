/**
 * B Closest Points to Origin
Problem Description

We have a list A, of points(x,y) on the plane. Find the B closest points to the origin (0, 0).

Here, the distance between two points on a plane is the Euclidean distance.

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in.)

NOTE: Euclidean distance between two points P1(x1,y1) and P2(x2,y2) is sqrt( (x1-x2)2 + (y1-y2)2 ).



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
vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    vector<pair<long long,int>> v;
    int n=A.size();
    
    for(int i=0; i<n; ++i){
        long long x=A[i][0];
        long long y=A[i][1];
        v.push_back({x*x+y*y,i});
    }
    
    // Creating MinHeap in O(N)
    priority_queue<pair<long long, int>, vector<pair<long long,int> >, greater<pair<long long, int> > > minHeap(v.begin(),v.end()); 
    
    vector<vector<int> > ans;
    // Extract B values
    for(int i=0;i<B;i++)
    {
        pair<long long, int> val = minHeap.top();
        minHeap.pop();
        vector<int> temp = A[val.second];
        ans.push_back(temp);
    }
    return ans;
}
*/

vector<vector<int>> Solution::solve(vector<vector<int>> &A, int B)
{
    map<long long int, vector<int>> m;
    for (int i = 0; i < A.size(); i++)
    {
        int x = A[i][0], y = A[i][1];
        long long int dist = (long long int)x * x + (long long int)y * y;
        m[dist].push_back(x);
        m[dist].push_back(y);
    }
    vector<vector<int>> answer;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        vector<int> v(it->second);
        int n = v.size(), i = 0;
        while (i < n && B)
        {
            vector<int> new1;
            new1.push_back(v[i]);
            i++;
            new1.push_back(v[i]);
            i++;
            answer.push_back(new1);
            B--;
        }
    }
    return answer;
}
