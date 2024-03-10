#include<bits/stdc++.h>
using namespace std;
#define print(x) for(auto i: x) { cout << i << " "; }


int recursive(vector<int> &arr, int n, int index, int prev, vector<vector<int>> &dp){

    if(index >= n){

        return 0;
    }

    int case1;
    int case2;

    if(arr[prev] % 2 ==0){
        
        if(arr[index] < arr[prev]){

            case1 = 1 + recursive(arr, n, index+1, index, dp);
            case2 = recursive(arr, n, index+1, index, dp);
            return max(case1, case2);

        }else{
            return recursive(arr, n, index+1,prev, dp);
        }
    
    }else{
        
        if(arr[index] > arr[prev]){

            case1 = 1 + recursive(arr, n, index+1,index, dp);
            case2 = recursive(arr, n, index+1,prev, dp);

            return max(case1, case2);
        }else{
            return recursive(arr, n, index+1,prev, dp);
        }
    
    }
}

int main() {

    int n; cin >> n;

    vector<pair<int, int>> arr(n);

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i = 0; i < n; i++){

        cin >> arr[i].first;

        arr[i].second = i+1;

    }

    sort(arr.begin(), arr.end());

    vector<int> arrr(n);

    for(int i = 0; i < n; i++){
        arrr[i] = arr[i].second;
    }

    cout <<  recursive(arrr, n, 0, -1 ,dp) << endl;
    
   

    return 0;
}