class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) 
    {
        vector<int> a(101,0);
        int ans=-1;
        int n = logs.size();
        
        for(int i=0;i<n;i++)
        {
           a[logs[i][0]-1950]+=1;
            
            a[logs[i][1]-1950]-=1;
        }
        
        for(int i=1;i<101;i++)
            a[i]+=a[i-1];
        
       
        
        int max=0;
        for(int i=0;i<101;i++)
        {
         if(max<a[i])
         {
             ans=i;
             max=a[i];
         }
        }
        
        return 1950 + ans;
    }
};