#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> v(2 * n);
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v[2 * i] = {a, 1};
        v[2 * i + 1] = {b, -1};
    }
    sort(v.begin(), v.end());
    int ans = 0, aux = 0;
    for(int i = 0; i < 2 * n; i++){
        aux += v[i].second;
        ans = max(ans, aux);
    }
    cout << ans << '\n';
}   