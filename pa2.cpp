#include<iostream>
//#define TLX_BTREE_DEBUG
#include"die.cc"
#include"btree_map.h"
using namespace std;
int main(){
    ios::sync_with_stdio(false);
  //  cerr<<"start"<<endl;
    tlx::btree_map<int,int> data;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        int k,v;
        cin>>k>>v;
        data[k]=v;
        //if(n%10000==0)cerr<<k<<v<<endl;
    }
    for(int i=1;i<=m;++i){
        int l,r;
        cin>>l>>r;
        //cerr<<l<<" "<<r<<endl;
        cout<<data.range_query(l,r)<<endl;

    }
}