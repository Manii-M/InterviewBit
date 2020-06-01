/*
Equal
Problem Description

Given an array A of N integers, find the index of values that satisfy P + Q = R + S, where P,Q,R & S are integers values in the array

NOTE:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices in the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 if:
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2


Problem Constraints
1 <= N <= 1000

0 <= A[i] <= 1000



Input Format
Single argument which is an integer array A of size N.



Output Format
Return an array of size 4 which indexes of values P,Q,R and S.



Example Input
Input 1:

 A = [3, 4, 7, 1, 2, 9, 8]
Input 2:

 A = [2, 5, 1, 6]


Example Output
Output 1:

 [0, 2, 3, 5]
Output 2:

 [0, 1, 2, 3]


Example Explanation
Explanation 1:

 A[0] + A[2] = A[3] + A[5]
 Note: indexes returned should be 0-based.
Explanation 2:

 A[0] + A[1] = A[2] + A[3]
 /*
 * Approach - make a hashmap for all the pairs and check again with the same pairs to maintain the lexicographical order for the answer
 */

public
class Solution
{
public
    boolean overlapping(int a, int b, int c, int d)
    {
        if (a < b && c < d && a < c && b != c && b != d)
            return false;
        return true;
    }
public
    ArrayList<Integer> equal(ArrayList<Integer> A)
    {
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
        ArrayList<Integer> answer = new ArrayList<Integer>();
        ArrayList<Integer> values = new ArrayList<Integer>();
        
        for (int i = 0; i < A.size(); i++)//adding all the possible pairs sum and thier index 
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                int sum = A.get(i) + A.get(j);

                if (map.containsKey(sum))
                    values = map.get(sum);
                else
                    values = new ArrayList<Integer>();

                values.add(i);
                values.add(j);
                map.put(sum, values);
            }
        }

        for (int i = 0; i < A.size(); i++)//now check the sum exists or not if exists find the valid answer
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                int sum = A.get(i) + A.get(j);
                if (map.containsKey(sum))
                {
                    ArrayList<Integer> val = map.get(sum);

                    for (int k = 0; k < val.size(); k += 2)
                    {
                        if (overlapping(i, j, val.get(k), val.get(k + 1)))
                            continue;
                        answer.add(i);
                        answer.add(j);
                        answer.add(val.get(k));
                        answer.add(val.get(k + 1));
                        return answer;
                    }
                }
            }
        }
        return answer;
    }
}
