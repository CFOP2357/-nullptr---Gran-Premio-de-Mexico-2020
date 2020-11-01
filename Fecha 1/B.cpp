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

vector<ull> a;
vector<ull> b;
ull n;

/*

1 2 3 4 5 6 7 8 9 10
0 1 1 1 1 1 0 1 0 0

1 2 3 4 5 6 7 8 9 10
0 0 1 1 0 1 0 1 0 0

*/

struct Tree {
	typedef ull T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


Tree tr(MAX);
Tree front(MAX);

void solve(){

    ull ansBack = 0, ansBoth = 0;

    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin >> z;

        b.push_back(tr.query(z+1, MAX));

        ansBack += b.back();
        tr.update(z, tr.query(z, z+1)+1);

        a.push_back(z);
    }

    for(int i=n-1; i>=0; i--){
        ull z = a[i];

        ansBoth += min(b[i], front.query(z+1, MAX));
        front.update(z, front.query(z, z+1)+1);
    }

    cout<<ansBack<<" "<<ansBoth<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

/*
10
3
4
6
5
2
9
8
7
1
10

5
8
3
4
6
7
*/
