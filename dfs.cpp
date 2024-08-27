#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<functional>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    auto add = [&] (int a, int b) {
        g[a].push_back(b);
    };
    while(m--) {
        int a,b;
        cin >> a >> b;
        add(a,b),add(b,a);
    }
    vector<int> color(n + 1,-1);
    function<bool(int,int)> dfs = [&] (int u,int c) {
        color[u] = c;
        for(const auto& j: g[u]) {
            if(color[j] == -1) {
                if(!dfs(j,1 - c)) return false;
            }
            else if(color[j] == c) return false;
        }
        return true;
    };
    bool flag = true;
    for(int i = 1 ; i <= n ; i ++) {
        if(color[i] == -1) {
            if(!dfs(i,0)){
                flag = false;
                break;
            }
        }
    }
    if(!flag) puts("NO");
    else puts("YES");

    return 0;
}

