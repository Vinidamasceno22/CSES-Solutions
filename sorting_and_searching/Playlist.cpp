#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    set<int> s;
    vi v(n);
    int ans = 0, ini = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        if(s.find(v[i]) == s.end()){
            s.insert(v[i]);
        }
        else{
            ans = max(ans, (int) s.size());
            while(v[ini] != v[i]){
                s.erase(v[ini]);
                ini++;
            }
            ini++;

        }
    }
    ans = max(ans, (int) s.size());
    cout << ans << '\n';
}