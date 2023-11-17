class Solution {
    public int minPairSum(int[] nums) 
    {
        Arrays.sort(nums);
        int n = nums.length, ans = Integer.MIN_VALUE;

        for (int i = 0; i < n / 2; i++) ans = Math.max(nums[i] + nums[n - 1 - i], ans);

        return ans;
    }
}