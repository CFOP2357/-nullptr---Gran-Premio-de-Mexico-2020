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

#define MAX 1000100
#define MOD 1000000007

vector<vector<ull>> adj;

vector<pii> p; //pos, dir
ull L, G;

#define LEFT 0
#define RIGHT 1

void pre(){

}

void solve(){

    cin>>L>>G;
    for(int i=0; i<G; i++){
        ull P, D; cin>>P>>D;
        p.push_back({P, D});
    }
    sort(all(p));

    ull ans = 0;
    ull even = 0, odd = 0;
    bool isEven = false;
    for(auto goomba : p){
        if(goomba.second == RIGHT){
            ans = max(ans, L-goomba.first);
        }
        else {
            ans =  max(ans, goomba.first );
        }
    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    pre();

    int t=1;// cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
3 2
1 1
2 0


5 2
1 0
2 1
*/

