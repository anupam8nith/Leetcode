class Solution {
public:
    vector<int> intersect(vector<int>& n1, vector<int>& n2) 
    {
        int m=n1.size(), n = n2.size();
        vector<int> ans;
        
        //sort
        sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());
        
        // find and pushback and make null;
       if(m<n)
            {
            for(int i=0;i<m;i++)
                {
                    if(binary_search(n2.begin(), n2.end(), n1[i]))
                    {
                        ans.push_back(n1[i]);
                    int index= lower_bound(n2.begin(), n2.end(), n1[i]) - n2.begin();
                        
                        n2[index] = INT_MIN;
                    }
                }

            }
        else
            {
                for(int i=0;i<n;i++)
                {
                    if(binary_search(n1.begin(), n1.end(), n2[i]))
                    {
                        ans.push_back(n2[i]);
                    int index= lower_bound(n1.begin(), n1.end(), n2[i]) - n1.begin();
                        
                        n1[index] = INT_MIN;
                    }
            }
        
    }
        return ans;
    }
};