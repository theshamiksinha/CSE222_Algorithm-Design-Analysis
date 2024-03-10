#include<bits/stdc++.h>
using namespace std;
#define print(x) for(auto i: x) { cout << i << " "; }

vector<vector<int>> dp;

int func(int song, vector<int>& score, vector<int> &wait, vector<int> &dp, int index) {

    if(index >= song){
        return 0;
    }

    if(dp[index] != -1){

        return dp[index];
    }

    int case1 = score[index] + func(song, score, wait, dp, (index + 1 + wait[index]));

    int case2 = func(song, score, wait, dp, index+1);

    return  dp[index] = max(case1, case2);

}

int main() {

    int songs; cin >> songs;
    
    vector<int> score(songs), wait(songs);

    for(int i = 0; i < songs; i++){
        cin >> score[i];
    }

    for(int i = 0; i < songs; i++){
        cin >> wait[i];
    }

    int n = score.size();
    vector<int> dp(n + 1, 0); // Initialize the table with 0

    for (int index = n-1; index >=0 ; index--) {

        int case1 = score[index]; 
        if( index + 1 + wait[index] < n){
            case1 += dp[index + 1 + wait[index]]; 
        }
        int case2 = dp[index + 1]; 
        dp[index] = max(case1, case2);
        
    }
 
    cout << dp[0] << endl;

    return 0;
}