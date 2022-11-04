#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        vector<string> ins(1, "x");
        int n;
        int ans = 0;
        string in;
        cin >> n;
        getchar();
        while(n--){
            getline(cin, in);
            if(in[0] == 'S'){
                string tmp1, tmp2;
                int num;
                stringstream ss(in);
                ss >> tmp1 >> tmp2 >> num;
                in = ins.at(num);
            }

            if(in == "LEFT"){
                ans--;
                ins.emplace_back("LEFT");
            }
            else if(in == "RIGHT"){
                ans++;
                ins.emplace_back("RIGHT");
            }
        }
        cout << ans << endl;
    }

}
