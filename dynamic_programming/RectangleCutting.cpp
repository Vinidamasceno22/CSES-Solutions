#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int a, b;
    cin >> a >> b;
    vector<vi> dp(a + 1, vi(b + 1, -1));
    
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            int ans = 501;
            for(int k = 1; k < j; k++){
                ans = min(ans, dp[i][k] + dp[i][j - k] + 1);
            }
            for(int k = 1; k < i; k++){
                ans = min(ans, dp[k][j] + dp[i - k][j] + 1);
            }
            dp[i][j] = ans;
        }
    }
    cout << dp[a][b] << '\n';
}