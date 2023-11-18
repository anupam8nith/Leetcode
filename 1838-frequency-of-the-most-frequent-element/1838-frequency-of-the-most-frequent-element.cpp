class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long long> prefixSum(n + 1);

        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int lo = 0, hi = i;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                long long total = (long long)nums[i] * (i - mid + 1);
                long long sum = prefixSum[i + 1] - prefixSum[mid];

                if (total - sum <= k) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }

            ans = max(ans, i - lo + 1);
        }

        return ans;
    }
};