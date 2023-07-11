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

int n, m; //개수, 타겟
vector<int> inDegree;
queue<int> q;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    inDegree.clear();
    inDegree.resize(10, 0);

    while(!q.empty()) q.pop();

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp; // 중요도
        q.push(tmp);

        for(int j=tmp-1; j>0; j--){
            inDegree[j]++;
        }
    }
}

void solve()
{
    int cnt = 0;
    while(!q.empty()){
        int here = q.front();
        q.pop();

        // 뽑을 수 있는 문서인가?
        if(inDegree[here] == 0){
            // 뽑는다.
            cnt++;
            // m번째 문서인가?
            if(m == 0){
                cout << cnt << "\n";
                return;
            }

            m--; // m의 위치가 줄어든다.
            for(int i=here-1; i>0; i--){
                if(inDegree[i] > 0) inDegree[i]--;
            }
        }
        else{
            m--;
            q.push(here);
            if(m == -1) m = q.size() - 1;
        }
    }
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