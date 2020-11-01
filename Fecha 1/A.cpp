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

#define MAX 200100
#define MOD 1000000007

set< pair<ull, pii>, greater<pair<ull, pii>> > all; //preference, pair reaction
set< pii, greater<pii>> each[MAX]; //preference, j

map <pair<int, int>, ull> preference;

ull n, q;

void R(){
    int i, j; cin>>i>>j;

    preference[{i, j}]++;

    all.insert( {preference[{i, j}], {i, j}} );
    each[i].insert( {preference[{i, j}], j} );
}

void Q(){
    int i; cin>>i;

    if(!each[i].size()){
        cout<<"No info\n";
        return;
    }

    auto sec = each[i].begin();
    sec++;
    if(each[i].size()==1 || each[i].begin()->first > sec->first){
        cout<<each[i].begin()->second<<"\n";
    }
    else cout<<"Multiple\n";
}

void B(){

    if(!all.size()){
        cout<<"No info\n";
        return;
    }

    auto sec = all.begin();
    sec++;
    if(all.size()==1 || all.begin()->first > sec->first){
        cout<<all.begin()->second.first<<" "<<all.begin()->second.second<<"\n";
    }
    else cout<<"Multiple\n";
}


void solve(){
    cin>>n>>q;

    char c;
    while(q--){
        cin>>c;

        switch(c){
            case 'R':
                R();
            break;
            case 'Q':
                Q();
            break;
            case 'B':
                B();
            break;
        }
    }


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

