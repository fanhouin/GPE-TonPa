#include <iostream>

using namespace std;


int main(){
    unsigned int N, L, U;
    while(cin >> N){
        cin >> L >> U;
        unsigned int ans =0;
        for(int i = 31; i >= 0; i--){
            if((ans | (1 << i)) > U) continue;
            if((ans | (1 << i)) <= L || !(N & (1 << i))){
                ans |= (1 << i);
            }
        }

        cout << ans << endl;
    }


    return 0;
}
