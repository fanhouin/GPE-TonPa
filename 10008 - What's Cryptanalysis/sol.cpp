#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct{
    char chr;
    int count;
}CC;


bool cmp(CC a, CC b){
    if(a.count == b.count)
        return a.chr < b.chr;
    return a.count > b.count;
}

int main(){
    vector<CC> arr(26);
    for(int i = 0; i < arr.size(); i++){
        arr[i].chr = 'A'+i;
        arr[i].count = 0;
    }

    int n;
    cin >> n;
    getchar();
    while(n--){
        string s;
        getline(cin, s);
        for(auto e : s){
            if(e >= 'a' && e <= 'z')
                arr.at(e-'a').count++;
            else if(e >= 'A' && e <= 'Z')
                arr.at(e-'A').count++;
        }
    }

    sort(arr.begin(), arr.end(), cmp);
    for(auto e : arr){
        if(e.count == 0) continue;
        cout << e.chr << " " << e.count <<  endl;
    }

    return 0;
}
