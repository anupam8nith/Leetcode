class Solution {
    
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int minPartitions(string n) {
        int max = 0;
        int i = 0;
        int len = n.size();
        for (; i < len; i++) {
            int num =  n[i] - 48;
            if (num == 9) {
                return 9;
            }
            if (num > max) {
                max = num;
            } 
            
        }
        return max;
    }
};

//solution 1 71ms

// class Solution {
// public:
//     int minPartitions(string n) 
//     {
//         return *max_element(begin(n), end(n)) - '0'; //Just return max digit
//     }
// };
