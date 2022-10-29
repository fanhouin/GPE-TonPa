#include<iostream>
#include<stdio.h>
using namespace std;

#define kuti    10000000
#define lakh    100000
#define hajar   1000
#define shata   100

void checknum(long long num){
    if(num == 0) return;

    if(num / kuti){
        checknum(num / kuti);
        cout << " kuti";
        num %= kuti;
    }

    if(num / lakh){
        checknum(num / lakh);
        cout << " lakh";
        num %= lakh;
    }

    if(num / hajar){
        checknum(num / hajar);
        cout << " hajar";
        num %= hajar;
    }

    if(num / shata){
        checknum(num / shata);
        cout << " shata";
        num %= shata;
    }

    if(num)
        printf("% lld", num);
}

int main(){
    long long num;
    int n = 1;
    while(cin >> num){
        printf("%4d.", n);
        if(num)
            checknum(num);
        else
            cout << " 0";
        cout << endl;
        n++;
    }
}
