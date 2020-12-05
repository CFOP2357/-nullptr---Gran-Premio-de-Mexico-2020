#include<bits/stdc++.h>
using namespace std;
int main(){
  
    //5 75
    //320 170 235 23 78
  
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, g, maxPoints = 0;
    cin >> n >> g;
    vector<int>ar(n), ar2;


    for(int i = 0; i < n; i++)
        cin >> ar[i], maxPoints += ar[i];
    
    ar2 = ar;

    sort(ar2.begin(), ar2.end(), greater<int>());

    int sum = 0, min_sum = 
    ceil(
      (g/100.0) 
      * accumulate(ar2.begin(), ar2.end(), 0)
    );
    
    int min_prob = 0;

    for(; min_prob < n and sum < min_sum; min_prob++){
      sum += ar2[min_prob];
    }

    vector<int>grades;
    vector<vector<int>> output;

    for(int i = 0; i < (1 << n); i++){        
        if( __builtin_popcount(i) == min_prob){
          vector<int>pos;
          int points = 0;
          for(int j = 0; j < n; j++)
              if(i & (1 << j))
                  points += ar[j],
                  pos.push_back(j + 1);
          
          if(points > 0){
              int mean = points * 100 / maxPoints;
              if( mean >= g)
                grades.push_back(mean),
                output.push_back(pos);                 
          }
        }
    }    
    cout<<min_prob<<" "<<output.size()<<"\n";
    for(int i = 0; i < output.size(); i++){
      cout<<grades[i]<<" ";
      for(int j = 0; j < output[i].size(); j++)
        cout<<output[i][j]<<" ";
      cout<<"\n";
    }
}