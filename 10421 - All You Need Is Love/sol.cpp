#include<iostream>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b){
    if(b == 0)
        return a;

    return gcd(b, a%b);
}


int main(){
    int n;
    cin >> n;

    for(int round = 1; round <= n; round++){
        string s1, s2;
        cin >> s1 >> s2;
        unsigned long long num1 = 0, num2 = 0;
        for(int i = 0; i < s1.size(); i++){
            num1 *= 2;
            num1 += s1.at(i) - '0';
        }

        for(int i = 0; i < s2.size(); i++){
            num2 *= 2;
            num2 += s2.at(i) - '0';
        }
        int a = gcd(num1,num2);
        if(gcd(num1,num2) == 1){
            cout << "Pair #" << round << ": Love is not all you need!" << endl;
        }
        else{
            cout << "Pair #" << round << ": All you need is love!" << endl;
        }

    }

    return 0;
}
