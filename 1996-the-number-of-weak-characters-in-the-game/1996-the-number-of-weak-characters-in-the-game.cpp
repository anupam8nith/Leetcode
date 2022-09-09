//best solution

class Solution {
public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    int maxAttack = 0;
    for (const auto& p : properties) {
      maxAttack = max(maxAttack, p[0]);
    }
    
    vector<int> maxDefenses (maxAttack + 2);
    for (const auto& p : properties) {
      int attack = p[0];
      int defense = p[1];
      maxDefenses[attack] = max(maxDefenses[attack], defense);
    }
    
    for (int i = maxDefenses.size() - 2; i >= 0; i--) {
      maxDefenses[i] = max(maxDefenses[i], maxDefenses[i+1]);
    }
    
    int weak = 0;
    for (const auto& p : properties) {
      int attack = p[0];
      int defense = p[1];
      if (maxDefenses[attack + 1] > defense)
        weak++;
    }
    
    return weak;
  }
};


/*
this is the comparator class function which sort Attacks in Ascending order and if attacks are duplicate then the 
character having lower defense value will be on upper than the greater like [[10,20 ][10,21]];
*/

// bool accToSecond(vector<int>&first, vector<int> &second) {
// 	if (first[0] == second[0]) return first[1] < second[1];
// 	return first[0] > second[0];
// }
// class Solution {
// public:
//     int numberOfWeakCharacters(vector<vector<int>>& properties) {
// 	sort(properties.begin(), properties.end(), accToSecond);
// 	stack<int> st;
// 	st.push(properties[0][1]);
// 	int n = properties.size();
// 	int ct = 0;
// 	for (int i = 1; i < n; i++) {
// 		int second =  properties[i][1];
// 		if (st.top() > second) ct++;
// 		if (st.top() < second) {
// 			/*as we handle the cases for the attacks now if anywhere defense is greater than
// 			the defense value at the top of stack which means we have new stronger character so we remove the previous one and
// 			push the new stronger one this makes the stack - Monotonic (i.e., top is stronger as much as it can )*/
// 			st.pop();
// 			st.push(second);//pushing the new character
// 		}
// 	}
// 	return ct;
//     }
// }; 


            //TLE but working bruteforce code

// long int n = properties.size();
//         if(n<=1)
//             return 0;
       
        
//        long int weak=0,j=0;
        
//         for(long int i=0;i<n;i++)
//         {
//                 for(j=0;j<n;j++)
//                 {
//                     if(properties[i][0]<properties[j][0]  &&  properties[i][1]<properties[j][1])
//                     {
//                         weak++;
//                         break;
//                     }
//                 }
//         }
        
//         return weak;


            //sorting and stack

// //sabse pehle ham properties ko sort karege incresing order me attack ke hisaab se
// //or jab attack same ho to defense ke hisaab se decreasing order me sort karege 

// //Sort karne se kya hoga ki attack ke hisaab se dekhne ki tension ab khatam ho gayi
// //ab ham sirf defense ke hisaab se dekhege

// //Ab yaha ham next greater to left waali strategy follow karege or jab ham smaller element pop kar
// //rahe honge defense ke hisaab se to counter bhi increase kar denge kyuki wo hi week character honge
// //or bo pop hote jaege saath hi saath to baar baar count bhi nahi honge


// bool comp(vector<int> &a, vector<int> &b)
// {
//     return (a[0] < b[0] || a[0] == b[0] && a[1] > b[1]);
// }

// class Solution {
// public:
    
//     int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
//         int n = properties.size();
//         stack<int> st;
//         int count = 0;
        
//         sort(properties.begin(), properties.end(), comp);
        
//         for(int i=0; i<n; i++)
//         {
//             while(!st.empty() && properties[st.top()][1] < properties[i][1])
//             {
//                 st.pop();
//                 count++;
//             }
            
//             st.push(i);
//         }
        
//         return count;
//     }
// };



//solution


// class Solution {
// public:
//     // the idea is to
//     // 1. rearrange the order of attack in ascending order and  that of defense in descending order 
//     // 2. count weak characters (those defenses less than the current maximum defense)
//     // 3. update the maximum defense
//     int numberOfWeakCharacters(vector<vector<int>>& p) {
//         // the final answer to be returned
//         int weakCharacters = 0;
//         // record maximum defense. since 1 <= defense_i <= 10 ^ 5
//         // we can set the init value to x where x < 1
//         int maxDefense = 0;
//         // sort properties with custom sort comparator
//         sort(p.begin(), p.end(), [](const vector<int>& x, const vector<int>& y) {
//             // if the attack is same, then sort defense in descending order  
//             // otherwise, sort attack in in ascending order 
//            return x[0] == y[0] ? x[1] < y[1] : x[0] > y[0];
//         });
//         for (auto& x : p) {
//             // x[1] is defense of properties[i]
//             // if it is less than current maxDefense, then it means it is a weak character
//             weakCharacters += x[1] < maxDefense;
//             // update maxDefense
//             maxDefense = max(maxDefense, x[1]);
//         }
//         return weakCharacters;
//     }
// };