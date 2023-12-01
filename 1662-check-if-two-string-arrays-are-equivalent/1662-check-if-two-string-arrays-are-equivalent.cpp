class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        ios::sync_with_stdio(false);cin.tie(0);
        
        int wrdIdx1=0,charIdx1=0,wrdIdx2=0,charIdx2=0;
        
        while(true)
        {
            char c1=word1[wrdIdx1][charIdx1], c2=word2[wrdIdx2][charIdx2];
            
            if(c1!=c2)return false;
            
            charIdx1++;
            charIdx2++;
            
            if(charIdx1==word1[wrdIdx1].size()){wrdIdx1++;charIdx1=0;}
            if(charIdx2==word2[wrdIdx2].size()){wrdIdx2++;charIdx2=0;}
            
            
            if(wrdIdx1==word1.size() && wrdIdx2==word2.size()) break;
            if(wrdIdx1==word1.size() || wrdIdx2==word2.size()) return false;
            
        }
        
        return true;
    }
};