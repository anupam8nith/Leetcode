class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int count = 0, maj = 0;
        for (int n : nums) {
            if (count == 0) {
                maj = n;
            }
            if (maj == n) {
                count++;
            } else {
                count--;
            }
        }
        return maj;
    }
};