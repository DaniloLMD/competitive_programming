//https://codeforces.com/problemset/problem/282/A
#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    int n;
    cin>>n;
    int ans = 0;  
    while(n--){
        string s;
        cin >> s;
        for(auto x: s){
            if(x=='+'){
                ans++;
                break;
            }
            if(x=='-'){
                ans--;
                break;
            }
        }
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