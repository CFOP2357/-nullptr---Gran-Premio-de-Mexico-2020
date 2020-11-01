#include<bits/stdc++.h>
using namespace std;
               
bool isPrime(int x){
    if(x < 2)
        return 0;
    if(x == 2)
        return 1;
    if(x % 2 == 0)
        return 0;
    for(int i = 3; i <= sqrt(x); i += 2)
        if(x % i == 0)
            return 0;
    return 1;
}

//validamos que el número no tenga 0´s al inicio
int toInt(string x){
    // int DistintoDeCero = 0;
    // for(int i = 0; i < x.size(); i++){
    //     if(x[i] == '0' && DistintoDeCero == 0)
    //         return -1;
    //     DistintoDeCero = 1;
    // }
    if(x[0] == '0')
        return -1;
    return stoi(x);
}

int main(){

    string S;
    cin>>S;

    sort(S.begin(), S.end());
    int minProduct = INT_MAX;
    
    do{
        for(int i = 1; i < S.size(); i++){
            for(int j = 1; j < S.size() - i; j++){
                    int A = toInt(S.substr(0, i));
                    int B = toInt(S.substr(i, j));
                    int C = toInt(S.substr(j + i));
                    if(isPrime(A) && isPrime(B) && isPrime(C)){
                        //cout<<S<<endl;
                        //cout<<0<<" "<<i + 1<<endl;
                        //cout<<j<<" "<<k - j<<endl;
                        //cout<<k<<" "<<S.size() - k<<endl;
                        //cout<<A<<" "<<B<<" "<<C<<endl;
                        minProduct = min(minProduct, A * B * C);
                }
            }
        }                    
    }while(next_permutation(S.begin(), S.end()));

    if(minProduct == INT_MAX)
        cout<<"Bob lies\n";
    else
        cout<<minProduct<<"\n";
}