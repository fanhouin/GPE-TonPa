#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;
int main(){
    int N;
    cin >> N;

    while(N--){
        int n;
        cin >> n;
        vector<double> v(n);
        vector<double> p(n);
        for(int i = 0; i < n; i++){
            cin >> v.at(i);
        }
        sort(v.begin(), v.end());

        double ans = 9999999999;
        do{
            p.at(0) = v.at(0);
            double cur = 2 * v.at(0);
            for(int i = 1; i < n; i++){
                p.at(i) = v.at(i);
                for(int j = 0; j < i; j++){
                    p.at(i) = max(p.at(i), p.at(j) + 2 * sqrt(v.at(i) * v.at(j)));
                }
                cur = max(cur, p.at(i) + v.at(i));
            }
            ans = min(ans, cur);

        }
        while(next_permutation(v.begin(), v.end()));

        printf("%.3lf\n", ans);
    }


    return 0;
}
