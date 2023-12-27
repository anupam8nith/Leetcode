class Solution 
{
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int n = colors.size(),ans=0;
        
        for(int i=0;i<n;i++)
        {
            int j=i+1, mxt= neededTime[i];
            
            while(colors[i]==colors[j] && j<n)
            {
                if(neededTime[j]<mxt)
                ans+=neededTime[j];
                else {ans+=mxt;mxt=neededTime[j];}
                j++;
            }
            
            i=j-1;
        }
        return ans;
        
    }
};

//TC = O(klogk) where k is the largest sequence of equal colors
// SC = O(n)