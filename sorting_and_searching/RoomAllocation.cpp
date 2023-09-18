#include<bits/stdc++.h>

#define INF 1000000000 + 10
#define ll long long
#define vi vector<int>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> v(n);
    for(int i = 0; i < n; i++){
        pair<int, int> p;
        cin >> p.second >> p.first;
        v[i] = {p, i};
    }

    sort(v.begin(), v.end());

    vi ans(n);
    int nr = 0;
    set<pair<int, int>, decltype(&cmp)> s(&cmp);
    for(int i = 0; i < n; i++){
        s.insert({0, i});
    }
    for(int i = 0; i < n; i++){
        auto it = s.lower_bound({v[i].first.second, INF});
        it--;
        int r = it->second;
        nr = max(nr, r + 1);
        ans[v[i].second] = r + 1;
        s.erase(it);
        s.insert({v[i].first.first, r});
    }
    cout << nr << '\n';
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';

}