#include <iostream>

using namespace std;


int main(){
    int n;
    while(cin >> n){
        if(n == 0)
            break;
        if(n <= 2){
            cout << n << endl;
            continue;
        }

        unsigned long long dp[n+1] = {0,1,2};
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        cout << dp[n] << endl;
    }

}
