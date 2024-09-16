class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        set<int> timeSet;  // To store time in minutes
        int diff = INT_MAX;

        // Convert each time point to minutes and store in the set
        for (string s : timePoints) 
        {
            int temp_time = 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3, 2));
            
            // Check for duplicate times
            if (timeSet.find(temp_time) != timeSet.end())
                return 0;  // If duplicate time exists, the minimum difference is 0

            timeSet.insert(temp_time);
        }

        // Now that all times are in the set, calculate minimum difference
        int firstTime = *timeSet.begin();
        int prevTime = firstTime;
        
        // Traverse the set to calculate time differences
        for (auto it = next(timeSet.begin()); it != timeSet.end(); ++it) {
            int currTime = *it;
            diff = min(diff, currTime - prevTime);
            prevTime = currTime;
        }

        // Check the circular difference between the last and first time
        diff = min(diff, 1440 - (*timeSet.rbegin() - firstTime));

        return diff;
    }
};
