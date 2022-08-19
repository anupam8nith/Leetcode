class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
            
        
        for(auto x: matrix)
        {
            if(x.at(0)<= target && x.at(x.size()-1)>=target)
            {
                if(binary_search(x.begin(), x.end(), target))
                    return true;
            }
               
        }
        return false;
    }
};