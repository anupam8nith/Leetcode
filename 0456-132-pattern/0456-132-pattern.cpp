class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        int n = nums.size();
        
        int last_no= INT_MIN; //last_no is last of 132 pattern
        
        stack<int> s;
        
        for (int i = nums.size() - 1; i >= 0; -- i) 
        {
            if (nums[i] < last_no) return true;
            
            while (!s.empty() && nums[i] > s.top()) 
            {
                last_no = s.top(); 
                s.pop();   
            }
            s.push(nums[i]);
        }
        return false;
    }
};