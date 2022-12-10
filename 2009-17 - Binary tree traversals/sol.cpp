#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int searchRoot(string *in, string ch, int n){
    for(int i = 0; i < n; i++){
        if(in[i] == ch)
            return i;
    }
    return -1;
}

void printPost(string *in, string *pre, int n){

    int root = searchRoot(in, pre[0], n);

    if(root != 0)
        printPost(in, pre + 1, root);

    if(root != n - 1)
        printPost(in + root + 1, pre + root + 1, n - root - 1);

    cout << pre[0] << " ";
}


int main(){
    int round;
    cin >> round;
    while(round--){
        int size;
        string s;
        vector<string> in, pre;
        cin >> size;
        for(int i = 0; i < size; i++){
            cin >> s;
            pre.emplace_back(s);
        }
        for(int i = 0; i < size; i++){
            cin >> s;
            in.emplace_back(s);
        }

        printPost(&in[0], &pre[0], size);
        cout << endl;
    }

}
