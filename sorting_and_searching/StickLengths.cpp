#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int avg = v[n/2];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(v[i] - avg);
    }
    cout << ans << '\n';
}