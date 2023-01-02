class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        int n = size(word);
        
        if(n==1)
        return true;
        
        if(islower(word[0]))
        {
            for(int i=1;i<n;i++)
                if(!islower(word[i]))
                    return false;
        }
        
        for(int i=2;i<n;i++)
        {
            if((isupper(word[i]) && isupper(word[i-1])) || (islower(word[i]) && islower(word[i-1])) )
                continue;
            else
                return false;
        }
        
        return true;
    }
};