class Solution {
public:
    
    string reverseVowels(string s) 
    {
        int n = s.size();
        
        string ans="";
        
        string vowels="";
        
        for(int i=0;i<n;i++)
        {
            int temp = (int)(s[i]-'a');
            int Temp = (int)(s[i]-'A');
            
            if(temp == 0 || temp == 4 || temp == 8 || temp == 14 || 
               temp == 20 || Temp == 0 || Temp == 8 || Temp == 14 || Temp == 20 || Temp == 4)
             vowels+=s[i];
        }
        
        // reverse the characters but not position
        
       reverse(vowels.begin(),vowels.end());
        
        int j=0;
        
        for(int i=0;i<n;i++)
        {
           int temp = (int)(s[i]-'a');
            int Temp = (int)(s[i]-'A');
            
            if(temp == 0 || temp == 4 || temp == 8 || temp == 14 || 
               temp == 20 || Temp == 0 || Temp == 8 || Temp == 14 || Temp == 20 || Temp == 4)
            {
                ans+=vowels[j];
                j++;
            }
            else
                ans+= s[i];
        }
        
        return ans;
    }
};