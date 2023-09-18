#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, h;
    cin >> n;
    ll MAX = 0;
    stack<pair<int, int>> s;
    for(int i = 0; i < n; i ++){
        cin >> h;
        int j = i;
        while(!s.empty() && s.top().first > h){
            MAX = max(MAX, (ll) (i - s.top().second) * s.top().first);
            j = s.top().second;
            s.pop();
        }
        s.push({h, j});
    }

    while(!s.empty()){
        MAX = max(MAX, (ll) (n - s.top().second) * s.top().first);
        s.pop();
    }
    
    cout << MAX << '\n';
}