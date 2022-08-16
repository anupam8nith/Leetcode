class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
            
        int count=0;
        
        auto it = nums.begin();
        
        while(it!=nums.end())
        {
            if(*it==0)
            {
                nums.erase(it);
                count++;
            }
            if(*it==0)
                it--;
            it++;
        }
        
        while(count--)
            nums.push_back(0);
        return;
    }
};