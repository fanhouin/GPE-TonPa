#include <iostream>
#include <cstring>
using namespace std;
int main(){
    long long people, day;
    while(cin >> people >> day){
        while(day > 0){
            day -= people++;
        }
        people--;

        cout << people << endl;

    }
}
