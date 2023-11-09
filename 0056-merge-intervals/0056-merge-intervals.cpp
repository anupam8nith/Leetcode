class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;
        if(intervals.size()==0)return ans;     
        
        sort(intervals.begin(), intervals.end(),[](vector<int> &a, vector<int> &b)
             {
            return a[0] < b[0];   // comparing according to 1st element
            });
        
        vector<int> curr=intervals[0];
        
        for(int i=1;i<intervals.size();i++)
        {
            if(curr[1]<intervals[i][0])
            {
                ans.push_back(curr);
                curr=intervals[i];
            }
            else curr[1]=max(curr[1], intervals[i][1]);
        }
        
        ans.push_back(curr);
        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) 
//     {
//         set<pair<int, int>> sp;
//         vector<vector<int>> ans;

//         for (auto it : intervals) sp.insert({it[0], it[1]});

//         auto current_interval = *sp.begin();

//         for (auto it = sp.begin(); it != sp.end(); ++it)
//         {
//             if (it->first > current_interval.second)
//             {
//                 ans.push_back({current_interval.first, current_interval.second});
//                 current_interval = *it;
//             }
//             else current_interval.second = max(current_interval.second, it->second);
//         }

//         ans.push_back({current_interval.first, current_interval.second});

//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) 
//     {
//         set<pair<int, int>> sp;
//         set<pair<int, int>> remove;
//         vector<vector<int>> ans;

//         for (auto it : intervals) sp.insert({it[0], it[1]});

//         for (auto dibba : sp)
//         {
//             int x1 = dibba.first, y1 = dibba.second;

//             for (auto dusradibba : sp)
//             {
//                 if (dibba == dusradibba) continue;

//                 int x2 = dusradibba.first, y2 = dusradibba.second;
                
//                 if(y1<x2 || y2<x1)continue;

//                 if (x1 <= x2 && y1 >= y2) remove.insert({x2, y2});
//                 else if (x1 < x2 && y1 <= y2)
//                 {
//                     remove.insert({x1, y1});
//                     remove.insert({x2, y2});
//                     sp.insert({x1, y2});
//                 }
//                 else if (x1 >= x2 && y1 > y2)
//                 {
//                     remove.insert({x1, y1});
//                     remove.insert({x2, y2});
//                     sp.insert({x2, y1});
//                 }
//                 else if (x1 > x2 && y1 <= y2) remove.insert({x1, y1});
//             }
//         }

//         for (auto it : remove) sp.erase(it);
//         remove.clear();
        
//         for (pair<int, int> it : sp) ans.push_back({it.first, it.second});

//         return ans;
//     }
// };