class Solution {
public:

void findall(vector<vector<int>>&ans, vector<int> &candidates, vector<int> currVec, int idx, int sum, int target)
    {
        if (sum == target)
        {
            ans.push_back(currVec);
            return;
        }
        if (idx > candidates.size() || sum > target) return;

        for(int i=idx;i<candidates.size();i++)
        {
                currVec.push_back(candidates[i]);
                findall(ans, candidates, currVec, i, sum + candidates[i], target);
                currVec.pop_back();
        }   
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        
        int n = candidates.size(); vector<vector<int>>ans;
        sort(candidates.begin(), candidates.end());

        long long sum = 0;
        vector<int> currVec;

        findall(ans, candidates, currVec, 0, sum, target);

        return ans;
    }
};