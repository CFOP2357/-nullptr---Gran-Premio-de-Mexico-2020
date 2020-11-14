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

typedef unsigned long long ull;
typedef long long ll;

typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ll> a;
vector<ll> b;
ll n;


// P
////////////////////////////////////////////////////////
//https://github.com/kth-competitive-programming/kactl/tree/master/content/number-theory
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}
////////////////////////////////////////////////////////


int graph[1002][1002];

void solve(){
  ull n,m, k, tmp;
  ull num[1010];
  cin >> m >> n >> k;

  for(int i = 0; i< n; i++){
    cin >> num[i];
  }

  //cout<<"1#\n";

  sort(num, num+n);

  for(int i=0; i < k; i++){
    int a, b, d;
    cin >> a >> b >> d;
    graph[b][a] = d;
  }

  //cout<<"2#\n";

  set<ull> ans;
  for(int i = 0; i< n; i++){ // O(n*(n*logc + n))
    //cout<<num[i]<<"\n";
    vector<ull> comunes = factor(num[i]);
    for(ull div : comunes){
        ans.insert(div);
    }
    for(int j = i; j<n; j++){
      for(ull div : comunes){
        if(div > num[j]) break;
        while(num[j]%div == 0)
          num[j]/=div;
      }
    }
  }
  //cout<<"3#\n";

  for(auto a = ans.begin(); a!=ans.end(); a++){
    auto nxt = a; nxt++;

    cout<<*a;
    if(nxt!=ans.end())
      cout<<" ";

  }
  cout<<"\n";
}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

