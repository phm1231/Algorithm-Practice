// based problem:
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define ll long long
#define MAX 100001

int n, a, b;

void init();
void input();
void solve();

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> a >> b;
}

void solve()
{
    deque<int> answer;

    for(int i=1; i<a; i++){
        n--;
        if(n < 0){
            cout << -1;
            return;
        }
        answer.push_back(i);
    }

    n--;
    answer.push_back(max(a, b));
    if(n < 0){
        cout << -1;
        return;
    }

    for(int i=b-1; i>=1; i--){
        n--;
        if(n < 0){
            cout << -1;
            return;
        }
        answer.push_back(i);
    }

    cout << answer.front() << ' ';
    while(n > 0){
        n--;
        cout << 1 << ' ';
    }
    for(int i=1; i<answer.size(); i++){
        cout << answer[i] << ' ';
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}