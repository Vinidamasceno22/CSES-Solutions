#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, x;
    ll ans = 0;
    cin >> n >> x;
    vector<ll> v(n+1);
    unordered_map<ll, ll> m;
    v[0] = 0;
    m[0]++;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        v[i] += v[i - 1];
        if(m.find(v[i] - x) != m.end()){
            ans += m[v[i] - x];
        }
        m[v[i]]++;
    }
    cout << ans << '\n';
    
}