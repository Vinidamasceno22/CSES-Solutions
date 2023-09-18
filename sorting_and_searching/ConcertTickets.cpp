#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n, m, x;
    cin >> n >> m;
    multiset<int> tickets;
    for(int i = 0; i < n; i++){
        cin >> x;
        tickets.insert(x);
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        auto it = tickets.upper_bound(x);
        if(it == tickets.begin()) cout << -1 << '\n';
        else {
            cout << *(--it) << '\n';
            tickets.erase(it);
        }
    }
}