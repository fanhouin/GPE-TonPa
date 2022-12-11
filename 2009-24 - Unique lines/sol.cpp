#include <iostream>
#include <set>
#include <vector>
#include <limits>
#include <utility>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        int num;
        cin >> num;
        vector<pair<int, int>> points(num);
        for(int i = 0; i < num; i++){
            cin >> points[i].first >> points[i].second;
        }

        // y = mx + b
        // set<m, b>
        set<pair<double, double>> slopes;
        for(int i = 0; i < num; i++){
            for(int j = i + 1; j < num; j++){
                if(points[i].first == points[j].first){
                    slopes.insert(make_pair(numeric_limits<double>::infinity(), (double)(points[i].first)));
                }
                else {
                    double m = (points[j].second - points[i].second) / (double)(points[j].first - points[i].first);
                    double b = points[j].second - m * points[j].first;
                    slopes.insert(make_pair(m, b));
                }
            }
        }
        cout << slopes.size() << endl;

    }

    return 0;
}
