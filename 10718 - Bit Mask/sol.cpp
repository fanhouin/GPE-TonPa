#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
    int num;
    int orr;
}Num;

bool cmp(Num a, Num b){
    if(a.orr == b.orr){
        return a.num < b.num;
    }
    return a.orr > b.orr;
}

int main(){
    int N, L, U;
    while(cin >> N){
        cin >> L >> U;
        vector<Num> v;
        for(int i = L; i <= U; i++){
            v.push_back({i, i|N});
        }

        sort(v.begin(), v.end(), cmp);
        cout << v[0].num << endl;

        v.clear();
    }

    return 0;
}
