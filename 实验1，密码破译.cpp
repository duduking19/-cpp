#include<bits/stdc++.h>
using namespace std;
int c[101];
int main(){
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        c[a[i]]= i+'A';
    
    }//映射 
    string b;
    while(cin>>b){
        for(int i=0;i<b.size();i++){
            b[i]=c[b[i]];
        }
        cout << b <<" "<<endl;
    }
}
