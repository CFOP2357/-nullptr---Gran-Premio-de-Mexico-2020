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

vector<ull> a;
vector<ull> b;
ull n, k;

void pre(){

}

void solve(){

    unordered_set<string> m;

    int ans = 0;

    cin>>n;
    for(int i=0; i<n; i++){
        string s; cin>>s;

        bool diferent = true;
        for(int j=0; j<s.size(); j++){
            if(m.find(s) != m.end())
                diferent = false;
            s = s.substr(1) + s[0];
        }

        if(diferent){
            ans++;
            m.insert(s);
        }

    }

    cout<<ans<<"\n";


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;// cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

