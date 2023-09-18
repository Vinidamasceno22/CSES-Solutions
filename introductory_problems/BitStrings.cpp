#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    long long r = 1;
    for(int i = 0; i < n; i++){
        r = (r*2) % 1000000007;
    }
    cout << r << '\n';
}