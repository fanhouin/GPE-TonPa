#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int main(){
    vector<string> word_list;
    string str;
    while(getline(cin, str) && str[0] != '0'){
        string tmp = "";
        int value = 0;
        for(int i = 0; i < str.size(); i++){
            if(isalpha(str[i])){
                tmp = "";
                while(isalpha(str[i])){
                    tmp += str[i++];
                }
                word_list.push_back(tmp);
                i--;
                cout << tmp;
            }
            else if(isdigit(str[i])){
                value = 0;
                while(isdigit(str[i])){
                    value = value * 10 + str[i++] - '0';
                }
                i--;

                tmp = word_list[word_list.size() - value];
                word_list.erase(word_list.end() - value);
                word_list.push_back(tmp);
                cout << tmp;
            }
            else{
                cout << str[i];
            }
        }
        cout << endl;
    }

}
