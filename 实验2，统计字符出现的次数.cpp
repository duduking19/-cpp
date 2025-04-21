#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node {
    char ch;
    int count;
}node[1001];
int cnt =0;
int mp[150]; 

int main() {
    string s;
    while(cin>>s){
        for(int i=0;i<150;i++) mp[i]=0;
        for(int i=0;i<s.length();i++) mp[s[i]]++;
    for (int i =0; i <150; i++) {
        if (mp[i]> 0) {
           node[cnt].ch = i;
           node[cnt].count = mp[i];
           cnt++;
        }
    }
    sort(node, node+cnt,[](Node a, Node b)
    {
        if(a.count !=b.count) return a.count > b.count;
        return a.ch>b.ch;});
        for(int i=0; i<cnt;i++) {
            cout << node[i].ch << ":" << node[i].count << " ";
        }

    cout << endl;
    cnt=0;
}
}