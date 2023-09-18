#include <bits/stdc++.h>

using namespace std;

int main(){
    int ans = 0;
    long long n, x;
    cin >> n;
    x = 5;
    while(x <= n){
        ans += n / x;
        x *= 5;
    }
    cout << ans << '\n';
    

}