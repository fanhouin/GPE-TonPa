#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void find(vector<int> &arr){
     for(int d = arr.size() - 1; d >= 0 ; d--){
        for(int a = 0; a < arr.size(); a++){
            for(int b = a + 1; b < arr.size(); b++){
                for(int c = b + 1; c < arr.size(); c++){
                    if((arr[d] == arr[a] + arr[b] + arr[c]) &&
                        a != d && b != d && c != d){
                            cout << arr[d] << endl;
                            return;
                        }
                }
            }
        }
    }
    cout << "no solution" << endl;
}

int main(){
    int n;
    vector<int> arr;
    while(cin >> n && n != 0){
        int num;
        while(n--){
            cin >> num;
            arr.emplace_back(num);
        }

        sort(arr.begin(), arr.end());
        find(arr);
        arr.clear();
    }

}
