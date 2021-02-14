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

void pre(){
}

ll y, x, z, k;
ll c, f, b, s;
void solve(){
    cin >> c >> f >> b >> s;

    int m = 12;
    for(int i = 1; i <= 6; i++){
        if(i*f % 12 == 0 and i*b % 12 == 0){
            m = i;
            break;
        }
    }

    ll dist = 12 * s;
    ll step = c * m;
    ll turns = (dist / step) * m
    + (dist % step > 0) * m;

    cout << turns << '\n';

}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    pre();

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

