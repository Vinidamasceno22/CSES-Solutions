#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, sum_up = 0, sum_down = 0;
    cin >> n;
    vector<int> v(n+1);
    for (long long i = 1; i <= n; i++){
        v[i] = i % 2;
        if(i%2){
            sum_up += i;
        }
        else {
            sum_down += i;
        }
    }
    if (abs(sum_up - sum_down) % 2){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        if(abs(sum_up - sum_down) % 4 == 2){
            v[n] = (v[n]+1) % 2;
            v[n - abs(sum_up - sum_down) / 2] = (v[n - abs(sum_up - sum_down) / 2] + 1) % 2;
        }
        else {
            v[1] = 0;
            v[n] = (v[n] + 1) % 2;
            if(n % 2 == 0){
                v[n - 1 - abs(sum_up - sum_down) / 2] = (v[n - 1 - abs(sum_up - sum_down) / 2] + 1) % 2;                
            }
            else{
                v[n + 1 - abs(sum_up - sum_down) / 2] = (v[n + 1 - abs(sum_up - sum_down) / 2] + 1) % 2;
            }
        }
        sum_up = 0;
        sum_down = 0;
        for(int i = 1; i <= n; i++){
            if(v[i] == 1){
                sum_up++;
            }
            else{
                sum_down++;
            }
        }
        cout << sum_up << '\n';
        for(int i = 1; i <=n; i++){
            if(v[i]){
                cout << i << ' ';
            }
        }
        cout << '\n' << sum_down << '\n';
        for(int i = 1; i <= n; i++){
            if(v[i] == 0){
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
}