class Solution {
public:
     // worst solution code works for n<21
    
//     long int fact(int a)
//     {
//        
// //         if(a==0 || a==1)
// //             return 1;
        
//             long int ans=1;
//             for(int i=1;i<=a;i++)
//                 ans*=i;
            
//         return ans;
//     }
    
//     vector<int> getRow(int rowIndex) 
//     {
//         int n= rowIndex;
//         vector<int> ans(n+1);
        
        
        
//             if(n==0)
//             {
//                 ans[0]=1;
                
//                 return ans;
//             }
        
//         long int n1=fact(n),n2=1,n3=1;
       
        
        
        
//         ans[0]=1;
//         ans[1]=n;
//         ans[n-1]=n;
//         ans[n]=1;
        
//         for(int i=2;i<n-1;i++)
//         {
//             n2 = fact(i) * fact(n-i);
//             n3 = n1/n2;
//            ans[i]= (int) n3;
//         }
        
//         return ans;
     vector<int> getRow(int rowIndex) 
     {
         
    vector<int> A(rowIndex+1, 0);
        A[0] = 1;
        for(int i=1; i<rowIndex+1; i++)
            for(int j=i; j>=1; j--)
                A[j] += A[j-1];
        return A;
    
    
        
    }
};