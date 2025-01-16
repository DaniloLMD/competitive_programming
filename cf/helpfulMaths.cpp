//https://codeforces.com/problemset/problem/339/A

#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    vector<int>v;
    int x;
    while(cin>>x){
        v.push_back(x);
    }
    sort(all(v));
    for(int i=0;i<v.size();i++){
        cout<<v[i];
        if(i+1!=v.size())cout<<"+";
    }
    cout<<"\n";
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