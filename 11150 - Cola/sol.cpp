#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int sum = n;
        int em = n;

        while(em >= 3){
            sum += em / 3;
            em = (em / 3) + (em % 3);
        }

        sum = (em / 2 == 1)? sum+1:sum;
        cout << sum << endl;
    }

    return 0;
}
