#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int m ,n;
void dfs(vector<vector<char>> &map, int x, int y, char chr){
    if(x < 0 || y < 0 || x >= m || y >= n || map[x][y] == '0' || map[x][y] != chr){
        return;
    }

    map[x][y] = '0';
    dfs(map, x+1, y, chr);
    dfs(map, x-1, y, chr);
    dfs(map, x, y+1, chr);
    dfs(map, x, y-1, chr);
}

typedef struct{
    char chr;
    int count;
}CC;

bool cmp(CC a, CC b){
    if(a.count == b.count){
        return a.chr < b.chr;
    }
    return a.count > b.count;
}

int main(){
    int N;
    cin >> N;
    int NN = N;
    while(N--){
        cin >> m >> n;
        string s;
        vector<CC> cc(26);

        for(int i = 0; i < 26; i++){
            cc[i].chr = 'a'+i;
            cc[i].count = 0;
        }
        vector<vector<char>> map(m, vector<char>(n, '0'));

        for(int i = 0; i < m; i++){
            cin >> s;
            for(int j = 0; j < n; j++){
                map[i][j] = s[j];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(map[i][j] == '0') continue;
                cc[map[i][j]-'a'].count++;
                dfs(map, i, j, map[i][j]);
            }
        }


        sort(cc.begin(), cc.end(), cmp);

        cout << "World #" << NN - N << endl;
        for(auto &e : cc){
            if(e.count == 0) continue;
            cout << e.chr << ": " << e.count << endl;
        }

    }

}
