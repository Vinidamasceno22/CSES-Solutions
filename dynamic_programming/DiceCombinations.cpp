#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vi v(1000001, 0);
    v[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            v[i] += v[i - j];
            v[i] %= 1000000007;
            if(i - j == 0) break;
        }
    }
    cout << v[n] << '\n';
}