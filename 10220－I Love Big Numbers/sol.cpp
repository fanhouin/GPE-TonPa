#include <iostream>
#include <cstdio>
using namespace std;
int ans[1010] = {1,1};
int num[3010] = {1};

int main(){
    int dd = 1;
    for(int i = 2; i <= 1000; i++){
        for(int j = 0; j < dd; j++){
            num[j] *= i;
        }

        for(int j = 0; j < dd; j++){
            num[j+1] += num[j] / 10;
            num[j] %= 10;
            ans[i] += num[j];
            if(j + 1 >= dd && num[j+1] > 0)
                dd++;
        }
    }

    int n;
    while(cin >> n){
        cout << ans[n] << endl;
    }

}
