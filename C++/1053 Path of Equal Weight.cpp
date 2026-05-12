#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    int weight;
    vector<int> children;
};
int N, M, S;
node n[100];
vector<int> path;
vector<vector<int>> ans;
// 专门用于对最终结果排序的比较函数（字典序降序）
bool cmp_ans(const vector<int>& a, const vector<int>& b) {
    int i = 0;
    while(i < a.size() && i < b.size() && a[i] == b[i]) i++;
    // 如果前面都一样，比较第一个不同的数字，大的排前面
    if (i < a.size() && i < b.size()) return a[i] > b[i];
    // 如果一个是另一个的前缀，长的排前面（虽然题目定义主要看第一个不同数，但这是标准字典序处理）
    return a.size() > b.size();
}
void dfs(int cur, int curweight){
    path.push_back(n[cur].weight);
    if (curweight > S) {
        path.pop_back();
        return;
    }
    // 叶子节点
    if(n[cur].children.empty()){
        if(curweight == S){
            ans.push_back(path);
        }
    }
    // 非叶子节点
    else{
        for(int each : n[cur].children){
            dfs(each, curweight + n[each].weight);
        }
    }
    path.pop_back();
}
int main(){
    int i, j, k;
    cin >> N >> M >> S;
    for(i = 0; i < N; i++) cin >> n[i].weight;
    while(M--){
        cin >> i >> j;
        while (j--){
            cin >> k;
            n[i].children.push_back(k);
        }
    }
    dfs(0, n[0].weight);
    // 最后统一排序，确保顺序正确
    sort(ans.begin(), ans.end(), cmp_ans);
    
    for(i = 0; i < ans.size(); i++){
        for(j = 0; j < ans[i].size(); j++){
            if(j > 0) cout << ' ';
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}