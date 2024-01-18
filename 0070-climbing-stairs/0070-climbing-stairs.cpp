class Solution {
public:
    int climbStairs(int n) {
        int next2=1;
        int next1=1;
        for(int i=n-2;i>=0;i--){
            int curr  = next2 + next1;
            next2=next1;
            next1=curr;
        }
        return next1;
    }
};