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

#define MAX 10000010
#define MOD 1000000007

vector<vector<ull>> adj;

vector<ull> a;
vector<ull> b;
ull n, k;


const int N = 10000010;
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

set<ull> D;

void getDiv(ull A){

    ull d = A;
    while(d>1){
        D.insert(lp[d]);
        d/=lp[d];
    }

}

void solve(){
    ull A, B;
    cin>>A>>B;

    D.clear();
    getDiv(A);
    getDiv(B);

    cout<<D.size()<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    pre();

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

