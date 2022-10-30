#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int nums;
        int coin;
        int sum = 0;
        vector<int> coins;

        cin >> nums;
        while(nums--){
            cin >> coin;
            coins.push_back(coin);
        }

        for(auto c : coins){
            sum += c;
        }
        int av = sum / 2;

        vector<int> dp(av+1, 0);

        for(int i = 0; i < coins.size(); i++){
            for(int j = av; j >= coins[i]; j--){
                dp[j] = max(dp[j], dp[j - coins[i]] + coins[i]);
            }
        }

        int ans = sum - 2 * dp[av];
        cout << ans << endl;
    }
}
