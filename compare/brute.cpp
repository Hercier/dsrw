#include<iostream>
//#define TLX_BTREE_DEBUG
using namespace std;
#include<set>
class read{
    public:
    static const int MAX_SIZE=1<<20;
    char buff[MAX_SIZE];
    char* buff_end=NULL,*bpos=NULL;
    char getc(){
        if(buff_end==bpos){
            buff_end=buff+fread(buff,1,MAX_SIZE,stdin);
            bpos=buff;
        }
        return *(bpos++);
    }
    char first_useful(){
        char c=getc();
        while((c==' ')|(c=='\n')|(c=='\r')){
            c=getc();
        }
        return c;
    }
    read &operator>>(char &x){
        x=first_useful();
        return *this;
    }
    read &operator>>(int &x){
        char c = first_useful();
        x = 0;
        int s=1;
        if(c=='-'){
            s=-1;
            c=getc();
        }
        while (c >= '0' && c <= '9') {
            x = x * 10 + c - '0';
            c = getc();
        }
        x*=s;
        return *this;
    }
}IN;
set<int> data;
int main(){
    int n;
    IN>>n;
    for(int i=1;i<=n;++i){
        int a,b;
        char op;
        IN>>op>>a>>b;
        if(op=='i'){
            data.insert(a);
        }
        else{
            int res=0;
            for(int i=a;i<b;++i){
              res+=data.count(i);
            }
            printf("%d\n",res);
        }
    }
}