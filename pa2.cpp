#include<iostream>
#include"btree_map.h"
using namespace std;
int main(){
    tlx::btree_map<int,int> data;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        int k,v;
        cin>>k>>v;
        data[k]=v;
    }
    for(int i=1;i<=m;++i){
        int l,r;
        cin>>l>>r;
        cout<<data.range_query(l,r)<<endl;

    }
}