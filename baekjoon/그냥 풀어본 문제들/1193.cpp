// based problem:
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

void init();
void input();
void solve();

// 1 = 1/1
// 2 = 1/2
// 3 = 2/1
// 4 = 3/1
// 5 = 2/2
// 6 = 1/3
// 1 -> 1/1
// 2 3 -> 1/2, 2/1
// 4 6 -> 3/1, 2/2, 1/3
// 7 10 -> 1/4, 4/1
// 11 15 -> 5/1, 1/5

int n;

void init()
{
    FAST
}

void input()
{
    cin >> n;
}

void solve()
{
    if(n == 1) cout << "1/1";
    else{
        bool isLeftGap = false;
        int start = 2;
        int gap = 1;
        int end = start + gap;

        while(1){
            if(start <= n && n <= end) break;
            start = end + 1;
            gap++;
            end = start + gap;
            isLeftGap = !isLeftGap;
        }
        // gap + 1을 기준으로 시작함.
        // gap + 1이 left;
        if(isLeftGap){
            int left = gap+1;
            int right = 1;
            for(int i=start; i<n; i++){
                left--;
                right++;
            }
            cout << left << "/" << right;
        }
        else{
            int left = 1;
            int right = gap+1;
            for(int i=start; i<n; i++){
                left++;
                right--;
            }
            cout << left << "/" << right;            
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