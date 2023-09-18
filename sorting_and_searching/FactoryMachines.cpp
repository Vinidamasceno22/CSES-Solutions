#include<bits/stdc++.h>

#define INF 1e18 + 10
#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, t;
    ll MAX = INF;
    cin >> n >> t;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        MAX = min(MAX, (ll) v[i] * t);
    }
    ll ini = 0, fim = MAX, m = (ini + fim) / 2;
    while(ini < fim){
        ll aux = 0;
        for(int i = 0; i < n; i++){
            aux += m / v[i];
        }
        if(aux >= t){
            fim = m;
        }
        else{
            ini = m + 1;
        }
        m = (ini + fim) / 2;
    }
    cout << m << '\n';
}