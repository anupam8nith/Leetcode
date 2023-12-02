class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        
        unordered_map<char,int> um; int ans=0;
        for(char& ch: chars)um[ch]++;
        
        for(string& str:words)
        {
            unordered_map<char,int> temp;
            for(char& ch: str)temp[ch]++;
            
            bool flag=true;
            for(auto &it: temp)if(um[it.first]<it.second){flag=false;break;}
            
            if(flag)ans+=str.size();
        }
        
        return ans;
    }
};