class Solution {
public:
    int nextGreaterElement(int n) 
    {
        if(n==INT_MAX)
            return -1;
        
        string s= to_string(n);

        if(next_permutation(s.begin(),s.end())!=NULL && stol(s)<=INT_MAX)
        {
            return stol(s);
        }
        else return -1;
        
    }
};