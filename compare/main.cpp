#include <cstdio>
#include <cstring>
#include <algorithm>
#include<string>
#include<iostream>
using namespace std;
void System(std::string s){
  cerr<<s<<endl;
  system(s.c_str());
}
int main(void) {
  System("g++ dmk.cpp -o dmk");
    System("g++ ../pa2.cpp -o ../main");
  while (true) {
    
    System("./dmk > in && ../main < in > out && ./brute < in > ans");
    if (system("diff -b ans out")) {
      puts("wrong");
      exit(0);
    } else {
      puts("ok");
    }
  }
}
