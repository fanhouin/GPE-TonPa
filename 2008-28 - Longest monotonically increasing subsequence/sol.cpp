#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    int num;
    vector<vector<int>> SS;
}Info;

bool cmp(vector<int> a, vector<int> b){
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i])
            continue;
        return a[i] > b[i];
    }

}

vector<int> v;
int main(){
    int n;
    cin >> n;
    while(n--){
        int N;
        int num;
        cin >> N;
        while(N--){
            cin >> num;
            v.emplace_back(num);
        }
        vector<Info> dp(v.size(), {1,vector<vector<int>>()});
        for(int i = 0; i < v.size(); i++){
            bool ok = false;
            for(int j = 0; j < i; j++){
                if(v.at(i) > v.at(j)){
                    dp[i].num = max(dp[j].num + 1, dp[i].num);
                    // i比j大, 代表可以準備串seq
                    ok = true;
                }
            }
            if(ok){
                for(int j = 0; j < i; j++){
                    if(dp[i].num == dp[j].num + 1 && v.at(i) > v.at(j)){
                        vector<vector<int>> SS = dp[j].SS;
                        // 如果dp[i].SS是empty，要把v[j]值Push到SS中j
                        if(SS.empty()){
                            SS.emplace_back(vector<int>(1, v.at(j)));
                        }
                        // 把v[i]的值push到SS中每個arr
                        for(int a = 0; a < SS.size(); a++){
                            vector<int> tmp = SS[a];
                            tmp.emplace_back(v.at(i));
                            dp[i].SS.push_back(tmp);
                        }
                    }
                }
            }
        }

        int max = -1;
        for(auto e : dp){
            if(max < e.num) max = e.num;
        }

        // 如果max=1，代表上面沒有做過串seq的動作，要新增一個v[i]的值進dp[i].SS中
        if(max == 1){
            for(int i = 0; i < dp.size(); i++){
                dp[i].SS.emplace_back(vector<int>(1, v.at(i)));
            }
        }

        vector<int> max_idx_v;
        for(int i = 0; i < dp.size(); i++){
            if(dp[i].num == max){
                max_idx_v.emplace_back(i);
            }
        }

        // 題目要把答案做sorting，idx[i]中value最大為優先
        vector<vector<int>> sortSS;
        for(int i = 0; i < max_idx_v.size(); i++){
            vector<vector<int>> SS = dp[max_idx_v[i]].SS;
            for(int j = 0; j < SS.size(); j++){
                sortSS.emplace_back(SS.at(j));
            }
        }
        sort(sortSS.begin(), sortSS.end(), cmp);

        cout << sortSS.size() << endl;
        for(int i = 0; i < sortSS.size(); i++){
            for(int j = 0; j < sortSS.at(i).size(); j++){
                cout << sortSS.at(i).at(j) << " ";
            }
            cout << endl;
        }

        v.clear();
        dp.clear();

    }

}
