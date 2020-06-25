int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void findMinCost(vector<int> A,int &minCost,int cost)
{
    if(A.size()==0)
    {
        if(minCost>cost)
            minCost=cost;
        return;
    }
    vector<int> temp(A);
    if(A.size()>1)
    {
    cost+=gcd(A[0],A[A.size()-1]);
    A.erase(A.begin());
    A.erase(A.begin()+A.size()-1);
    }
    findMinCost(A,minCost,cost);
    vector<int> temp1(temp);

    if(temp.size()>1){
     cost+=gcd(temp[0],temp[temp.size()/2]);
    temp.erase(temp.begin());
    temp.erase(temp.begin()+temp.size()/2);
    }
    findMinCost(temp,minCost,cost);
    if(temp1.size()>1){
    cost+=gcd(temp1[temp1.size()/2],temp1[temp1.size()-1]);
    temp1.erase(temp1.begin()+temp1.size()/2);
    temp1.erase(temp1.begin()+temp1.size()-1);
    }
    findMinCost(temp1,minCost,cost);
    
}
int Solution::emptyTheArray(vector<int> &A) {
    int minCost = 0;
    findMinCost(A,minCost,0);
    return minCost;
    
}
