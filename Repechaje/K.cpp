#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  cin>>n>>m; //panes y hornos
  vector<int>panes(n), hornos(m);
  for(int i = 0; i < n; i++)
    cin>>panes[i];
  for(int i = 0; i < m; i++)
    cin>>hornos[i];
  int a = 0, b = 0;
  for(int i = 0; i < n; i++)
    a += panes[i];
  for(int i = 0; i < m; i++)
    b += hornos[i];
  cout<<abs(a - b)<<endl;

}
