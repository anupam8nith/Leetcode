class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        double median = 0;
        
        int m = nums1.size(), n = nums2.size();
        
        if(m>n)
        {
            for(auto it: nums2)nums1.push_back(it);
            sort(nums1.begin(),nums1.end());
            
            if((m+n)%2==0) median = (nums1[(m+n)/2] + nums1[(m+n)/2-1])/2.0;
            else median = nums1[(m+n)/2];
              
             return median;
        }
        else
        {
            for(auto it: nums1)nums2.push_back(it);
            sort(nums2.begin(),nums2.end());
            
            if((m+n)%2==0) median = (nums2[(m+n)/2] + nums2[(m+n)/2-1])/2.0;
            else median = nums2[(m+n)/2];
              
             return median;
        }
        
        

        return median;
    }
};
