// based problem:
#include <iostream>
#include <vector>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, s;
vector<ll> seqs;
vector<ll> sums;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> s;
    seqs.resize(n+1, 0);
    for(int i=1; i<=n; i++) cin >> seqs[i];

}

void solve()
{
    for(int i=1; i<=n; i++){
        if(seqs[i] >= s){
            cout << 1;
            return;
        }
    }

    sums.resize(n+1, 0);
    sums[1] = seqs[1];
    for(int i=2; i<=n; i++) sums[i] = sums[i-1] + seqs[i];
    
    int left = 0;
    int right = left + 1;
    int answer = 987654321;

    while(1){
        // s 이상임
        if(sums[right] - sums[left] >= s){
            answer = min(right - left, answer);
            left++;
        }
        else{
            right++;
        }

        if(right > n || left > n) break;
    }

    if(answer == 987654321) cout << 0;
    else cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}