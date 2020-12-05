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
ull n, b;

void pre(){

}

void solve(){

    priority_queue<pii, vector<pii>, greater<pii>> nxt;

    cin>>n>>b;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        nxt.push({z, i});
    }

    vector<ull> ans(n, 0);

    while(nxt.size()){
        int i = nxt.top().second; //cout<<nxt.top().second<<"\n";
        nxt.pop();

        if(ans[i])
            continue;

        if(a[i])ans[i]++;
        ans[i]++;

        if(a[i]>a[((i-1)<0?n-1:i-1)]){
            ans[i]= max(ans[((i-1)<0?n-1:i-1)]+1, ans[i]);
        }
        if(a[i]>a[(i+1)%n]){
            ans[i]= max(ans[(i+1)%n]+1, ans[i]);
        }

    }

    for(int i=0; i<ans.size(); i++){
        cout<<(ans[i]-1)*b;
        if(i==n-1)
            cout<<"\n";
        else cout<<" ";
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;// cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

