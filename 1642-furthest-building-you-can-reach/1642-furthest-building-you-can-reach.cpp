class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int totalBricksUsed = 0;
        priority_queue<int> bricksUsed;
        int access = 0;
        for (; access < n-1; access++) {
            // If current height is higher, we don't have to use
            // bricks or ladder.
            if (heights[access] >= heights[access+1]) {
                continue;
            }
        
            // We have to use either brick or ladder.
            int difference = heights[access+1] - heights[access];
        
            if (totalBricksUsed + difference <= bricks) {
                // Prefer bricks because we can later change from 
                // bricks to ladder as we will see below.
                totalBricksUsed += difference;
                bricksUsed.push(difference);
            } else if (ladders > 0) {
                // If even bricks are insufficient, check ladders.
                if (!bricksUsed.empty() && bricksUsed.top() > difference) {   // Alert: Corner case ** 
                    totalBricksUsed = totalBricksUsed - bricksUsed.top() + difference;
                    bricksUsed.pop();
                    bricksUsed.push(difference); // Thanks to @amanda_86
                }
                ladders--;
            } else {
                // Unfortunately, it's not possible to go ahead any further.
                break;
            }
        }
        return access; // This is the max we can go ahead.
    }
};