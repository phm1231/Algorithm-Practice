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

int n, k; // 건물의 개수, 규칙의 개수
int target;
vector<int> times;
vector<int> inDegree;
vector<vector<int> > tree; // tree[i] = i번 건물을 지은 후에야 지을 수 있는 건물 집합

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;

    // 초기화
    times.clear();
    inDegree.clear();
    tree.clear();
    times.resize(n+1, 0);
    inDegree.resize(n+1, 0);
    tree.resize(n+1, vector<int>());

    for(int i=1; i<=n; i++) cin >> times[i];
    int src, dst;
    for(int i=0; i<k; i++){
        cin >> src >> dst;
        tree[src].push_back(dst);
        inDegree[dst]++;
    }
    cin >> target;
}   

void solve()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // 기본은 내림차순 정렬임.
    for(int i=1; i<=n; i++){
        // 건물을 지을 수 있는 상황이라면
        if(inDegree[i] == 0){
            pq.push(make_pair(times[i], i));
        }
    }

    int current = 0;
    while(!pq.empty()){
        int time = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        // pq.top()을 하지 않으면 아무것도 할 수 없는 상황이므로 시간을 정해주어야 함.
        if(current < time) current = time;
        if(here == target) cout << current << "\n";
        for(int next: tree[here]){
            inDegree[next]--;
            if(inDegree[next] == 0){
                pq.push(make_pair(current + times[next], next));
            }
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