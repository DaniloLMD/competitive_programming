//https://codeforces.com/contest/546/problem/A
#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    int k,n,w;
    cin>>k>>n>>w;

    humberto tot = (w*(k+w*k))/2;
    cout<<max(0LL,tot-n)<<"\n";

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