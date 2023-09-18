#include <bits/stdc++.h>

using namespace std;

int main(){
    int curr = 1, MAX = 1;
    string s;
    cin >> s;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1]){
            curr++;
        }
        else{
            curr = 1;
        }
        MAX = max(MAX, curr);
    }
    cout << MAX << '\n';
}