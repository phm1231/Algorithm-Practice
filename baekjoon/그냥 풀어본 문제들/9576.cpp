#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
int t, n, m;
vector<bool> is_out;

const int MAX = 1e9;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    is_out.clear();
    cin >> n >> m;
    is_out.resize(n+1, false);
}

void Solve()
{
    priority_queue<pair<int, int> > pq; // 큰 값이 우선, 뒷값은 작은 거로
    int answer = 0;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        pq.push({a, -b});
    }
    while(!pq.empty()){
        int a = pq.top().first;
        int b = -pq.top().second;
        pq.pop();
        for(int i=b; i>=a; i--){
            if(!is_out[i]){
                is_out[i] = true;
                answer++;
                break;
            }
        }
    }
    cout << answer << endl;
}


int main()
{
    Init();
    cin >> t;
    while(t--){
        Input();
        Solve();
    }
    return 0;
}