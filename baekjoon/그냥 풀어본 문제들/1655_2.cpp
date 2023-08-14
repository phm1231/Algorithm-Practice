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


void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{

}

void solve()
{
    int n;
    cin >> n;
    priority_queue<int> maxQ; // 최대
    priority_queue<int, vector<int>, greater<int> > minQ;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;

        // 항상 maxQ size >= minQ size
        
        if(maxQ.empty()) maxQ.push(tmp);
        else if(maxQ.size() == minQ.size()) maxQ.push(tmp);
        else minQ.push(tmp);

        // 항상 maxQ.top <= minQ.top
        if(!maxQ.empty() && !minQ.empty() && !(maxQ.top() <= minQ.top())){
            int maxTop = maxQ.top();
            int minTop = minQ.top();

            maxQ.pop(), minQ.pop();
            maxQ.push(minTop), minQ.push(maxTop);
        }

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