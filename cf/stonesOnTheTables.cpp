//https://codeforces.com/problemset/problem/266/A
#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    int n;
    string s;
    cin>>n>>s;

    int ans=0;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            string t;
            for(int j=0;j<s.size();j++){
                if(j==i)continue;
                t.push_back(s[j]);
            }
            ans++;
            swap(s,t);
            i=-1;
            continue;
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