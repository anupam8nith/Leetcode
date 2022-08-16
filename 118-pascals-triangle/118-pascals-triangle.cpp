class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        std::vector<vector<int>>ans{};
        
        for(int i = 0; i < numRows; i++){
            std::vector<int>row (i+1,1);
            
            for(int j = 1; j < row.size()-1; j++){
                row.at(j) = ans[i-1][j] + ans[i-1][j-1];
            }
            
            ans.push_back(row);
        }
        
        return ans;
    }
};


// my code 0ms accepted

// ios_base::sync_with_stdio(false);
// cin.tie(NULL);

//         vector<vector<int>> answer;
//         for(int i=0;i<nr;i++)
//         {
//             vector<int> ans(i+1);
//             for(int j=0;j<=i;j++)
//             {
//                 if(i==0 || j==0 || j==i)
//                     ans[j]=1;
//                 else
//                 {
//                     ans[j] = answer[i-1][j-1]+answer[i-1][j];
//                 }
                
//             }
//             answer.push_back(ans);
//             ans.clear();
//         }
        
//         return  answer;