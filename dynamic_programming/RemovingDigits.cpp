#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int remove(vi &v, int n){
    if(v[n] != -1) return v[n];
    vi digits;
    int aux = n, count = 0;
    while(aux > 0){
        digits.push_back(aux - (aux / 10) * 10);
        aux /= 10;
        count++;
    }
    int ans = 1000000;
    for(int i = 0; i < count; i++){
        if(digits[i] != 0) ans = min(ans, remove(v, n - digits[i]));
    }
    return v[n] = ans + 1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vi v(n + 1, -1);
    v[0] = 0;
    cout << remove(v, n) << '\n';
}