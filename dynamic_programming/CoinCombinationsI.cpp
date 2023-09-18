#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, x;
    cin >> n >> x;
    vi v(n);
    vector<ll> ans(x + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    ans[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - v[j] >= 0) ans[i] = (ans[i] + ans[i - v[j]]) % 1000000007;
        }
    }
    cout << ans[x] << '\n';
    
}