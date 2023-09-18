#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, x;
    cin >> n;
    vector<int> v(n+1);
    v.assign(0,n);
    for(int i = 0; i < n - 1; i++){
        cin >> x;
        v[x]++;
    }
    for(int i = 1; i <= n; i++){
        if(v[i] == 0){
            cout << i << '\n';
            break;
        }
    }

}