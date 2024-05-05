class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        multiset<int> ms(people.begin(),people.end());
        int ans = 0;
        while(!ms.empty()){
            auto ptr1 = ms.begin();
            auto ptr2 = ms.upper_bound(limit-*ptr1);
            if(ptr2!=ms.begin())
            {
                --ptr2;
                if(ptr1!=ptr2)ms.erase(ptr2);
            }
            ms.erase(ptr1);
            ans++;
        }
        return ans;
    }
};
