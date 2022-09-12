class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) 
    {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int score=0;
        int n = token.size();
        
        if(n==1)
        {
            if(power<token[0])
                return 0;
            else
                return 1;
        }
        
        //
        
       sort(token.begin(),token.end());
        
       int l=0,r=n-1,ans=0;
        
        
       while(l<=r)
       {
           if(power>=token[l])
           {
               power-=token[l];
               score++;
               ans=max(ans,score);
               l++;
           }
           else if(score>0)
           {
               power+=token[r];
               score--;
               r--;
           }
           else
           {
               break;
           }
       }
           
           
           
           
        return ans;
    }
};