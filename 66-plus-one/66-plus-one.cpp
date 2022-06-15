class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int n = digits.size(),j=0;
        
    if(digits.at(n-1)==9)
    {
        if(n==1)
        {
            digits.pop_back();
            digits.push_back(1);
            digits.push_back(0);
            
            return digits;
        }
        else
        {
            int k;
                for(k=n-1;k>=0;k--)
                {
                  if(digits.at(k) + 1 >= 10)
                    {
                      digits.at(k)=0;
                    }
                    else
                    {
                       digits.at(k)++;
                        break;
                    }
                }
            
            
            if(digits.at(0)==0)
                digits.insert(digits.begin(), 1);
            
            return digits;
        }
    }
         
    else
    {
        for(auto i:digits)
        {
            if(j==n-1)
            {
                digits.pop_back();
                digits.push_back(i+1);
            }
                
               j++;
        }
    }
        
        
        return digits;
        
    }
};




//

// if(digits.at(n-1)==9)
//      {
//          for(int k=0;k<n;k++)
//          sum= sum*10 + digits.at(k);
         
//          sum++;
         
//          digits.clear();

//                  for(int k=0;k<=n;k++)
//                  {
//                      temp=sum%10;

//                      digits.push_back(temp);
//                      sum/=10;
//                  }
             
//              reverse(digits.begin(), digits.end());
            
        
//                  if(digits.at(0)==0)
//                 digits.erase(digits.begin());
         
//                  return digits;
//          }
             
         
     
  
//     else
//     {
//         for(auto i:digits)
//         {
//             if(j==n-1)
//             {
//                 digits.pop_back();
//                 digits.push_back(i+1);
//             }
                
//                j++;
//         }
//     }
        
        
//         return digits;