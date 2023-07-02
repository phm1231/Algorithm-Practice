// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int k, m, p;
vector<vector<int> > tree;
vector<vector<int> > out;
vector<int> strahler;
vector<int> inDegree;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> k >> m >> p; // 테케번호, 노드개수, 엣지개수
    tree.clear();
    tree.resize(m+1, vector<int>());
    out.clear();
    out.resize(m+1, vector<int>());
    strahler.clear();
    strahler.resize(m+1, 0);
    inDegree.clear();
    inDegree.resize(m+1, 0);

    int src, dst;
    for(int i=0; i<p; i++){
        cin >> src >> dst;
        tree[src].push_back(dst);
        out[dst].push_back(src);
        inDegree[dst]++;
    }
}

void solve()
{
    queue<int> q;
    // 강의 시작 부분에 대해서
    for(int i=1; i<=m; i++){
        if(inDegree[i] == 0){
            q.push(i);
            strahler[i] = 1;
        }
    }

    while(!q.empty()){
        // here은 strahler 값이 결정됨.
        int here = q.front();
        q.pop();

        for(int next: tree[here]){
            inDegree[next]--;
            // strahler 값을 결정할 수 있다면
            if(inDegree[next] == 0){
                // next에 연결된 다른 강들을 추후에 처리하기 위해 q에 넣는다.
                q.push(next);

                // next의 strahler 값을 계산한다.
                int maxNum = 0;
                int cnt = 0;
                for(int i=0; i<out[next].size(); i++){
                    int from = out[next][i]; // from은 next로 흘러들어오는 강물.
                    if(maxNum < strahler[from]){
                        maxNum = strahler[from];
                        cnt = 1;
                    }
                    else if(maxNum == strahler[from]) cnt++;
                }
                if(cnt == 1) strahler[next] = maxNum;
                else if(cnt > 1) strahler[next] = maxNum + 1;
            }
        }
    }

    int answer = 0;
    for(int s: strahler) answer = max(s, answer);
    cout << k << ' ' << answer << "\n";
}

int main()
{
    init();
    int t;
    cin >> t;
    while(t--){
        input();
        solve();
    }
    return 0;
}