class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>ans;
         

        while(!q.empty()){
             
             auto [row , col ] = q.front();
             q.pop();

             ans.push_back(nums[row][col]);

            //sabse pahle wale column ke last elment ke le test case row+1          taaki last me na jaaaye 
             if(col == 0 && row + 1 < nums.size()){
                  q.push({row+1 , col});
             }

             //sabse last wali column ke lie col + 1 wala condn lagai 
               if (col + 1 < nums[row].size()){
                  q.push({row,col+1});
             }


        }
      return ans;

    }
};