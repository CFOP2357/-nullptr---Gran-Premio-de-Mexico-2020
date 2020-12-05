#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    int s = a[0] + a[1] + a[2];
    if(a[0] >= 500 && a[1] >= 500 && a[2] >= 500){
        cout<<s - 300<<endl;
        return 0;
    }
    if(a[0] >= 500 && a[1] >= 500){
        cout<<s - 200<<endl;
        return 0;
    }
    if(a[0] >= 500 && a[2] >= 500){
        cout<<s-200<<endl;
        return 0;
    }
    if(a[1] >= 500 && a[2] >= 500){
        cout<<s - 200<<endl;
        return 0;
    }
    if(a[0] >= 500){
        if(a[1] + a[2] >= 500)
            cout<<s - 200<<endl;
        else
            cout<<s - 100<<endl;
        return 0;
    }
    if(a[1] >= 500){
        if(a[0] + a[2] >= 500)
            cout<<s - 200<<endl;
        else
            cout<<s - 100<<endl;
        return 0;
    }
    if(a[2] >= 500){
        if(a[0] + a[1] >= 500)
            cout<<s - 200<<endl;
        else
            cout<<s - 100<<endl;
        return 0;
    }
    //ninguno fue mayor a 500
    if(s >= 500){
        cout<<s-100<<endl;
        return 0;
    }
    cout<<s<<endl;
    return 0;
}