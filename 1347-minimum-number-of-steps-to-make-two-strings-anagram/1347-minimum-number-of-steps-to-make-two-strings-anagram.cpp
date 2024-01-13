class Solution {
public:
    int minSteps(string& s, string& t) {
    int freq[26]={0}, ans=0, n=size(s);
    for (int i=0; i<n; i++){
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }
    for( int i=0; i<26; i++)
        if (freq[i]>0)
            ans+=freq[i];
    return ans;
}

};