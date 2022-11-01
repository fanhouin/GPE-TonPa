#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 30000
long long dp[maxn+5] = {1};
long long coin[11] = {10000,5000, 2000, 1000, 500, 200, 100, 50, 20 , 10, 5};

int main(){
    for(int i = 0; i < 11; i++){
        for(int j = coin[i]; j <= maxn; j++){
            dp[j] += dp[j - coin[i]];
        }
    }
    int input1, input2;
    while(scanf("%d.%d", &input1, &input2) != EOF && !(input1 == 0 && input2 == 0)){
        printf("%3d.%02d%17lld\n", input1, input2, dp[input1*100+input2]);
    }
}
