#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    string str;
    int n;
    int num;
    while(cin >> n){
        vector<int> nums;
        vector<int> absnums;

        for(int i = 0; i < n; i++){
            cin >> num;
            nums.emplace_back(num);
        }
        for(int i = 0; i <  nums.size() - 1; i++){
            absnums.emplace_back(abs(nums[i] - nums[i+1]));
        }

        sort(absnums.begin(), absnums.end());
        int ok = 1;

        for(int i = 0; i < absnums.size(); i++){
            if(absnums[i] != i + 1){
                ok = 0;
                break;
            }
        }

        if(ok)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;

        /*for(auto e : absnums){
            cout << e <<" ";
        }
        cout << endl;*/

        nums.clear();
        absnums.clear();
    }
}
