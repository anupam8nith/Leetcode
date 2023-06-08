class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end()); //sort the array.
        
        int d = arr[1]-arr[0]; //difference of A.P = d
        
        for(int i=0;i<(arr.size()-1);i++) if((arr[i+1]-arr[i])!=d) return false; // if d != arr[i+1] - arr[i] return false
        
        return true;
    }
};

// class Solution {
// public:
//   bool canMakeArithmeticProgression(std::vector<int>& arr) {
//     int m = *std::min_element(arr.begin(), arr.end());
//     int gap = (int)((std::max_element(arr.begin(), arr.end()) - m) / (arr.size() - 1));
//     if (gap == 0) {
//       return true;
//     }
//     int i = 0;
//     while (i < arr.size()) {
//       if (arr[i] == m + i * gap) {
//         i++;
//       } else {
//         int dis = arr[i] - m;
//         if (dis % gap != 0) {
//           return false;
//         }
//         int pos = dis / gap;
//         if (arr[pos] == arr[i]) {
//           return false;
//         }
//         std::swap(arr[pos], arr[i]);
//       }
//     }
//     return true;
//   }
// };
