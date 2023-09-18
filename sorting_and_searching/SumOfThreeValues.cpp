#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        int s = 0, r = n - 1;
        while(s < r){
            if(s == i){
                s++;
            }
            else if(r == i){
                r--;
            }
            else if(v[s].first + v[r].first + v[i].first < x){
                s++;
            }
            else if(v[s].first + v[r].first + v[i].first > x){
                r--;
            }
            else{
                cout << v[s].second << ' ' << v[i].second << ' ' << v[r].second << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}