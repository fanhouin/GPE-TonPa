#include <iostream>
#include <vector>

using namespace std;

int main(){
    int stones;
    int n;
    while(cin >> stones){
        cin >> n;
        vector<int> choice;
        vector<int> dp(stones+1, 0);

        while(n--){
            int num;
            cin >> num;
            choice.emplace_back(num);
        }

        for(int i = 1; i <= stones; i++){
            for(auto c : choice){
                if(i - c >= 0 && dp[i - c] == 0){
                    dp[i] = 1;
                    break;
                }
            }
        }

        if(dp[stones] == 1)
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;

        choice.clear();
        dp.clear();
    }


}
