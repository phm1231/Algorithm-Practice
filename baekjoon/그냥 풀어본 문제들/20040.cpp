// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int getParent(int child);
void merge(int a, int b);

int n, m; // 개수, 진행된 차례
vector<pair<int, int> > cmds;
vector<int> parent;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    parent.resize(n, 0);
    for(int i=0; i<n; i++) parent[i] = i;
    for(int i=0; i<m; i++){
        int src, dst;
        cin >> src >> dst;
        cmds.push_back(make_pair(src, dst));
    }
}

void solve()
{
    for(int i=1; i<=m; i++){
        int src = cmds[i-1].first;
        int dst = cmds[i-1].second;
        int psrc = getParent(src);
        int pdst = getParent(dst);
        
        if(psrc == pdst){
            cout << i << "\n";
            return;
        }
        else{
            merge(src, dst);
        }
    }
    cout << 0 << "\n";
}

int getParent(int child){
    if(child == parent[child]) return child;
    else return parent[child] = getParent(parent[child]);
}

void merge(int a, int b){
    int pa = getParent(a);
    int pb = getParent(b);
    parent[pa] = pb;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}