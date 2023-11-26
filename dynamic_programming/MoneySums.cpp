#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vi coins(n);
    vector<vi> dp(n + 1, vi(100001, 0));
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    
    for(int i = 0; i <= n; i++) dp[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 100000; j++){
            dp[i][j] = dp[i - 1][j];
            if(coins[i - 1] <= j){
                dp[i][j] = dp[i][j] || dp[i - 1][j - coins[i - 1]];
            }
        }
    }

    int ans = 0;
    vi sums;
    for(int j = 1; j <= 100000; j++){
        for(int i = 1; i <= n; i++){
            if(dp[i][j] == 1){
                ans++;
                sums.push_back(j);
                break;
            }
        }
    }

    cout << ans << '\n';
    for(int i = 0; i < ans; i++){
        cout << sums[i] << ' ';
    }
    cout << '\n';

}