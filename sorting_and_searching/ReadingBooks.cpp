#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n, x, MAX = 0;
    ll sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        sum += x;
        MAX = max(MAX, x);
    }
    cout << (MAX > sum - MAX ?  2 * 1ll * MAX : sum) << '\n';




}