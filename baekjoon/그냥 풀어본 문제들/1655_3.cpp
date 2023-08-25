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
    priority_queue<int, vector<int>, less<int> > maxQ;
    priority_queue<int, vector<int>, greater<int> > minQ;

    // maxQ의 사이즈가 항상 minQ와 같거나 1 커야 하며
    // maxQ의 top은 minQ의 top보다 작거나 같아야 한다.
    for(int i=0; i<n; i++){
        int number;
        cin >> number;

        if(maxQ.empty()) maxQ.push(number);
        else if(maxQ.size() == minQ.size()) maxQ.push(number);
        else minQ.push(number);

        if(!maxQ.empty() && !minQ.empty() && !(maxQ.top() <= minQ.top())){
            int maxTop = maxQ.top();
            maxQ.pop();
            int minTop = minQ.top();
            minQ.pop();

            maxQ.push(minTop);
            minQ.push(maxTop);
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
