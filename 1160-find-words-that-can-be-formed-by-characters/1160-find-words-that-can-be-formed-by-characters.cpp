class Solution 
{
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
        
        int count[26]{}; int ans = 0;
        
        for(char& c : chars) ++count[c - 'a'];
        
        for(string& word : words) 
        {
            int wCount[26]{}; bool good = true;
            
            for(char& c : word) ++wCount[c - 'a'];
            
            for(int i = 0; i < 26; i++) if(count[i] < wCount[i]){good=false;break;};
            
            if(good) ans += word.size();
        }
        return ans;
    }
};