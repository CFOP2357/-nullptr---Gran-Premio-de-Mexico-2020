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

#define MAX 100100
#define MOD 1000000007

vector<vector<ull>> adj;

vector<ull> g;
vector<pii> range;

ull n, k;

vector<ull> dp(MAX);

priority_queue<pii> wait_range[MAX]; //value, last
priority_queue<pii> actual_range;

void solve(){

    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        ull a, b; cin>>a>>b;
        g.push_back(z);
        range.push_back({min(i+a, n), i+b});
        //cout<<range[i].first<<"#\n";
    }
    g.push_back(0); range.push_back({1, 1});

    actual_range.push({0, n});
    for(int i=0; i<=n; i++){

        //cout<<wait_range[i].size()<<",";

        while(wait_range[i].size()){
            actual_range.push(wait_range[i].top());
            wait_range[i].pop();
        }

        while(actual_range.top().second < i)
            actual_range.pop();

        dp[i] = actual_range.top().first;

        //cout<<dp[i]<<" ";

        //cout<<range[i].first<<"\n";

        wait_range[min(range[i].first, n)].push({dp[i]+g[i], range[i].second});

    } //cout<<"\n";

    cout<<*max_element(all(dp))<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;// cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

