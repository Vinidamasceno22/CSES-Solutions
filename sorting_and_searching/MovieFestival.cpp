#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, a, b;
    cin >> n;
    vector<pair<int, int>> v(n);

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v[i] = {b, a};
    }

    sort(v.begin(), v.end());

    int t = 0, res = 0;
    for(int i = 0; i < n; i++){
        if(v[i].second >= t){
            t = v[i].first;
            res++;
        }
    }
    cout << res << '\n';
}