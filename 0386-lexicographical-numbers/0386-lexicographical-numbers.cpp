class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> ans;

        for(int i=1;i<=n;i++)
            ans.push_back(to_string(i));

        sort(ans.begin(),ans.end());

        vector<int> v(n);
        int i=0;
        for(auto it: ans)
            v[i++]=stoi(it);

        return v;
    }
};