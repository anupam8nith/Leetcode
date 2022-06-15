class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
         vector <int> ans;
        
       unordered_map <int, int> um;
        for(int i=0;i<numbers.size();i++)
        {
            um[numbers[i]]= i;
        }
        
        int i=0;
        
        while( i< numbers.size())
        {
            if(um.find(target - numbers[i]) != um.end() && i!=um[target-numbers[i]]){
                ans.push_back(i+1);
                ans.push_back(um[target-numbers[i]]+1);
                break;
            }
        i++;
        }
        
        return ans;

    }
};