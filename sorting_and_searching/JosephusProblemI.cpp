#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 0; i < n; i++){
        q.push(i+1);
    }
    for(int i = 0; i < n-1; i++){
        q.push(q.front());
        q.pop();
        cout << q.front() << ' ';
        q.pop();
    }
    cout << q.front() << '\n';
}