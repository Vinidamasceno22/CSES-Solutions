#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, x;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> x;
        v[x - 1] = i + 1;
    }
    int ans = 1;
    for(int i = n - 2; i >= 0; i--){
        if(v[i] > v[i + 1]){
            ans++;
        }
    }
    cout << ans << '\n';
}