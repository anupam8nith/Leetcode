#include <vector>
#include <queue>

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size(),  totalCandies = 0;

        queue<int> q;
        vector<bool> has_box(n, false);
        vector<bool> opened_box(n, false);

        for (int box_idx : initialBoxes) 
        {
            has_box[box_idx] = true;
            if (status[box_idx] == 1) 
            {
                q.push(box_idx);
                opened_box[box_idx] = true;
            }
        }

        while (!q.empty()) {
            int current_box = q.front();
            q.pop();

            totalCandies += candies[current_box];

            for (int key_for_box : keys[current_box]) {
                status[key_for_box] = 1;

                if (has_box[key_for_box] && !opened_box[key_for_box]) {
                    q.push(key_for_box);
                    opened_box[key_for_box] = true;
                }
            }

            for (int new_box : containedBoxes[current_box]) {
                has_box[new_box] = true;

                if (status[new_box] == 1 && !opened_box[new_box]) {
                    q.push(new_box);
                    opened_box[new_box] = true;
                }
            }
        }

        return totalCandies;
    }
};