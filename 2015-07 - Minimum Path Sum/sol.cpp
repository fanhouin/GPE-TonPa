#include <iostream>
#include <vector>
using namespace std;

int main(){

    int N;
    cin >> N;
    while(N--){
        int m, n;
        cin >> m >> n;
        vector<vector<int>> mm(m, vector<int>(n,0));
        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> mm.at(i).at(j);
            }
        }
        dp[0][0] = mm[0][0];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                if(i == 0){
                    dp[i][j] = dp[i][j-1] + mm[i][j];
                }
                else if(j == 0){
                    dp[i][j] = dp[i-1][j] + mm[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j] + mm[i][j], dp[i][j-1] + mm[i][j]);
                }
            }
        }
        cout << dp[m-1][n-1] << endl;

    }

    return 0;
}
