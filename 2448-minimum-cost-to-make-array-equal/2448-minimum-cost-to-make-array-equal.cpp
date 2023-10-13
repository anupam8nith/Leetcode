#define ll long long
class Solution {
public:
    ll find(int mid , vector<int>& nums, vector<int>& cost){
        ll ans = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            ans += 1LL*(1LL*abs(nums[i]-mid)*1LL*cost[i]);
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll left = *min_element(nums.begin(), nums.end());
        ll right = *max_element(nums.begin(),nums.end()); 
        ll min_cost = LLONG_MAX;

        while(left<=right){
            int mid = left + (right-left)/2;
            ll p = find(mid,nums,cost);
            ll q = find(mid+1,nums,cost);
            if(p<q){
                right = mid - 1;
                min_cost = min(min_cost,p);
            }
            else{
                left = mid + 2;
                min_cost = min(min_cost , q);
            }

        }
        return min_cost;
       
    }
};