//https://codeforces.com/problemset/problem/231/A
#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    int n;
    cin>>n;
    
    int ans=0;
    for(int j=0;j<n;j++){
        int x=0;
        for(int i=0;i<3;i++){
            int a;
            cin>>a;
            x+=a;
        }
        if(x>1)ans++;
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