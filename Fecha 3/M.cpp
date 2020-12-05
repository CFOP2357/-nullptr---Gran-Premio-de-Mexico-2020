#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define all(a) a.begin(), a.end()

int rm[300];
vector<bool> valid;
string num;

//O(2n^2)

int next(int x){
  for(int i = x + 1; i < num.size(); i++){
    if(valid[i] && num[i]!=num[x]) return i;
  }
  return -1;
}

vector<int> pos[300];

vector<char> C = {'9', '1', '8', '2', '7', '3', '6', '4', '5'};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> num;

  for(char i = '1'; i <= '9'; i++){
    cin >> rm[i];
  }

  valid = vector<bool>(num.size(), true);

  //vector pos
  for(int i=0; i<num.size(); i++)
    pos[num[i]].push_back(i);

  //greedy
  bool p = true;
  for(char c : C){

    if(p){
        for(int i : pos[c]){
          int j = next(i);
          if(j>=0 && num[i]<num[j] && rm[c]){
            rm[c]--;
            valid[i]=false;
          }
        }
    }
    else {
        reverse(all(pos[c]));

        for(int i : pos[c]){
          if(valid[i] && rm[c]){
            rm[c]--;
            valid[i]=false;
          }
        }
    }

    p = !p;
  }



  for(int i = 0; i < num.size(); i++){
    if(valid[i]) cout << num[i];
  }
  cout << '\n';
}

/*
12345
1 0 0 1 1 0 0 0 0

112345
2 1 1 0 0 0 0 0 0

1123451
2 1 1 0 0 0 0 0 0

132129
0 1 0 0 0 0 0 0 1

*/
