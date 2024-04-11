class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans; 
        int n = num.size();  
        stack<char> s;
        
        if(k >= n)
            return "0";
        
        s.push(num[0]);
        
        for(int i = 1; i < n; i++) {
            while(k > 0 && !s.empty() && s.top() > num[i]) {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        
        while(k > 0 && !s.empty()) {
            s.pop();
            k--;
        }
        
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        // Removing leading zeros
        int i = 0;
        while(i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);
        
        return ans.empty() ? "0" : ans;
    }
};
