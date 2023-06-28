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

int n, m; // n명의 학생, m번 키를 비교함.
vector<vector<int> > v;
vector<int> indegree;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    v.resize(n+1, vector<int>());
    indegree.resize(n+1, 0);

    for(int i=0; i<m; i++){
        int a, b; // a가 b보다 작다.
        cin >> a >> b;
        v[a].push_back(b); // a보다 큰 사람들.
        indegree[b]++;
    }
}

void solve()
{
    queue<int> q;
    vector<bool> visited(n+1, false);

    for(int i=1; i<indegree.size(); i++){
        if(indegree[i] == 0){
            q.push(i);
            visited[i] = true;
        }
    }

    while(!q.empty()){
        int here = q.front();
        q.pop();

        cout << here << ' ';
        
        for(int i=0; i<v[here].size(); i++){
            int bigger = v[here][i];
            if(visited[bigger]) continue;

            indegree[bigger]--;
            if(indegree[bigger] == 0){
                q.push(bigger);
                visited[bigger] = true;
            }
        }
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}