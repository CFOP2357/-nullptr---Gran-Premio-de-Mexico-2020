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

int personas = 0;
map<string, int> total;
map<string, int> restaurant;

void toMinus(string &S){
  for(int i = 0; i < S.size(); i++)
    S[i] = tolower(S[i]);
}

int stringToInt(string S){
  return stoi(S);
}

int space(string s){
    for(int i=0; i<s.size(); i++)
      if(s[i]==' ')
        return i+1;
    return 0;
}

vector<int> rest;
int count_(int i = 0, int sum = 0, int ull = 0){
  if(i == rest.size())
    return sum==n-1;

  return count_(i+1, sum+rest[i]) + count_(i+1, sum) + sum==n-1;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin>>n;

  //cin.clear();
  while(!cin.eof()){
    string s; getline(cin, s);

    int d = space(s);

    if(d){ //si tengo un espacio
      //split
      string number = s.substr(0, d - 1);
      string platillo = s.substr(d);

      total[platillo] += stringToInt(number);
    }
    else{ //es una persona o el restaurante
      if(s == "Restaurant")
        break;
      personas++;
    }

  }


  while(!cin.eof()){
    string s; getline(cin, s);

    int d = space(s);

    if(d){ //si tengo un espacio
      //split
      string number = s.substr(0, d - 1);
      string platillo = s.substr(d);

      restaurant[platillo] += stringToInt(number);
    }

  }


  int it = 0, sum = 0, tmp;
  for(auto x : restaurant){
    tmp = x.second - total[x.first];
    n -= total[x.first];
    if(tmp < 0 or n < 0){
      cout << "0\n";
      return 0;
    } else {
      rest.push_back(tmp);
    }
    sum += rest.back();
  }

  sort(all(rest));

  ull ans = count_();
  cout<<ans<<"\n";
  //P(sum, )

  return 0;
}

