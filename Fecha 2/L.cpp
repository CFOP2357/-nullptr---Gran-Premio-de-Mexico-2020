#include<bits/stdc++.h>
#define MAX 45
using namespace std;

int N, M, Q;
char mapa[MAX][MAX];

int sol[MAX][MAX];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    //lectura
    cin>>N>>M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin>>mapa[i][j];

    //para visitar palabras
    int color = 0;    

    set<pair<int, int> >coord;

    //queries
    cin>>Q;
    while (Q--){

        color++;

        string objetivo;
        cin>>objetivo;
        
        vector<int>VISITADO(27, 0);            
        for(int i = 0; i < objetivo.size(); i++)
            VISITADO[objetivo[i] - 'A']++;        
        
        //iteramos el mapa                
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                
                //arriba - abajo
                if(N - i >= objetivo.size()){//checamos si cabe la cadena en el espacio restante
                    bool posible = 1; //inicialmente es posible
                    vector<int>visitado = VISITADO;
                    for(int k = 0; k < objetivo.size(); k++){                                            
                        visitado[mapa[i + k][j] - 'A'] --;
                        if(visitado[mapa[i + k][j] - 'A'] < 0){
                            posible = 0;
                            break;
                        }
                    }
                    if(posible){ //marcamos la aparicion de la palabra en la matriz de solucion
                        for(int k = 0; k < objetivo.size(); k++){
                            if(sol[i + k][j] == 0)
                                sol[i + k][j] = color;                                
                            else if(sol[i + k][j] != color)
                                coord.insert({i + k, j});                            
                        }
                    }
                }

                //izquierda - derecha
                if(M - j >= objetivo.size()){//checamos si cabe la cadena en el espacio restante
                    bool posible = 1; //inicialmente es posible
                    vector<int>visitado = VISITADO;
                    for(int k = 0; k < objetivo.size(); k++){                                            
                        visitado[mapa[i][j + k] - 'A'] --;
                        if(visitado[mapa[i][j + k] - 'A'] < 0){
                            posible = 0;
                            break;
                        }
                    }
                    if(posible){ //marcamos la aparicion de la palabra en la matriz de solucion
                        for(int k = 0; k < objetivo.size(); k++){
                            if(sol[i][j + k] == 0)
                                sol[i][j + k] = color;                                
                            else if(sol[i][j + k] != color)
                                coord.insert({i, j + k});                                
                        }
                    }                    
                }

                //diagonal abajo-izquierda  
                //checamos abajo y la izquieda
                if(N - i >= objetivo.size() &&  j - objetivo.size() >= 0){//checamos si cabe la cadena en el espacio restante
                    bool posible = 1; //inicialmente es posible
                    vector<int>visitado = VISITADO;
                    for(int k = 0; k < objetivo.size(); k++){
                        visitado[mapa[i + k][j - k] - 'A'] --;
                        if(visitado[mapa[i + k][j - k] - 'A'] < 0){
                            posible = 0;
                            break;
                        }
                    }
                    if(posible){ //marcamos la aparicion de la palabra en la matriz de solucion
                        for(int k = 0; k < objetivo.size(); k++){
                            if(sol[i + k][j - k] == 0)
                                sol[i + k][j - k] = color;                                
                            else if(sol[i + k][j - k] != color)                                                                  
                                coord.insert({i + k, j - k});
                        }
                    }
                }


                //diagonal abajo-derecha  
                //checamos abajo y la derecha
                if(N - i >= objetivo.size() &&  M - j >= objetivo.size()){//checamos si cabe la cadena en el espacio restante
                    bool posible = 1; //inicialmente es posible
                    vector<int>visitado = VISITADO;
                    for(int k = 0; k < objetivo.size(); k++){
                        visitado[mapa[i + k][j + k] - 'A'] --;
                        if(visitado[mapa[i + k][j + k] - 'A'] < 0){
                            posible = 0;
                            break;
                        }
                    }
                    if(posible){ //marcamos la aparicion de la palabra en la matriz de solucion
                        for(int k = 0; k < objetivo.size(); k++){                            
                            if(sol[i + k][j + k] == 0)
                                sol[i + k][j + k] = color;
                            else if(sol[i + k][j + k] != color)                            
                                coord.insert({i + k, j + k});                                                            
                        }
                    }
                }

            }
        }        
    }    
    cout<<coord.size()<<endl;    
}

/*
4 5
XBOIC
DKIRA
ALBOA
BHGES
3
BOI
BOLA
CASA


2 4
AAAA
AAAA
2
AAA
BBB

3 3
AAB
ABA
BAA
2
ABA
BBB

*/