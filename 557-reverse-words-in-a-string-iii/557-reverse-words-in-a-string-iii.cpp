class Solution {
public:
    string reverseWords(string s) 
    {
        int front=0;
        for(int i=0;i<=s.size();i++)
        {
            if(s[i]==' ' || i==s.size())
            {
                reverse(&s[front], &s[i]);
                front = i+1;
            }
        }
        
        return s;
    }
};