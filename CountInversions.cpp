// Brute Force Approach : 
// Time Complexity : O(n*n) 
// Space Complexity : O(1) ; 

// #include <bits/stdc++.h>
// using namespace std;

// long long getInversions(long long *arr, int n){
  
//     long long count = 0 ; 

//     for(long long i = 0 ; i < n ; i ++ )
//     {
//         int element = *(arr + i ) ;
//         for(long long j = i + 1 ; j < n ; j ++ )
//         {
//             if(element > *(arr + j ))
//             {
//                 count ++ ;
//             }
//         }
//     }

//     return count ; 

// }

// int main() {
//     int n;
//     cout << "Enter size of array: ";
//     cin >> n;

//     long long *arr = new long long[n];
//     cout << "Enter " << n << " elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     long long result = getInversions(arr, n);
//     cout << "Number of inversions: " << result << endl;

//     delete[] arr; 
//     return 0;
// }


// Optimal Solution : 
// Time Complexity : O(n*logn)


#include <bits/stdc++.h>
using namespace std;

long long cnt = 0 ; 

void merge(vector<long long>&vec , long long low , long long mid , long long high )
{
    long long n1 = mid - low + 1 ; 
    long long n2 = high - mid ; 


    vector<long long> L(n1) , R(n2) ; 

    for(long long i = 0 ; i < n1 ; i ++)
    L[i] = vec[i+low] ; 

    for(long long i = 0 ; i < n2 ; i ++ )
    R[i] = vec[i+mid+1] ; 

    long long k = low ; 
    long long i = 0 ; 
    long long j = 0 ; 

    while( i < n1 && j < n2 )
    {
       if(L[i] <= R[j])
       {
        vec[k++] = L[i++] ; 
       }

       else 
       {
        cnt += (n1 - i ) ;
        vec[k++] = R[j++] ; 
       }
    }

    while(i < n1)
      vec[k++] = L[i++] ; 

    while(j < n2)
      vec[k++] = R[j++] ;    

}

void mergeSort(vector<long long>&vec , long long low , long long high)
{
    if(low > high)
        return ; 
    

    long long mid = low + ( high - low ) / 2 ; 

    mergeSort(vec , low , mid ) ;
    mergeSort(vec , mid + 1 , high )  ;
    merge(vec , low , mid , high) ; 


}

long long getInversions(long long *arr, long long n){
  
  vector<long long> vec(arr, arr + n); 

  mergeSort(vec , 0 , n - 1 ) ; 
    
  return cnt ; 

}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    long long *arr = new long long[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long result = getInversions(arr, n);
    cout << "Number of inversions: " << result << endl;

    delete[] arr; 
    return 0;
}
