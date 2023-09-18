#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, x;
    cin >> n >> x;
    vi v(n);
    vector<vi> m(n, vi(x+1, 0));
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        m[i][0] = 1;
    }
    for(int i = 1; i <= x; i++){
        if(i - v[0] >= 0) m[0][i] = m[0][i - v[0]];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= x; j++){
            m[i][j] = m[i-1][j] % 1000000007;
            if(j - v[i] >= 0) m[i][j] = (1ll * m[i][j] + m[i][j - v[i]]) % 1000000007;
        }
    }
    cout << m[n-1][x] << '\n';
}