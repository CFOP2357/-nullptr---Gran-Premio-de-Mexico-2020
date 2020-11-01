#include<bits/stdc++.h>
using namespace std;

int Rule_3(string S){
  string ar[] = {"01", "12", "23", "34", "45", "56", "67", "78", "89"};
  string ar2[] = {"98", "87", "76", "65", "54", "43", "32", "21", "10"};
  
  bool valid = false;
  for(char c : S)
    if ('0' <= c and c <= '9') {
      valid = true;
      break;
    }
    
  if (not valid) return 0;

  for(int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
    if(S.find(ar[i]) != string::npos || S.find(ar2[i]) != string::npos)
      return 0;
  return 1;
}          

int Rule_4(string S){
  string ar[] = {".", "#", "$", "%", "/", "(", "&", ")"};
  for(int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
    if(S.find(ar[i]) != string::npos)
      return 1;
  return 0;
}

int Rule_5(string S){
  return S.size() >= 10;
}

int Rule_2(string s){
  for(char c : s)
    if ('A' <= c and c <= 'Z') return 1;
  return 0;
}

int Rule_1(string s){
  for(char c : s)
    if ('a' <= c and c <= 'z') return 1;
  return 0;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin>>N;
  for(int i = 1; i <= N; i++){
    string S;
    cin>>S;
    int c = 0;
    c += Rule_1(S);
    //cout << c << ' ';
    c += Rule_2(S);
    //cout << c << ' ';
    c += Rule_3(S);
    //cout << c << ' ';
    c += Rule_4(S);
    //cout << c << ' ';
    c += Rule_5(S);
    //cout << c << '\n';
    if(c == 5)
      cout<<"Assertion number #"<<i<<": Strong\n";
    else if(c == 4)
      cout<<"Assertion number #"<<i<<": Good\n";
    else if(c == 3)
      cout<<"Assertion number #"<<i<<": Weak\n";
    else
      cout<<"Assertion number #"<<i<<": Rejected\n";
  }
}
