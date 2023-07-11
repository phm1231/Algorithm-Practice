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

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
}

void solve()
{
    priority_queue<int> maxQ; // 작은 값들 중 최댓값
    priority_queue<int, vector<int>, greater<int> > minQ; // 큰 값들 중 최솟값

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;

        // 최대 힙의 크기는 최소 힙의 크기보다 같거나 1개 더 크다.
        if(maxQ.empty()) maxQ.push(tmp);
        else if(maxQ.size() == minQ.size()) maxQ.push(tmp);
        else minQ.push(tmp);

        // 최대 힙의 top은 최소 힙의 top보다 작거나 같아야한다.
        if(!maxQ.empty() && !minQ.empty() && !(maxQ.top() <= minQ.top())){
            // 그렇지 않으면 swap한다.
            int maxTop = maxQ.top();
            int minTop = minQ.top();
            maxQ.pop();
            minQ.pop();

            maxQ.push(minTop);
            minQ.push(maxTop);
        }
        // 최대 힙의 Top은 항상 중간값이다.
        cout << maxQ.top() << "\n";
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}