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

#define MAX 100100
#define MOD 1000000007

set<ull> children[MAX];
multiset<pii> party[MAX];
ull ans[MAX];
int P[MAX];
int A[MAX];
int N, M;

bool visited[MAX];

//children, party
void dfs(int v, int p){

    if(visited[v])
      return;
    visited[v] = true;

    children[v].insert(v);

    //cout << v<<"$\n";

    for(int u : children[v]){
        if(u==p || u==v)
          continue;

        dfs(u, v);

        for(auto child : children[u])
          children[v].insert(child);
        for(auto part : party[u])
          party[v].insert(part);
    }


    //cout << "party_size: " << party[v].size() << '\n';
    while(party[v].size() && (party[v].begin()->first < A[p] || v == 1)){
      //cout << "l " << party[v].begin()->second << ' ';
      //cout << " r " << party[v].begin()->first << '\n';
      for(int child : children[v]){
        if(A[child] >= party[v].begin()->second) ans[child]++;
      }

      party[v].erase(party[v].find(*party[v].begin()));
    }

    for(int u : children[v]){
      if(u != v){
        children[u].clear();
        party[u].clear();

    }
    }

}

void solve(){
    cin>>N>>M;
    for(int i=1; i<=N; i++){
      cin>> A[i] >> P[i];
      children[P[i]].insert(i);
    }

    while(M--){
      int o, l, r; cin>>o>>l>>r;
      party[o].insert({r, l});
    }


    dfs(1, 0);

    for(int i=1; i<N; i++)
      cout<<ans[i]<<" ";
    cout<<ans[N]<<"\n";

}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

