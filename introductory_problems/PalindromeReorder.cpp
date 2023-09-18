#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> v(26, 0);
    int odd = 0, pos = 0;
    for(int i = 0; i < s.size(); i++){
        v[s[i] - 'A']++;
    }
    for(int i = 0; i < 26; i++){
        if(v[i] % 2){
            odd++;
        }
        for(int j = pos; j < pos + v[i] / 2; j++){
            s[j] = i + 'A';
            s[s.size() - j - 1] = i + 'A';
        }
        pos += v[i] / 2;
        v[i] = v[i] % 2;
    }
    if(odd >= 2){
        cout << "NO SOLUTION\n";
    }
    else{
        for(int i = 0; i < 26; i++){
            if(v[i]){
                s[s.size()/2] = i + 'A';
            }
        }
        cout << s << '\n';
    }

}