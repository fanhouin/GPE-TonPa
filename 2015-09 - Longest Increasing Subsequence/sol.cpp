#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    int num;
    vector<int> v;
    while(cin >> n){
        while(n--){
            cin >> num;
            v.emplace_back(num);
        }

        vector<int> dp(v.size(), 1);
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < i; j++){
                if(v.at(i) > v.at(j)){
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
        }

        int max = -1;
        for(auto e : dp){
            if(max < e) max = e;
        }
        cout << max << endl;

        v.clear();
        dp.clear();

    }


}
