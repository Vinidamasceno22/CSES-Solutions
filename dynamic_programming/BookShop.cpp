#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, x;
    cin >> n >> x;
    vi price(n + 1), pages(n + 1);
    vector<vi> dp(n + 1, vi(x + 1, 0));
    for(int i = 0; i < n; i++){
        cin >> price[i + 1];
    }
    for(int i = 0; i < n; i++){
        cin >> pages[i + 1];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            if(j - price[i] >= 0) dp[i][j] = max(dp[i - 1][j - price[i]] + pages[i], dp[i - 1][j]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][x] << '\n';
}