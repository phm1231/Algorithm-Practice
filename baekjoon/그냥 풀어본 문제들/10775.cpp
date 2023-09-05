#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();
void go();

int G, P, answer;
vector<bool> isDocked(100002, false);
vector<int> skip(100002, 0);
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> G >> P;
    for(int i=0; i<P; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}

void solve()
{
    go();
    cout << answer;
}

void go(){
    for(int here: v){
        if(!isDocked[here]){
            isDocked[here] = true;
            answer++;
            skip[here] = 1;
            continue;
        }
        else{
            while(1){
                int next = here - skip[here];
                if(next <= 0){
                    return;
                }
                if(isDocked[next]){
                    skip[here] += skip[next];
                    here = next;
                }
                else{
                    isDocked[next] = true;
                    skip[next] = 1;
                    skip[here] += skip[next];
                    answer++;
                    break;
                }
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