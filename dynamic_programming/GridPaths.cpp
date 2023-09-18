#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int paths(const vector<vector<char>> &m, vector<vi> &dp, int i, int j, int n){
    if(m[i][j] == '*') return dp[i][j] = 0;
    if(i == n - 1 && j == n - 1) return dp[i][j] = 1;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if(i + 1 < n) ans = paths(m, dp, i + 1, j, n);
    if(j + 1 < n) ans = (1ll* ans + paths(m, dp, i, j + 1, n)) % 1000000007;
    return dp[i][j] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> m(n, vector<char>(n));
    vector<vi> dp(n, vi(n, -1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }
    cout << paths(m, dp, 0, 0, n) << '\n';
}