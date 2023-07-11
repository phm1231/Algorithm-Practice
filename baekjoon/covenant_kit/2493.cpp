// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
vector<int> tops;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    tops.resize(n+1, 0);
    tops[0] = 987654321;
    for(int i=1; i<=n; i++) cin >> tops[i];
}

void solve()
{
    vector<int> receiver(n+1, 0); // receiver[i] = tops[i]의 수신자.
    
    for(int i=1; i<=n; i++){
        // 바로 앞.
        if(tops[i-1] >= tops[i]) receiver[i] = i-1;
        else{
            int next = i-1;
            while(1){
                if(tops[next] >= tops[i]){
                    receiver[i] = next;
                    break;
                }
                else{
                    next = receiver[next];
                }
            }
        }
    }

    for(int i=1; i<=n; i++) cout << receiver[i] << ' ';
}

int main()
{
    init();
    input();
    solve();
    return 0;
}