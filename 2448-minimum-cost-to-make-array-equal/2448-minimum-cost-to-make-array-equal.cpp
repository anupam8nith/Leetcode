class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        vector<pair<int, int>> arr;
        for(int i=0; i<n; i++) {
            arr.push_back({nums[i], cost[i]});
        }
        sort(begin(arr), end(arr));

        //first calculate cost for nums[0]
        // what calculate    it's  make all otheer elements equal to it..
        long long sum = 0;
        for(int i=1; i<n; i++) {
            long long gap  = arr[i].first - arr[0].first;
            sum += gap*arr[i].second;
        }

        //calculate prefix sum array for costs 
        // inorder to apply the sum in some range
        vector<long long> prefix(n);
        prefix[0] = arr[0].second;
        for(int i=1; i<n; i++) {
            prefix[i] = arr[i].second + prefix[i-1];
        }

        //treat every other index as breaking point and find min
        long long min_cost = sum;
        for(int i=1; i<n; i++) {
            
            //previous elements are being already made equal to it
            int gap(arr[i].first - arr[i-1].first);
            
            //increase the sum to the front
            sum += prefix[i-1]*gap;
            
            //as previously we added the change to sum    we need to remove it now... NOte that your array is in asc order
            sum -= (prefix.back() - prefix[i-1])*gap;

            min_cost = min(sum, min_cost);
        }
        return min_cost;
    }
};