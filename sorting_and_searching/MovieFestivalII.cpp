#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n, k, a, b;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    multiset<int> t;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v[i] = {b, a};
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < k; i++){
        t.insert(0);
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        auto it = t.upper_bound(v[i].second);
        if(it != t.begin()){
            it--;
            t.erase(it);
            t.insert(v[i].first);
            res++;
        }
    }

    cout << res << '\n';
}