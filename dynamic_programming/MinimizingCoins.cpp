#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, x;
    cin >> n >> x;
    vi v(n);
    vector<vi> m(n, vi(x+1, -1));
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        m[i][0] = 0;
    }
    for(int i = 1; i <= x; i++){
        if(i - v[0] >= 0 && m[0][i - v[0]] != -1) m[0][i] = m[0][i - v[0]] + 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= x; j++){
            m[i][j] = m[i-1][j];
            if(j - v[i] >= 0 && m[i][j - v[i]] != -1){
                if(m[i][j] == -1) m[i][j] = m[i][j - v[i]] + 1;
                else m[i][j] = min(m[i][j], m[i][j - v[i]] + 1);
            }
        }
    }
    cout << m[n-1][x] << '\n';
}