class Solution {
public:
    string reverseWords(string s) 
    {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int front=0;
        int i=0;
        for(i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                reverse(&s[front], &s[i]);
                front = i+1;
            }
        }
        reverse(&s[front], &s[i]);
        
        return s;
    }
};