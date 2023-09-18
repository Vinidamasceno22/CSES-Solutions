#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll ans = 0, aux = 0;
    for(int i = 0; i < n; i++){
        aux += v[i];
        ans = max(ans, aux);
        if(aux < 0) aux = 0;
    }

    if(aux == 0){
        ans = v[0];
        for(int i = 1; i < n; i++){
            ans = max(ans, (ll) v[i]);
        }
    }

    cout << ans << '\n';
}