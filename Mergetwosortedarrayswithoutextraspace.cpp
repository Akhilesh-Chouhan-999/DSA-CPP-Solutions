// Brute Force 
// Time Complexity : O ( m + n)
// Space Complexity : O(m + n )
// #include <iostream>
// #include <vector>
// using namespace std;

// class Solution {
// public:
     
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
//         vector<int>result(m + n) ; 

//         int i = 0 ; 
//         int j = 0 ; 
//         int k = 0 ; 

//         while (i < m && j < n )
//         {
//             if(nums1[i] <= nums2[j])
//             {
//                 result[k++] = nums1[i++] ; 
//             }
//             else
//             {
//                 result[k++] = nums2[j++] ; 
//             }
//         }

//         while( i < m )
//         {
//             result[k++] = nums1[i++] ;
//         }

//         while(j < n )
//         {
//             result[k++] = nums2[j++] ; 
//         }


//        nums1 = result ; 
        
//     }
// };

// int main() {
//     Solution sol;

//     // Example input
//     vector<int> nums1 = {1,2,3,0,0,0}; // nums1 has extra space for nums2
//     int m = 3; // number of valid elements in nums1

//     vector<int> nums2 = {2,5,6};
//     int n = 3; // number of elements in nums2

//     cout << "Before merge:\nnums1: ";
//     for(int x : nums1) cout << x << " ";
//     cout << "\nnums2: ";
//     for(int x : nums2) cout << x << " ";
//     cout << "\n";

//     // Call merge (logic not yet implemented)
//     sol.merge(nums1, m, nums2, n);

//     cout << "\nAfter merge:\nnums1: ";
//     for(int x : nums1) cout << x << " ";
//     cout << "\n";

//     return 0;
// }

// Brute Force 
// Time Complexity : O ( m + n)
// Space Complexity : O(1)
// Trick : Think backward shifting and arranging in the descending order . 


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int idx = m + n -1  ; 

        int i = m - 1 ; 
        int j = n - 1  ; 
        while( i >= 0 && j >= 0 )
        {
            if(nums1[i] >= nums2[j])
            {
                nums1[idx--] = nums1[i--] ;
            }

            else 
            {
                nums1[idx--] = nums2[j--] ; 
            }
        }

      

        while( j >= 0 )
        {
            nums1[idx--] = nums2[j--] ; 
        }
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums1 = {1,2,3,0,0,0}; // nums1 has extra space for nums2
    int m = 3; // number of valid elements in nums1

    vector<int> nums2 = {2,5,6};
    int n = 3; // number of elements in nums2

    cout << "Before merge:\nnums1: ";
    for(int x : nums1) cout << x << " ";
    cout << "\nnums2: ";
    for(int x : nums2) cout << x << " ";
    cout << "\n";

    // Call merge (logic not yet implemented)
    sol.merge(nums1, m, nums2, n);

    cout << "\nAfter merge:\nnums1: ";
    for(int x : nums1) cout << x << " ";
    cout << "\n";

    return 0;
}
