class Solution {
public:
    string makeGood(string s) 
    {
        //using stack
        
        stack<char> st;
        
        for(int i=0;i<s.size();i++)
        {
             st.push(s[i]);
            while (!st.empty() && ((st.top()==s[i+1]+32) || (st.top()==s[i+1]-32))){
                st.pop();
                i++;
            }
        }
        string ans = "";
        
        while( st.empty()!=1)
        {
            ans= st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};

// O(n*n)

// while (sz != s.size()) {
//         sz = s.size();
//         for (int i = 0; i + 1 < s.size(); ++i)
//             if (abs(s[i] - s[i + 1]) == 32)
//                 s = s.substr(0, i) + s.substr(i + 2);
//     }
//     return s;

// O(n)

// for (int i = 0; i < s.size(); ++i) {
//         if (p > 0 && abs(s[i] - s[p - 1]) == 32)
//             --p;
//         else
//             s[p++] = s[i];
//     }
//     return s.substr(0, p);