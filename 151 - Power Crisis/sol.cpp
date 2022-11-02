#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
  int n;
  int m;

  while(cin >> n && n != 0){
    n--;
    for(m = 1; m < n; m++){
        int target = 0;
        for(int i = 1; i <= n; i++){
            target = (target + m) % i;
        }
        if(target == 11)
            break;
    }
    cout << m << endl;
  }
}
