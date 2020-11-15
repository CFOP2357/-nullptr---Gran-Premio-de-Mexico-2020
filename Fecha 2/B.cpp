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

vector<ull> a;
vector<ull> b;
ull n;

bool grid[11][11];

bool colocarBarco(int x, int y, int d, int l){
  if(d == 0){ //horizontal
    for(int i = 0; i < l; i++){
      if(y + i > 9 or grid[x][y + i]) //fuera de limites
        return 0;
      grid[x][y + i] = 1;  
    }
  }
  if(d == 1){ //horizontal
    for(int i = 0; i < l; i++){
      if(x + i > 9 or grid[x + i][y]) //fuera de limites
        return 0;
      grid[x + i][y] = 1;
    }
  }
  return 1;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int barcos;

    ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  int D,L,R,C;

  cin >> N;

  bool ans = true;
  while(N--){
    cin >> D >> L >> R >> C;
    ans = ans and colocarBarco(R-1,C-1,D,L);
  }

  cout << (ans? "Y\n" : "N\n");

  return 0;
}


