#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    getchar();

    while(n--){
        string input;
        vector<int> weights;
        int sum = 0;
        int weight;

        getline(cin, input);
        stringstream ss(input);
        while(ss >> weight){
            weights.push_back(weight);
            sum += weight;
        }

        if(sum % 2 == 1){
            cout << "NO" << endl;
            continue;
        }
        sum /= 2;
        sort(weights.begin(), weights.end());

        vector<int> arr(sum + 1, 0);

        for(int i = 0; i < weights.size(); i++){
            for(int j = sum; j >= weights[i]; j--){
                arr[j] = max(arr[j], arr[j - weights[i]] + weights[i]);
            }
        }

        if(arr[sum] == sum)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        arr.clear();
        weights.clear();
    }

}
