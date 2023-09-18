#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int x, n, p;
    cin >> x >> n;
    set<int> lights;
    multiset<int> lengths;
    lengths.insert(x);
    lights.insert(0);
    lights.insert(x);
    for(int i = 0; i < n; i++){
        cin >> p;
        lights.insert(p);
        auto beg = lights.find(p);
        auto end = beg;
        beg--;
        end++;
        lengths.erase(lengths.find(*end - *beg));
        lengths.insert(p - *beg);
        lengths.insert(*end - p);
        auto ans = lengths.end();
        ans--;
        cout << *ans << ' ';
    }
    cout << '\n';
}