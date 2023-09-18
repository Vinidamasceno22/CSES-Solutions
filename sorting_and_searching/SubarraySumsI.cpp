#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, x, ans = 0;
    cin >> n >> x;
    vector<ll> v(n+1);
    v[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        v[i] += v[i - 1];
    }
    
    int r = 0, s = 1;
    while(r <= n && s <= n){
        if(v[s] - v[r] == x){
            ans++;
            r++;
            s++;
        }
        else if(v[s] - v[r] > x) r++;
        else s++;
    }
    cout << ans << '\n';
    
}