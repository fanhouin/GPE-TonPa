#include <iostream>
#include <vector>

using namespace std;

int main(){
    string str1;
    string str2;
    while(cin >> str1){
        cin >> str2;

        int size1 = str1.size()+1;
        int size2 = str2.size()+1;
        vector<vector<int>> dp(size1, vector<int>(size2, 0));

        for(int i = 1; i < size1; i++){
            for(int j = 1; j < size2; j++){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

            }
        }

        cout << dp[size1-1][size2-1] << endl;
    }
}
