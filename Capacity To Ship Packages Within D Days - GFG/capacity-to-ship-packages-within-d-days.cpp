//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int leastWeightCapacity(int arr[], int N, int D) 
    {
        int low = arr[0];
        int high = 0;
        for (int i = 0; i < N; i++) {
            high += arr[i];
            low = max(low, arr[i]);
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            int totalDays = 1;
            int cumulativeWeight = 0;
            for (int i = 0; i < N; i++) {
                cumulativeWeight += arr[i];
                
                if (cumulativeWeight > mid) {
                    totalDays++;
                    cumulativeWeight = arr[i];
                }
            }
            
            if (totalDays <= D) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends