#include<bits/stdc++.h>
using namespace std;

#define MAX 200

typedef  long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> P;

vector<int> adj[MAX];
int edges(0);

struct UF {
	vector<int> e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int N, M, K;
// aristas, (costo, nodos)
priority_queue<P, vector<P>, greater<P>> l; //los que sobran
vector<P> aristas;
bool posible = true;

int kruskal(){
  int a, b, suma = 0;
  sort(aristas.begin(), aristas.end());
  UF uf(N+5);
  for(int i = 0; i < aristas.size(); i++){
    a = aristas[i].second.first;
    b = aristas[i].second.second;
    if(!uf.sameSet(a, b)){
      adj[a].push_back(b);
      adj[b].push_back(a);
      uf.join(a, b);
      edges++;
    }
    else {
      l.push(aristas[i]);
    }
  }
  return suma;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>N>>M>>K;

  // No se puede formar un arbol
  if(K < N - 1){
    posible = false;
  }

  for(int i = 1; i <= M; i++){
    int a, b;
    cin>>a>>b;
    if(b < a) swap(a, b);
    aristas.push_back({0,{a,b}});
    //l.push(aristas.back());
  }
  //cout << "Input\n";

  //llamar MST
  kruskal();

  //cout << "MST\n";

  if(edges > K || !posible){

    cout<<"Impossible\n";
    return 0;
  }

  for(;edges<K; edges++){
    if(!l.size()){
      cout<<"Impossible\n";
      return 0;
    }

    int u = l.top().second.first;
    int v = l.top().second.second;
    l.pop();

    adj[u].push_back(v);
    adj[v].push_back(u);

  }

  for(int i=1; i<N; i++)
    cout<<adj[i].size()<<" ";
  cout<<adj[N].size()<<"\n";

}
