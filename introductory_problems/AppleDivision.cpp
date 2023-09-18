#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vii vector<vi>

using namespace std;

ll diff(const vi &v, ll sum, int i, const int &n, const ll &tot){
    if(i == n){
        return abs(tot - 2 * sum);
    }

    return min(diff(v, sum + v[i], i + 1, n, tot), diff(v, sum, i + 1, n, tot));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n;
    cin >> n;
    vi v(n);
    ll s = 0;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        s += v[i];
    }
    cout << diff(v, 0, 0, n, s) << '\n';
}