#include<bits/stdc++.h>
using namespace std;
#define print(x) for(auto i: x) { cout << i << " "; }

vector<vector<int>> dp;


int recursive(vector<int> &hotels, int n, int index, int dist, vector<vector<int>> &dp){

    if(index == n-1){

        return (250 - (hotels[index]-hotels[dist]))*(250 - (hotels[index]-hotels[dist]));
    }

    if(dp[index][dist] != -1){
        return dp[index][dist];
    }
    
    int case1 = (250 - (hotels[index]-hotels[dist]))*(250 - (hotels[index]-hotels[dist])) + recursive(hotels, n, index+1, index, dp);

    int case2 = recursive(hotels, n, index+1, dist, dp);

    return dp[index][dist] = min(case1, case2);
}

int tabular(vector<int> &hotels, int n, int index, int dist, vector<vector<int>> &dp){
    
    for(int i = n-1; i >= 0; i--){

        for(int j = n-1; j >= 0; j--){

            int case1 = (250 - (hotels[i]-hotels[j]))*(250 - (hotels[i]-hotels[j])) + dp[i+1][i];

            int case2 = dp[i+1][j];

            dp[i][j] = min(case1, case2);
        }
    }

    return dp[0][0];
}

int main() {

    int n; cin >> n;

    vector<int> hotels(n);

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i = 0; i < n; i++){

        cin >> hotels[i];

    }

    // int ans = recursive(hotels, n, 0, 0, dp);

    int ans = tabular(hotels, n, 0, 0, dp);
    
    cout << ans << endl;
    

    return 0;
}