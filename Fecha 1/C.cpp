#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

bool comp(const string &a, const string &b){
  if(a.size() == b.size())
    return a < b;
  else
    return a.size() < b.size();
}

struct UF {
	map<string, string> e;
	UF() {}
	bool sameSet(string a, string b) { return find(a) == find(b); }
	string find(string x) {
        if(e.find(x) == e.end())
        {
          return e[x] = x;
        }
        if(e[x]==x)
          return x;
        return find(e[x]);
    }
	bool join(string a, string b) {
		a = find(a), b = find(b);
    if(comp(b, a))
      swap(a, b);
		e[b] = a;
		return true;
	}
};

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin>>N;

  UF uf;

  for(int i = 1; i <= N; i++){
      string a, b;
      cin>>a>>b;
      uf.join(a, b);
  }
  string line, word;
  cin.ignore();
  getline(cin, line);
  stringstream ss;
  ss.str(line);
  while(ss >> word){
    cout << uf.find(word);
    if(ss.eof())
      cout<<"\n";
    else cout<<" ";
  }
}

/*
8
sea see
see c
you u
and an
n an
are r
ok k
k z
i sea you and you are ok
*/
