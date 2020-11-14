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

#define MAX 100
#define MOD 1000000007

ull L, C, N;
char grid[MAX][MAX];
set<int> t[MAX][MAX];
vector<string> w;

bool mapEqual(map<char, int> &a, map<char, int> &b){

    if(a.size() != b.size())
        return false;

    for(auto el : b){
        if(a[el.first]!=el.second)
            return false;
    }

    return true;


}

void solve(){
    cin>>L>>C;

    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++){
            cin>>grid[i][j];
            t[i][j].clear();
        }

    cin>>N;
    for(int i=0; i<N; i++){
        string s; cin>>s;
        w.push_back(s);
    }


    int iS = 0;
    for(string s : w){

        map<char, int> times_char; times_char.clear();
        for(char c : s)
            times_char[c]++;

        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++){

                map<char, int> actual;

                actual.clear();
                if(s.size()+i<=L){ //012
                    for(int k = 0; k<s.size(); k++)
                        actual[grid[i+k][j]]++;
                    if(mapEqual(actual, times_char))
                        for(int k = 0; k<s.size(); k++)
                            t[i+k][j].insert(iS);
                }

                actual.clear();
                if(s.size()+j<=C){
                    for(int k = 0; k<s.size(); k++)
                        actual[grid[i][j+k]]++;
                    if(mapEqual(actual, times_char))
                        for(int k = 0; k<s.size(); k++)
                            t[i][j+k].insert(iS);
                }

                actual.clear();
                if(s.size()+j<=C && s.size()+i<=L){
                    for(int k = 0; k<s.size(); k++)
                        actual[grid[i+k][j+k]]++;
                    if(mapEqual(actual, times_char))
                        for(int k = 0; k<s.size(); k++)
                            t[i+k][j+k].insert(iS);
                }

                actual.clear();
                if(j-s.size()>=-1 && s.size()+i<=L){
                    for(int k = 0; k<s.size(); k++)
                        actual[grid[i+k][j-k]]++;
                    if(mapEqual(actual, times_char))
                        for(int k = 0; k<s.size(); k++)
                            t[i+k][j-k].insert(iS);
                }



            }

        iS++;

    }


    int ans = 0;
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            if(t[i][j].size()>1)
                ans++;
    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

/*
4 4
AZAB
CBCB
ACAA
BZAA
2
BBCC
BCZZ

4 4
AZAB
CBCC
ACAA
BZAA
2
BBCC
BCZZ

4 4
AAAA
AAAA
AAAA
AAAA
2
AAAA
AA

4 5
XBOIC
DKIRA
ALBOA
BHGES
4
BOLA
CASA
BOI
EO

1 5
ABCAA
2
ABCAA
A

5 1
A
B
C
A
A
2
AACBA
ABC




*/

