#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>

#include <map>
#include <set>

#include <stack>
#include <queue>

#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define all(a) a.begin(), a.end()

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000001
#define MOD 1000000007
// empleados, premios, queries
int N, M, Q;
vector<int>adj[MAX];

ull individual[MAX];
ull sePasan[MAX];

ull totalIndividual[MAX];
ull total[MAX];


ull dfs(int u){
  //recorremos nodos adyacentes
  for(auto v : adj[u]){
    sePasan[u] += dfs(v);
  }
  return sePasan[u];
}

ull dfs2(int u){
  //recorremos nodos adyacentes
  for(auto v : adj[u]){
    total[u] += dfs2(v);
  }
  return total[u];
}

void solve(){
  cin>>N>>M>>Q;
  ull root = 1;
  for(int i = 1; i <= N; i++){
    ull mannager; cin>>mannager;
    adj[mannager].push_back(i);

    if(mannager==0)
      root=i;
  }


  while(M--){
    ull m, e, v; cin>>m>>e>>v;
    if(m==1){
      individual[e] += v;
    }
    else {
      sePasan[e] += v;
    }
  }

  dfs(root);

  for(int i=1; i<=N; i++)
    total[i] = totalIndividual[i] = sePasan[i]+individual[i];

  dfs2(root);

  while(Q--){
    ull t, e;
    cin>>t>>e;
    if(t == 1)
      cout<<totalIndividual[e]<<"\n";
    else
      cout<<total[e]<<"\n";
  }


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;// cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

