// Brute Force : 
// Time Complexity : O(n)
// Space Complexity : O(n)

// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std ; 

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
        
//        unordered_map<int , int>mpp ;  

//        for(int num : nums)
//        {

//         if(++mpp[num] > 1)
//         {
//             return num ; 
//         }

//        }

//        return -1 ; 
//     }
// };


// int main() {
//     Solution sol;
//     vector<int> nums = {1, 3, 4, 2, 2}; 

//     cout << sol.findDuplicate(nums) << endl;

//     return 0;
// }

// Better Approach : Binary Search Approach { Range Based Approach }
// Time Complexity : O(nlogn)
// Space Complexity : O(1)

#include<iostream>
#include<vector>
using namespace std ; 


class Solution {
public:


int countLessThanMid(vector<int>&nums , int mid)
{
  int cnt = 0 ;
  for(int num : nums)
  {
    if(num <= mid)
    cnt ++ ; 
  }

  return cnt ; 
}
    int findDuplicate(vector<int>& nums) {

     int n = nums.size() ; 
     int low = 1 ; 
     int high = n - 1  ; 


     while(low <= high)
     {
       int mid = low + ( high - low ) / 2 ; 

       int count = countLessThanMid(nums , mid ) ;

       if(count > mid)
       {
          high = mid - 1; 
       }
       else
       {
        low = mid + 1 ; 
       }
     }

     return low ; 

    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2}; 

    cout << sol.findDuplicate(nums) << endl;

    return 0;
}



// Optimized Approach : 
// { Hare and Tortoise Approach  or Floyds Cycle } 
// Think of indices as nodes and values as pointers to next nodes .
// Time Complexity : O(n)
// Space Complexity : O(1)

// #include<iostream>
// #include<vector>
// using namespace std ; 

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
        
//       int slow = nums[0] ; 
//       int fast = nums[0] ; 

      
//       do {
//          slow = nums[slow] ;
//          fast = nums[nums[fast]] ;  
//       } while (slow != fast) ; 

//       fast = nums[0] ; 

//       while(slow != fast)
//       {
//          slow = nums[slow] ; 
//          fast = nums[fast] ; 
//       }

//       return slow  ;

//     }
// };


// int main() {
//     Solution sol;
//     vector<int> nums = {1, 3, 4, 2, 2}; 

//     cout << sol.findDuplicate(nums) << endl;

//     return 0;
// }