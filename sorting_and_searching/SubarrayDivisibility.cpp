#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, x;
    ll ans = 0;
    cin >> n;
    vector<ll> v(n+1), m(n, 0);
    v[0] = 0;
    m[0]++;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        v[i] = ((v[i] + v[i - 1]) % n + n) % n;
        ans += m[v[i]];
        m[v[i]]++;
    }
    cout << ans << '\n';
    
}