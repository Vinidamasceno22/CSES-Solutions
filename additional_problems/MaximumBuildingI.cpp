#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vii vector<vi>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    char c;
    vi k(m, 0);
    stack<pair<int ,int>> s;
    ll MAX = 0;

    for(int i = 1; i < n + 1; i++){
        for(int j = 0; j < m; j++){
            cin >> c;
            if(c == '*'){
                k[j] = 0;
            }
            else{
                k[j] += 1;
            }
        
            int l = j;
            while(!s.empty() && s.top().first > k[j]){
                MAX = max(MAX, (ll) (j - s.top().second) * s.top().first);
                l = s.top().second;
                s.pop();
            }
            s.push({k[j], l});
        }

        while(!s.empty()){
            MAX = max(MAX, (ll) (m - s.top().second) * s.top().first);
            s.pop();
        }
    }
    cout << MAX << '\n';
}