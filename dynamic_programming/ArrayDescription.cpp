#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define mod 1000000007

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    vi v(n);
    vector<vi> dp(n, vi(m+2, 0));
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    if(v[0] == 0){
        for(int i = 1; i <= m; i++){
            dp[0][i] = 1;
        }
    }
    else{
        dp[0][v[0]] = 1;
    }
    
    for(int i = 1; i < n; i++){
        if(v[i] == 0){
            for(int j = 1; j <= m; j++){
                dp[i][j] = (1ll * dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % mod;
            }
        }
        else{
            dp[i][v[i]] = (1ll * dp[i-1][v[i]-1] + dp[i-1][v[i]] + dp[i-1][v[i]+1]) % mod;
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans += dp[n-1][i];
        ans %= mod;
    }
    cout << ans << '\n';
    
}