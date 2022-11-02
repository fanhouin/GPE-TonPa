#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;
const int maxn = 100001;
int nums[maxn];
vector<int> p;

int main(){
    // create the prime table
    for(int i = 2; i < maxn; i++){
        if(nums[i] == 1) continue;
        for(int j = i+i; j < maxn; j+=i){
            nums[j] = 1;
        }
        p.emplace_back(i);
    }

    int n;
    while(cin >> n && n != 0){
        int count = 0;
        for(int i = 0; p.at(i) <= n; i++){
            int sum = 0;
            for(int j = i; sum < n; j++){
                sum += p[j];
                if(sum == n){
                    count++;
                    break;
                }
            }
        }
        cout << count << endl;

    }
}
