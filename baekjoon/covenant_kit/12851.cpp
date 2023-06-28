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

int n, k;
int answer, cnt;
vector<int> dist(100001, 987654321);
vector<int> cnts(100001, 0);

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
}

void solve()
{
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    cnts[n] = 1;

    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(int next: {here*2,here+1, here-1}){
            if(next > 100000 || next < 0) continue;

            // 첫방문이 아니라면
            if(dist[next] != 987654321){
                // 재방문 거리가 동일하다면 처리해준다.
                if(dist[here] + 1 == dist[next]) cnts[next] += cnts[here];
                // Q를 사용할 때 첫 방문한 것은 최소 거리라는 것이 보장되어 있음.
                continue;
            }
            dist[next] = dist[here] + 1;
            cnts[next] = cnts[here];
            q.push(next);
        }
    }
    cout << dist[k] << "\n" << cnts[k] << endl;
}
int main()
{
    init();
    input();
    solve();
    return 0;
}