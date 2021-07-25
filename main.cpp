#include "btree_map.h"
#include<iostream>
tlx::btree_map<int,int> data;
int main(){
    int n,m,p,q;
    std::cin>>n>>m>>p>>q;
    for(int i=1;i<=n;++i){
        int k,v;
        std::cin>>k>>v;
        data.insert2(k,v);
    }
    for(int i=1;i<=m;++i){
        int k;
        std::cin>>k;
        auto it=data.find(k);
        if(it==data.end()){
            std::cout<<"NOT FOUND"<<std::endl;
        }
        else {
            std::cout<<it->second<<std::endl;
        }
    }
    for(int i=1;i<=p;++i){
        int k,v;
        std::cin>>k>>v;
        data[k]=v;
    }
    for(int i=1;i<=q;++i){
        int l,r;
        std::cin>>l>>r;
        int res=0;
        for(auto now=data.lower_bound(l);now!=data.end()&&now->first<r;++now){
            ++res;
        }
        std::cout<<res<<std::endl;
    }
}
