// Brute Force Approach . 

// Time Complexity : O(n)
// Space Complexity : O(n)

// #include <iostream>
// #include<unordered_map>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     vector<int> repeatedNumber(const vector<int> &A) {

//       int n = A.size() ; 
//       vector<int>mpp(n + 1 , 0 ) ; 
      
//       vector<int>result ; 

//       int missingNum = -1 ; 
//       int repeatingNum = -1 ; 

//       for(int element : A)
//       {
//         mpp[element] ++ ; 
//       }

//       for(int i = 1 ; i <= n ; i ++)
//       {
//         if(mpp[i] == 0)
//         {
//             missingNum = i ; 
//         }
//         else if(mpp[i] == 2)
//         {
//             repeatingNum= i ; 
//         }        

//         if(missingNum != -1 &&  repeatingNum != -1 )
//         break ;

//       }

//       return { repeatingNum , missingNum} ; 


        
//     }
// };

// int main() {
//     Solution sol;

//     vector<int> input = {3, 1, 2, 5, 3};
//     vector<int> result = sol.repeatedNumber(input);

//     if (!result.empty()) {
//         cout << "[" << result[0] << ", " << result[1] << "]" << endl;
//     } else {
//         cout << "No result returned!" << endl;
//     }

//     return 0;
// }

// Optimized Approach . 
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> repeatedNumber(const vector<int> &A) {

      long long n = A.size() ; 

      long long SN = ( n * ( n + 1 )) / 2 ; 
      long long S2N = ( n * ( n + 1 ) * (2 * n + 1 )) / 6 ; 

      long long S = 0 ;
      long long S2 = 0 ; 

      for(long long ele : A)
      {
        S += ele ; 
        S2 += ele * ele ; 
      }

      long long diffOfXandY = S - SN ; 
      long long diffOfX2andY2 = S2 - S2N ; 

      long long addOfXandY = diffOfX2andY2 / diffOfXandY ; 

      long long x = (diffOfXandY + addOfXandY ) / 2 ; 
      long long y = (addOfXandY - diffOfXandY) / 2 ;

      return {(int) x , (int) y } ; 
      
        
    }
};

int main() {
    Solution sol;

    vector<int> input = {3, 1, 2, 5, 3};
    vector<int> result = sol.repeatedNumber(input);

    if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No result returned!" << endl;
    }

    return 0;
}
