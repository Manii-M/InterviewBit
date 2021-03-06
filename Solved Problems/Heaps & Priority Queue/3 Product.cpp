/**
 * Product of 3
Problem Description

Given an integer array A of size N.

You have to find the product of the 3 largest integers in array A from range 1 to i, where i goes from 1 to N.

Return an array B where B[i] is the product of the largest 3 integers in range 1 to i in array A. If i < 3, then the integer at index i is -1.



Problem Constraints
1 <= N <= 105
0 <= A[i] <= 103



Input Format
First and only argument is an integer array A.



Output Format
Return an integer array B. B[i] denotes the product of the largest 3 integers in range 1 to i in array A.



Example Input
Input 1:

 A = [1, 2, 3, 4, 5]
Input 2:

 A = [10, 2, 13, 4]


Example Output
Output 1:

 [-1, -1, 6, 24, 60]
Output 2:

 [-1, -1, 260, 520]


Example Explanation
Explanation 1:

 For i = 1, ans = -1
 For i = 2, ans = -1
 For i = 3, ans = 1 * 2 * 3 = 6
 For i = 4, ans = 2 * 3 * 4 = 24
 For i = 5, ans = 3 * 4 * 5 = 60

 So, the output is [-1, -1, 6, 24, 60].
 
Explanation 2:

 For i = 1, ans = -1
 For i = 2, ans = -1
 For i = 3, ans = 10 * 2 * 13 = 260
 For i = 4, ans = 10 * 13 * 4 = 520

 So, the output is [-1, -1, 260, 520].
*/


vector<int> Solution::solve(vector<int> &A) { 
    
    // n is the size of the vector
    int n = A.size();
    
    // Initialize an answer vector
    vector<int> ans;
    
    // Initialize a priority queue
	priority_queue<int>pq;
	
	for(int i=0;i<n;i++){
	    
	    // Add element in priority queue
		pq.push(A[i]);
		
		// Append -1 to the answer as number of elements are < 3.
		if(i<2)
		{
			ans.push_back(-1);
		}
		else
		{
		    //take 3 maximum elements from queue.
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			int c = pq.top();
			
			pq.pop();
			
			//add all these numbers back to queue
			pq.push(a);
			pq.push(b);
			pq.push(c);
			
			//append the product to answer
			ans.push_back(a*b*c);
		}
	}
	return ans;
}



/**
 * TC will be O(n)
 * SC O(1)
 * vector<int> Solution::solve(vector<int> &A) {
    int a=-1,b=1,c=1;
    for(int i=0;i<A.size();i++)
    {
        if(i==0)
        {
            a=A[i];
            A[i]=-1;
        }
        else if(i==1)
        {
            b=A[i];
            A[i]=-1;
        }
        else if(i==2)
        {
            c=A[i];
            A[i]=a*b*c;
        }
        else
        {
            int mini=min(min(a,b),c);
            if(a==mini && a<A[i])
                a=A[i];
            else if(b==mini && b<A[i])
                b=A[i];
            else if(c==mini  && c<A[i])
                c=A[i];
            A[i]=a*b*c;
                
        }
    }
    return A;
}

*/