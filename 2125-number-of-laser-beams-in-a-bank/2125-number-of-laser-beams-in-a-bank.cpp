class Solution 
{
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int ans = 0;

        for (int i = 0; i < bank.size() - 1; i++) 
        {
            while (all_of(bank[i].begin(), bank[i].end(), [](char ch) {return ch == '0';})) 
            {
                i++; if (i == bank.size() - 1) return ans;
            }
            
            int onecnt1 = count(bank[i].begin(), bank[i].end(), '1');

            while (all_of(bank[i + 1].begin(), bank[i + 1].end(), [](char ch){return ch == '0';})) 
            {
                i++; if (i == bank.size() - 1) return ans;
            }

            int onecnt2 = count(bank[i + 1].begin(), bank[i + 1].end(), '1');

            ans += onecnt1 * onecnt2;
        }

        return ans;
    }
};
