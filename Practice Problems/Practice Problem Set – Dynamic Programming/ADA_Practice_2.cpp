#include<bits/stdc++.h>
using namespace std;
#define print(x) for(auto i: x) { cout << i << " "; }

vector<vector<int>> dp;

int func(int M, int n, vector<int>& position, vector<int> & revenue, vector<int> &dp, int index) {

    if(index >= n){
        return 0;
    }

    if(dp[index] != -1){

        return dp[index];
    }

    if(position[index+1] - position[index] > 5){
        return dp[index] = revenue[index] + func(M, n, position, revenue, dp, index+1);
    }else{

        return dp[index] = max(revenue[index] + func(M, n, position, revenue, dp, index+2), func(M, n, position, revenue, dp, index+1));
    }

}

int main() {

    int M, n; cin >> M >> n;
    
    vector<int> position(n), revenue(n);

    for(int i = 0; i < n; i++){
        cin >> position[i];
    }

    for(int i = 0; i < n; i++){
        cin >> revenue[i];
    }

    vector<int> dp(n + 1, 0);

    // cout << func(M, n, position, revenue, dp, 0) << endl;

    for(int index = n-1; index >=0; index--){

        if(position[index+1] - position[index] > 5){
            dp[index] = revenue[index] + dp[index+1];
        }else{

            dp[index] = max(revenue[index] +  dp[index+2], dp[index+1]);
        }
    }

    cout << dp[0] << endl;

    return 0;
}