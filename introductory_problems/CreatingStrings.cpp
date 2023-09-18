#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vii vector<vi>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    string s;
    cin >> s;
    int n = s.length();
    vi v(26, 0);
    vector<string> strings;

    for(int i = 0; i < n; i++){
        v[s[i] - 'a']++;
    }

    int j = 0;
    for(int i = 0; i < 26; i++){
        while(v[i] > 0){
            s[j] = i + 'a';
            j++;
            v[i]--;
        }
    }

    ll res = 1;
    strings.push_back(s);

    while(next_permutation(s.begin(), s.end())){
        res++;
        strings.push_back(s);
    }

    cout << res << '\n';
    
    for(ll i = 0; i < res; i++){
        for(int j = 0; j < n; j++){
            cout << strings[i][j];
        }
        cout << '\n';
    }

    
}