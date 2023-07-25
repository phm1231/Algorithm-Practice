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
vector<int> v;
vector<int> leftSizs;
vector<int> rightSizs;
vector<int> lefts;
vector<int> rights;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    v.resize(n+1, 0);
    leftSizs.resize(n+1, 0);
    rightSizs.resize(n+1, 0);
    lefts.resize(n+1, 0);
    rights.resize(n+1, 0);
    for(int i=1; i<=n; i++) cin >> v[i];
}

void solve()
{
    // 자신의 높이보다 큰 건물만 볼 수 있음.
    // 좌측으로
    for(int here=1; here<=n; here++){
        int next = here - 1;
        while(next != 0){
            if(v[here] < v[next]){
                lefts[here] = next;
                leftSizs[here] = leftSizs[next] + 1;
                break;
            }
            else next = lefts[next];
        }
    }
    // 우측으로
    for(int here=n; here>=1; here--){
        int next = here + 1;
        if(next == n+1) continue;

        while(next != 0){
            if(v[here] < v[next]){
                rights[here] = next;
                rightSizs[here] = rightSizs[next] + 1;
                break;
            }
            else next = rights[next];
        }
    }

    // 정답 출력
    for(int here=1; here<=n; here++){

        if(lefts[here] == 0 && rights[here] == 0){
            cout << 0 << "\n";
            continue;
        }
        // 좌우에 존재함.
        if(lefts[here] != 0 && rights[here] != 0){
            int leftgap = abs(lefts[here] - here);
            int rightgap = abs(rights[here] - here);
            int siz = leftSizs[here] + rightSizs[here];

            if(leftgap <= rightgap) cout << siz << " " << lefts[here] << "\n";
            else cout << siz << " " << rights[here] << "\n";
        }
        // 한쪽에만 존재함.
        else if(lefts[here] == 0) cout << rightSizs[here] << " " << rights[here] << "\n";
        else if(rights[here] == 0) cout << leftSizs[here] << " " << lefts[here] << "\n";
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}