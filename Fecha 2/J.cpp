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

typedef long long ll;
typedef long long ull;

const int MAXN = 1e4 + 2;
const int MOD = 1e9 + 7;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}


const ll mod = MOD; // change to something else
struct Mod {
	ll x;
	Mod(ll xx) : x(xx) {}
	Mod() : x(0) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		return Mod((x + mod) % mod);
	}
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};

Mod factorial[MAXN];
Mod inverse_factorial[MAXN];

Mod dp[MAXN];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ull n, m, k;
  cin >> n >> k >> m;

  dp[0] = Mod(1);

  for(ull i = 1; i <= m; i++)
    dp[i] = dp[i-1] * Mod(k);


  for(ull i = m+1; i <= n; i++){
    dp[i] = 0;
    for(ull j = 1; j <= m; j++){
      dp[i] = dp[i] + (Mod(k-1) * dp[i-j]);
    }
  }

  cout << dp[n].x << '\n';

  return 0;
}
