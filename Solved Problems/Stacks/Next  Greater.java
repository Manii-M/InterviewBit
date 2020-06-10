public class Solution {
    public ArrayList<Integer> nextGreater(ArrayList<Integer> A) {
        ArrayList<Integer> next_greater = new ArrayList<Integer>();
        Stack<Integer> s = new Stack<Integer>();
        for(int i=0;i<A.size();i++)
            next_greater.add(0);
        
        int k=A.size()-1;
        
        for(int i=A.size()-1; i >= 0; i--)
        {
            if(s.empty())
            {
                s.push(i);
                next_greater.set(i,i);
            }
            else
            {
                while(!s.empty() && A.get(s.peek())<=A.get(i))
                    s.pop();
                if(!s.empty())
                {
                    next_greater.set(i, s.peek());
                     s.push(i);
                }
                else
                {
                    s.push(i);
                    next_greater.set(i, i);
                }
                 
            }
        }
         for(int i=0;i<next_greater.size();i++)
         {
            if(i==next_greater.get(i))
                next_greater.set(i,-1);
            else
                next_greater.set(i,A.get(next_greater.get(i)));
         }
        return next_greater;
    }
}
