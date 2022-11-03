#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int xMove[] = {-1, 0, 1, 1, 0, 0, -1};
int yMove[] = {0, -1, -1, 0, 1, 1, 1};


int main(){
    vector<int> v = {1};
    int n = 0;
    int sum = 1;
    while(sum <= 10000){
        sum += 6*n++ + 1;
        v.emplace_back(sum);
    }

    int Num;
    while(cin >> Num){
        auto it = upper_bound(v.begin(), v.end(), Num);
        int move = it - v.begin() -1;
        int startNum = v.at(move);
        int x = 0, y = move;

        int distance = Num - startNum;
        for(int count = 0; distance > 0; count++){
            int t_move = min(distance, move);
            if(count == 5)
                t_move = min(1, move);
            x += xMove[count] * t_move;
            y += yMove[count] * t_move;
            distance -= t_move;
        }
        cout << x << " " << y << endl;
    }

    /*vector<int> v = {1};
    int sum = 1;
    int n = 0;
    while(sum <= 10000){
        sum += 6*n++ + 1;
        v.emplace_back(sum);
    }*/

    /*int Num;
    while(cin >> Num){
        if(Num <= 0) break;
        auto it = upper_bound(v.begin(), v.end(), Num);
        int move = it - v.begin() - 1;
        int startNum = v.at(move);
        int x = 0, y = move;

        int count = 0;
        for(int i = startNum, count = 0; i < Num; i++, count++){
            x += xMove[count / move];
            y += yMove[count / move];
            if(count / move == 5){
                count += move;
            }
        }

        cout << x << " " << y << endl;
    }*/


}
