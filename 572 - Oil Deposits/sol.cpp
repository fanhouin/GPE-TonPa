#include <iostream>
#include <cctype>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
int m, n;

void dfs(vector<vector<int>> &map, int x, int y){
    if(x < 0 || y < 0 || x >= m || y >= n || map[x][y] == 0)
        return;

    map[x][y] = 0;
    dfs(map, x+1, y);
    dfs(map, x-1, y);
    dfs(map, x, y+1);
    dfs(map, x, y-1);
    dfs(map, x+1, y+1);
    dfs(map, x+1, y-1);
    dfs(map, x-1, y+1);
    dfs(map, x-1, y-1);
}


int main(){
    while(cin >> m >> n && !(m == 0 && n == 0)){
        vector<vector<int>> map(m, vector<int>(n, 0));
        string s;
        for(int i = 0; i < m ; i++){
            cin >> s;
            for(int j = 0; j < n; j++){
                if(s[j] == '@')
                    map[i][j] = 1;
            }
        }

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(map[i][j] == 1){
                    dfs(map, i, j);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}
