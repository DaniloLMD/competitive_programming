#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    system("ls > ola");

    ifstream file;
    file.open("ola");
    string s;

    int cnt=-1;
    while(file){
        getline(file,s);
        if(s.find(".cpp")<s.size()){
            cnt++;
        }
    }

    dbg(cnt);
    system("rm ola");   
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