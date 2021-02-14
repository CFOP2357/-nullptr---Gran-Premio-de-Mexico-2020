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

#define MAX 1000100
#define MOD 1000000007

const int N = 1000100;
int lp[N+1];
vector<int> pr;
void pre(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

void solve(){
    ll n;
    cin >> n;
    n += 2;
    while(lp[n] == 2)
        n /= 2;
    if(n > 1) while(n > 1){
        while(lp[n] == lp[n/lp[n]]){
            n /= lp[n];
        }
        cout << lp[n];
        if(lp[n] != n)
            cout << ' ';
        n /= lp[n];
    } else {
        cout << -1;
    }

    cout << "\n";
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

