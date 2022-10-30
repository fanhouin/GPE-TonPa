#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef struct{
    int num;
    int mod;
    int odd;
}Num;

bool cmp(Num a, Num b){
    if(a.mod == b.mod){
        if(a.odd == 0 && b.odd == 0)
            return a.num < b.num;
        else if(a.odd == 1 && b.odd == 1)
            return a.num > b.num;
        else if(a.odd == 1 && b.odd == 0)
            return true;
        else
            return false;
    }
    return a.mod < b.mod;
    /*if(a.mod != b.mod)
        return a.mod < b.mod;
    if(a.odd != b.odd)
        return a.odd;
    if(a.odd)
        return a.num > b.num;
    return a.num < b.num;*/
}

int main(){
    int n, m, num;
    while(cin >> n >> m){
        vector<Num> arr;
        cout << n << " " << m << endl;
        if(n == 0 && m == 0)
            break;

        for(int i = 0; i < n; i++){
            cin >> num;
            arr.push_back({num, num % m, num & 1});
        }
        sort(arr.begin(), arr.end(), cmp);
        for(auto e : arr){
            cout << e.num << endl;
        }
    }

}
