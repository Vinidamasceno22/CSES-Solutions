#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int i = 0, j = n - 1, ans = 0;
    while(i <= j){
        if(v[i] + v[j] > x){
            j--;
            ans++;
        }
        else{
            i++;
            j--;
            ans++;
        }
    }
    cout << ans << '\n';
}