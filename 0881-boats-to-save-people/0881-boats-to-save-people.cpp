class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        multiset<int> st(people.begin(),people.end());
        int cnt = 0;
        while(!st.empty()){
            auto frst = st.begin();
            auto fnd = st.upper_bound(limit-*frst);
            if(fnd!=st.begin()){
                --fnd;
                if(frst!=fnd)st.erase(fnd);
            }
            st.erase(frst);
            cnt++;
        }
        return cnt;
    }
};
