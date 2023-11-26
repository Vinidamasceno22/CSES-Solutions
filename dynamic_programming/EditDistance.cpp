#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    string n, m;
    cin >> n >> m;
    vector<vi> dp(n.length() + 1, vi(m.length() + 1, -1));
    for(int i = 0; i <= n.length(); i++){
        dp[i][0] = i;
    }
    for(int j = 0; j <= m.length(); j++){
        dp[0][j] = j;
    }
    for(int i = 1; i <= n.length(); i++){
        for(int j = 1; j <= m.length(); j++){
            dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            if(n[i - 1] == m[j - 1]) dp[i][j] = dp[i - 1][j - 1];
        }
    }
    cout << dp[n.length()][m.length()] << '\n';
}