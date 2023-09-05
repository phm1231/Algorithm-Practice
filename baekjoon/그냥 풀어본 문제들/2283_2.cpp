#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define MAX 1000001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int n, k;
int minLeft = MAX;
int maxRight = -1;
ll accum[MAX] = {0, };

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        minLeft = min(minLeft, a);
        maxRight = max(maxRight, b);
        accum[a]++;
        accum[b]--;
    }
}

void solve()
{
    for(int i=1; i<=maxRight; i++){
        accum[i] += accum[i-1];
    }
    for(int i=1; i<=maxRight; i++){
        accum[i] += accum[i-1];
    }

    int left = 0;
    int right = 1;

    while(1){
        if(right > maxRight) break;

        ll value = accum[right] - accum[left];
        // 너무 짧음.
        if(value < k){
            right++;
        }
        else if(value == k){
            cout << left + 1 << " " << right + 1;
            return;
        }
        // 너무 김
        else if(value > k){
            left++;
        }
    }
    cout << "0 0";
}


int main()
{
    init();
    input();
    solve();
    return 0;
}