#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string str;
    int left = 1;
    while(getline(cin, str)){
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '\"' && left){
                str[i] = '`';
                str.insert(i+1, "`");
                left = 0;
            }
            else if(str[i] == '\"' && !left){
                str[i] = '\'';
                str.insert(i+1, "\'");
                left = 1;
            }
        }
        for(auto e : str){
            cout << e;
        }
        cout << endl;
    }

}
