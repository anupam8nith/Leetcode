class Solution {
public:
    vector<int> sumZero(int n) 
    {
        vector<int> ans;
        
        if(n&1) //if odd
        {
            ans.push_back(0);
            n--;
        }
        int i=1;
       while(n!=0)
       {
           if(n==0)break;
           
           ans.push_back(i);
           n--;
           if(n==0)break;
           
           ans.push_back(-1*i);
           
           i++;
           n--;
        }
        
        return ans;
            
    }
};