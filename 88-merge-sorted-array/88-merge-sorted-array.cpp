class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    { 
        if(n==0)
            return;
        vector<int> ans(m+n);
        
        std:: merge(nums1.begin(),nums1.begin()+m, nums2.begin(), nums2.begin()+n, ans.begin());
    
        
        for(long i=0;i<ans.size();i++)
        nums1[i]=ans[i];
    }
};




//working code 1

// int i=m-1,j=n-1,k=m+n-1;
        
//         while(i>=0 && j>=0)
//         {
//             if(nums1[i]<nums2[j])
//                 nums1[k--]=nums2[j--];
//             else
//                 nums1[k--]=nums1[i--];
//         }
        
//         while(j>=0)
//             nums1[k--]=nums2[j--];



// code 2

// std::merge(nums1.rend() - m, nums1.rend(), 
//                nums2.rbegin(), nums2.rend(), nums1.rbegin(), std::greater<>());



//code 3


// // copy nums2 at the end of nums1's mth int
//         copy(nums2.begin(),nums2.end(),nums1.begin()+m);
//         // merge two sorted array inplace just like in merge sort
//         inplace_merge(nums1.begin(),nums1.begin()+m,nums1.end());