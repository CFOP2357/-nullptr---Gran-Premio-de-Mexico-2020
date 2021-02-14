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
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 200100
#define MOD 1000000007

ll b_pow(ll b, ll p){
    if(not p){
        return 1;
    }
    ll ans = b_pow(b, p/2);
    ans *= ans;
    ans %= MOD;
    if(p & 1LL){
        ans *= b;
        ans %= MOD;
    }
    return ans;
}

ll inverse(ll n){
    return b_pow(n, MOD - 2);
}

ll factorial[MAX + 10];
void pre(){
    factorial[0] = 1;
    for (int i = 1; i <= MAX; i++)
        factorial[i] = factorial[i - 1] * i % MOD;
}

ll C(ll n, ll k){
    return factorial[n]
    * inverse(factorial[k]) % MOD
    * inverse(factorial[n-k]) % MOD;
}

void solve(){
    ll n;
    cin >> n;

    cout << C(2 * n - 1, n - 1) <<  '\n';
}

/*
2 2
0.75 0.25
0.5 0.5
*/

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    pre();

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

