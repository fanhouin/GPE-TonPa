#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    int N;
    while(cin >> N && N != 0){
        int num;
        vector<int> v(N, 0);
        vector<int> dp(N+1, 0);
        for(int i = 0; i < N; i++){
            cin >> num;
            v.at(i) = num;
        }

        int win = 0;
        for(int i = 0; i < N; i++){
            dp[i+1] = max(0, dp[i] + v[i]);
            win = max(dp[i+1], win);
        }

        if(win <= 0){
            cout << "Losing streak." << endl;
        }
        else{
            cout << "The maximum winning streak is " << win << "." << endl;
        }

    }


    return 0;
}
