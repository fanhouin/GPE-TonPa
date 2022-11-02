#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdio>

using namespace std;

bool getNum(stack<int> &s,int &a, int &b){
    if(s.size() < 2)
        return true;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return false;
}

bool isNum(string s){
    for(int j = 0; j < s.size(); j++){
        if(!isdigit(s[j])){
            return false;
        }
    }
    return true;
}

int main(){
    string str;

    while(getline(cin, str)){
        stack<int> s;
        vector<string> v;
        stringstream ss(str);
        string c;

        if(str.size() <= 1 || str[0] == '.')
            break;
        while(ss >> c){
            v.push_back(c);
        }

        bool err = false;
        for(int i = v.size() - 1; i >= 0; i--){
            int a, b;

            if(isNum(v[i])){
                s.push(stoi(v[i]));
                continue;
            }

            err = getNum(s,a,b);
            if(err) break;

            if(v[i] == "+"){
                s.push(a+b);
            }
            else if(v[i] == "-"){
                s.push(a-b);
            }
            else if(v[i] == "*"){
                s.push(a*b);
            }
            else if(v[i] == "/"){
                s.push(a/b);
            }
            else if(v[i] == "%"){
                s.push(a%b);
            }

        }

        if(err){
            cout << "illegal\n";
        }
        else{
            cout << s.top() << endl;
        }

    }



    return 0;
}
