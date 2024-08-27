//匈牙利算法解决二分图匹配问题
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<functional>
using namespace std;
int main() {
    int n1,n2,m;
    cin >> n1 >> n2 >> m;
    vector<vector<int>> g(n1 + 1);
    while(m--) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    vector<bool> vis(n2 + 1,false);
    vector<int> match(n2 + 1,0);
    function<bool(int)> find = [&] (int x) {//判断x是否已经匹配
        for(const auto& j : g[x]) {
            if(!vis[j]) {
                vis[j] = true;
                if(match[j] == 0 || find(match[j])) {//如果j没有匹配 或者 j匹配的点已经匹配了 则让j与x匹配
                    match[j] = x;
                    return true;
                }
            }
        }
        return false;
    };
    int res = 0;
    for(int i = 1; i <= n1; i ++) {
        fill(vis.begin(), vis.end(), false);  // 每次尝试匹配新节点时，都需要重置vis数组
        if(find(i)) res ++;
    }
    cout << res << '\n';

    return 0;
}