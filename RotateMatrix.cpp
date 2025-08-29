// Time Complexity : O( n * n )
// Space Complexity : O(1)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ; 

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int m = matrix.size() ;
        int n = matrix[0].size() ; 

        for(int i = 0 ; i < m ; i ++ )
        {
            for(int j = i ; j < n ; j ++ )
            {
                    swap(matrix[i][j] , matrix[j][i]) ;  
                
            }
        }

    
    for(vector<int>& vec : matrix)
    {
        reverse(vec.begin() , vec.end()) ; 
    }
}
};
int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    for(auto row : matrix) {
        for(auto val : row) cout << val << " ";
        cout << "\n";
    }

    sol.rotate(matrix);

    cout << "\nRotated Matrix:\n";
    for(auto row : matrix) {
        for(auto val : row) cout << val << " ";
        cout << "\n";
    }

    return 0;
}