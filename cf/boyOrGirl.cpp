//https://codeforces.com/problemset/problem/236/A
#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    string s;
    cin>>s;
    set<char>st;
    for(auto x:s)st.insert(x);
    if(st.size()&1)cout<<"IGNORE HIM!\n";
    else cout<<"CHAT WITH HER!\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}