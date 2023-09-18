#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll min = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        if(v[i] > min + 1) break;
        min = sum;
    }

    cout << min + 1 << '\n';
}