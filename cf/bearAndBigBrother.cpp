//https://codeforces.com/problemset/problem/791/A
#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    humberto a,b;
    cin>>a>>b;

    humberto ans=0;
    while(a<=b){
        a*=3;
        b*=2;
        ans++;
    }
    cout<<ans<<"\n";
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