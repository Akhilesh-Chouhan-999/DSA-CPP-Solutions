// Time Complexity : O(nlogn)

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size() ; 

        sort(intervals.begin() , intervals.end()) ;

        vector<vector<int>>result  ; 

        for(int i = 0 ; i < n ; i ++ )
        {
            int start = intervals[i][0] ; 
            int end = intervals[i][1] ; 

            // 1. Merging Step . 
            if(!result.empty() && start <= result.back()[1] )
            {
                result.back()[1] = max(result.back()[1] , end ) ; 
            }

            // 2. Insertion in result
            else
            {
                result.push_back({start , end}) ;
            }


        }

        return result ; 
        
    }
};

int main() {
    Solution sol;

    // Example input intervals
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    cout << "Original Intervals:\n";
    for(auto v : intervals) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << "\n";

    // Call merge function
    vector<vector<int>> result = sol.merge(intervals);

    cout << "\nMerged Intervals:\n";
    for(auto v : result) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << "\n";

    return 0;
}
