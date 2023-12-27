class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int n = colors.size(),ans=0;
        
        for(int i=0;i<n;i++)
        {
            int j=i; vector<int> time;
            
            while(colors[i]==colors[j] &&j<n) {time.push_back(neededTime[j]);j++;}
            
            if(time.size()!=0)
            {
                sort(time.begin(),time.end());
                for(int cnt=0;cnt<time.size()-1;cnt++)ans+=time[cnt];
            }
            
            i=j-1;
        }
        return ans;
        
    }
};