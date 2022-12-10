#include <iostream>
#include <queue>
using namespace std;

bool find(int n, int m){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    int cnt = 0;
    while(q.size() > 1){
        int tmp = q.front();
        q.pop();

        if(cnt++ % m != 0)
            q.push(tmp);
    }

    return q.front() == 13;
}

int main(){

    int n, m;
    while(cin >> n && n != 0){
        for(m = 1; ; m++){
            if(find(n, m)){
                cout << m << endl;
                break;
            }
        }
    }
    return 0;
}
