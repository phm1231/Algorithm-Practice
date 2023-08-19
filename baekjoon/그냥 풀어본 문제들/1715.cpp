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

int n;
priority_queue<int, vector<int>, greater<int> > pq;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
}

void solve()
{
    int answer = 0;
    while(!pq.empty()){
        // 1개뿐이라면
        if(pq.size() == 1){
            cout << answer;
            return;
        }
        // 두 개를 뽑아서 합친 후 다시 넣어야 함.
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b); // 합쳐서 다시 넣는다.
        answer += (a+b);
    }
}


int main()
{
    init();
    input();
    solve();
    return 0;
}