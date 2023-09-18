#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n, x, a;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> a;
        v[i] = {a, i + 1};
    }
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    while(i < j){
        if(v[i].first + v[j].first > x) j--;
        else if(v[i].first + v[j].first < x) i++;
        else break;
    }
    if(i < j){
        cout << v[i].second << ' ' << v[j].second;
    }
    else{
        cout << "IMPOSSIBLE";
    }
    cout << '\n';
}