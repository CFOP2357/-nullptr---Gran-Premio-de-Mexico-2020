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

ull pow2[70];
void pre(){

    pow2[0] = 1;
    for(int i = 1; i <= 62; i++){
        pow2[i] = 2 * pow2[i-1];
    }


}

/*
x

o
*/

void solve(){
    int x, y;
    cin >> x >> y;

    //if(x > 1 and y > 1)
        cout << pow2[x] + pow2[y] - 2 << '\n';
    /*else
        cout << "0\n";
    */
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    pre();

    int t=1; //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

