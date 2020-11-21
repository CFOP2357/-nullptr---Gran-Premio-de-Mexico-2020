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
int P[MAX];
int A[MAX];
int N, M;

bool visited[MAX];
vector<ull> pt[MAX]; //fiestas en el que el nodo v es el mas grande

vector<pii> last; //edad, id
void dfs(int v){
    last.push_back({A[v], v});

    //10 9 7 6 5 4
    for (auto p : party[v]){ // p = {r, l}
      int pos = lower_bound(last.begin(), last.end(), make_pair(p.first, LLONG_MAX), greater<pii>())->second;
      //cout<<pos;
      pt[pos].push_back(p.second);
    }

    for(auto u : children[v]){
      if(u!=v)
        dfs(u);
    }

    last.pop_back();
}

struct Tree {
	typedef ull T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

Tree seg(MAX);
ull ans[MAX];
void dfs2(int v){
  for(int fiesta : pt[v])
    seg.update(fiesta, seg.query(fiesta, fiesta+1)+1); //[v, v+1)

  /*for(int fiesta : pt[v])
    cout<<fiesta<<" ";
  cout<<"\n";*/

  ans[v] = seg.query(0, A[v]+1); //[)

  for(auto c : children[v]){
    if(c == v) continue;
    dfs2(c);
  }

  for(int fiesta : pt[v])
    seg.update(fiesta, seg.query(fiesta, fiesta+1)-1);
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



    dfs(1);
    dfs2(1);

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

