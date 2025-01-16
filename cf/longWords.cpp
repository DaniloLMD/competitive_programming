//https://codeforces.com/problemset/problem/71/A
#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    string s;
    cin>>s;
    if(s.size()<=10){
        cout<<s<<"\n";
        return;
    }
    cout<<s[0]<<s.size()-2<<s.back()<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}