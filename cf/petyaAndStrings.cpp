//https://codeforces.com/problemset/problem/112/A

#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    string s,t;
    cin>>s>>t;

    for(char&x:s)x|=32;    
    for(char&x:t)x|=32;

    if(s<t)cout<<"-1\n";
    else if(s>t)cout<<"1\n";
    else cout<<"0\n";
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