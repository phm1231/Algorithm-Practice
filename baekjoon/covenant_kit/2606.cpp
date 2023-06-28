// based problem:
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, m;
vector<vector<int> > tree;
vector<bool> isInfected;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    tree.resize(n+1, vector<int>());
    isInfected.resize(n+1, false);
    for(int i=0; i<m; i++){
        int src, dst;
        cin >> src >> dst;
        tree[src].push_back(dst);
        tree[dst].push_back(src);
    }
}

void solve()
{
    stack<int> stk;
    stk.push(1);
    isInfected[1] = true;
    int answer = 0;

    while(!stk.empty()){
        int here = stk.top();
        stk.pop();
        for(int i=0; i<tree[here].size(); i++){
            int next = tree[here][i];
            if(!isInfected[next]){
                isInfected[next] = true;
                answer++;
                stk.push(next);
            }
        }
    }
    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}