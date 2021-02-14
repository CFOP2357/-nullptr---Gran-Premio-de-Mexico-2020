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

double dp[10002][201];
double prob[201][201];
void pre(){
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i< n; i++)
        for(int j = 0; j< n; j++)
            cin >> prob[i][j];

    fill(dp[0], dp[0] + 201, 0);
    dp[0][0] = 1;

    for(int i = 1; i <= m; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = 0;
            for(int k = 0; k < n; k++){
                dp[i][j] += dp[i-1][k] * prob[k][j];
            }
            if(i == m)
                cout << dp[i][j] << '\n';
        }
    }
}

/*
2 2
0.75 0.25
0.5 0.5
*/

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    pre();

    int t=1; //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

