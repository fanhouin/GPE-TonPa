#include <iostream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

class Node{
public:
    Node(string _name) :
         name(_name){}

map<string, Node *> m;
string name;
};

void dfs(Node* &node, int deep){
    for(int i = 0; i < deep; i++)
        cout << " ";
    cout << node->name << endl;

    if(node->m.empty()) return;
    for(auto &child : node->m){
        dfs(child.second, deep+1);
    }

}

int main(){
    int n;
    string str;
    cin >> n;

    Node *root = new Node("00");

    while(n--){
        cin >> str;
        string d = "\\";
        char *sub;
        Node *tmp = root;

        sub = strtok((char *)str.c_str(), d.c_str());

        while(sub){
            string subs = string(sub);
            if(tmp->m.count(subs) <= 0){
                tmp->m[subs] = new Node(subs);
            }
            tmp = tmp->m[subs];
            sub = strtok(NULL, d.c_str());
        }
    }

    for(auto &child : root->m){
        dfs(child.second, 0);
    }
}
