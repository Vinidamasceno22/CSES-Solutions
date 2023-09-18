#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, k, ans = 0;
    cin >> n;
    multiset<int> s;
    for(int i = 0; i < n; i++){
        cin >> k;
        auto it = s.upper_bound(k);
        if(it == s.end()){
            s.insert(k);
        }
        else{
            s.erase(it);
            s.insert(k);
        }
    }
    cout << (int) s.size() << '\n';
}