class Solution {
public:
    vector<vector<int>> generate(int nr) 
    {
        vector<vector<int>> answer;
        
        
        
        for(int i=0;i<nr;i++)
        {
            vector<int> ans(i+1);
            for(int j=0;j<=i;j++)
            {
                if(i==0 || j==0 || j==i)
                    ans[j]=1;
                else
                {
                    ans[j] = answer[i-1][j-1]+answer[i-1][j];
                }
                
            }
            answer.push_back(ans);
            ans.clear();
        }
        
        return  answer;
    }
};