/*
Sparse Table: 

Dado uma range [L,R], podemos escrever ela como uniao
de ranges cujos tamanhos são potências de 2, de forma 
decrescente. Logo, terão no máximo log2 ranges.
Ex: [2,7] = [2,5] U [6,7]
    tam6    tam4    tam2

A sparse table será basicamente uma dp: st[K][N], em que
st[i][j] representa o range começando em j e cujo tamanho
é 2^i, ou seja, o range [j, j + 2^i - 1]

Essa estrutura da DP foi escolhida nessa ordem para
acelerar o processo via cache.
 
Caso base: st[0][j] = v[j] (Range de tamanho 1)

Transição:
st[i][j] = [j, j + 2^i - 1]
= [j, j + 2^(i-1) - 1]U[j+2^(i-1), j+2^(i-1) + 2^(i-1) -1] 
                        ^ X = j+2^(i-1) -> o segundo é [X, X+2^(j-1)-1]
= st[i-1][j] U st[i-1][j+2^(i-1)]


--- Usando a DP para recuperar o valor de uma range [L,R] em O(log(T)) ---
Tamanho da range: T = L - R + 1
Iterando nas potencias de 2 de forma decrescente, se P=2^i <= T, podemos
saltar P posicoes para frente, ou seja:
Ans = merge(Ans, st[i][L])    (no caso da soma: Ans = Ans + st[i][L])
L = L + 2^i  (Pulando 2^i posicoes pra frente)

--- Query O(1) para Funcoes Idempotentes ---
Uma função é idempotente se processando elementos repetidos, o valor de retorno não se altera (max, min).
Iremos usar isso para dividir a range [L,R] em apenas duas novas ranges, ambas de tamanhos potencias de 2.

Query(L,R) = merge(st[K][L], st[K][R+1-2^K])
em que K é o maior inteiro tal que 2^K <= R-L+1, ou seja,
K é a maior potência de 2 que é menor do que o tamanho do conjunto, ou seja,
K = log2(R-L+1);

Pre-calculando o valor de K para todo tamanho possivel:
K[1] = 0
for(int t=1; t<= N; t++)
    K[t] = K[t/2] + 1
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define dbg(x) cout << #x << " = " << x << endl;
#define all(v) v.begin(), v.end()

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+50;
const int K = 25;//log(N)

ll st[K][N];
int v[N];
int logs[N];
ll NULO = LLONG_MAX;

ll merge(ll x, ll y){
    return min(x,y);
}

void precalc(){
    //precalculando os log2 de todo tamanho para a query O(1)
    logs[1]=0;
    for(int i=2;i<N;i++){
        logs[i]=logs[i/2]+1;
    }

    for(int i=0;i<K;i++){
        for(int j=1;j<N;j++){
            if(!i){
                st[i][j]=v[j];
                continue;
            }
            int j2=j+(1<<(i-1));
            if(j2>=N)continue;
            st[i][j]=merge(st[i-1][j],st[i-1][j2]);
        }
    }
}

ll query_log(int l, int r){
    ll ans=NULO;
    for(int i=K-1;i>=0;i--){
        int p=1<<i;
        int tam=r-l+1;
        if(p<=tam){
            ans=merge(ans,st[i][l]);            
            l+=p;
        }
    }
    return ans;
}

//query em O(1) -> valido para funcoes idempotentes: se contar o mesmo elemento 2x, a resposta n muda (max, min)
ll query_cte(int l, int r){
    int lg=logs[r-l+1];
    return merge(st[lg][l],st[lg][r-(1<<lg)+1]);
}

void test(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    precalc();

    while(q--){
        int l,r;
        cin>>l>>r;
        // cout<<query_log(l,r)<<"\n";
        cout<<query_cte(l,r)<<"\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        test();
    }

    return 0;
}
