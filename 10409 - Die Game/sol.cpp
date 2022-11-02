#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        int north = 2, south = 5, west = 3, east = 4, up = 1, down = 6;
        string s;
        int tmp;
        while(n--){
            cin >> s;
            if(s == "north"){
                tmp = north;
                north = up;
                up = south;
                south = down;
                down = tmp;
            }
            else if(s == "south"){
                tmp = down;
                down = south;
                south = up;
                up = north;
                north = tmp;
            }
            else if(s == "west"){
                tmp = west;
                west = up;
                up = east;
                east = down;
                down = tmp;
            }
            else if(s == "east"){
                tmp = down;
                down = east;
                east = up;
                up = west;
                west = tmp;
            }
        }
        cout << up << endl;
    }

}
