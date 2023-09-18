#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n, m ,k;
    cin >> n >> m >> k;
    vi v(n), ap(m);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < m; i++){
        cin >> ap[i];
    }
    sort(v.begin(), v.end());
    sort(ap.begin(), ap.end());
    int j = 0, res = 0;
    for(int i = 0; i < n; i++){
        while(j < m && ap[j] < v[i] - k) j++;
        if(j < m && ap[j] > v[i] + k) continue;
        if(j < m && ap[j] >= v[i] - k){
            res++;
            j++;
        }
    }
    cout << res << '\n';
}