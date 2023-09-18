#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n;
    ll t = 0, ans = 0;
    cin >> n;
    vector<pair<int, int>>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        t += v[i].first;
        ans += v[i].second - t;
    }
    cout << ans << '\n';
}