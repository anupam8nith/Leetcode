class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if (len<2) return 0;
        if (k>len/2){ // simple case
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
        int hold[k+1];
        int rele[k+1];
        for (int i=0;i<=k;++i){
            hold[i] = INT_MIN;
            rele[i] = 0;
        }
        int cur;
        for (int i=0; i<len; ++i){
            cur = prices[i];
            for(int j=k; j>0; --j){
                rele[j] = max(rele[j],hold[j] + cur);
                hold[j] = max(hold[j],rele[j-1] - cur);
            }
        }
        return rele[k];
    }
};

//Stack and Max Heap


// class Solution {
// public:
//     int maxProfit(int k, vector<int> &prices) {
//         int n = (int)prices.size(), ret = 0, v, p = 0;
//         priority_queue<int> profits;
//         stack<pair<int, int> > vp_pairs;
//         while (p < n) {
//             // find next valley/peak pair
//             for (v = p; v < n - 1 && prices[v] >= prices[v+1]; v++);
//             for (p = v + 1; p < n && prices[p] >= prices[p-1]; p++);
//             // save profit of 1 transaction at last v/p pair, if current v is lower than last v
//             while (!vp_pairs.empty() && prices[v] < prices[vp_pairs.top().first]) {
//                 profits.push(prices[vp_pairs.top().second-1] - prices[vp_pairs.top().first]);
//                 vp_pairs.pop();
//             }
//             // save profit difference between 1 transaction (last v and current p) and 2 transactions (last v/p + current v/p),
//             // if current v is higher than last v and current p is higher than last p
//             while (!vp_pairs.empty() && prices[p-1] >= prices[vp_pairs.top().second-1]) {
//                 profits.push(prices[vp_pairs.top().second-1] - prices[v]);
//                 v = vp_pairs.top().first;
//                 vp_pairs.pop();
//             }
//             vp_pairs.push(pair<int, int>(v, p));
//         }
//         // save profits of the rest v/p pairs
//         while (!vp_pairs.empty()) {
//             profits.push(prices[vp_pairs.top().second-1] - prices[vp_pairs.top().first]);
//             vp_pairs.pop();
//         }
//         // sum up first k highest profits
//         for (int i = 0; i < k && !profits.empty(); i++) {
//             ret += profits.top();
//             profits.pop();
//         }
//         return ret;
//     }
// };