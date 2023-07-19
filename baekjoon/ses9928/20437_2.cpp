// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

string str;
int k;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> str >> k;
}

void solve()
{
    vector<int> maxCnts(26, 0);
    vector<int> minCnts(26, 987654321);
    vector<vector<int> > v(26, vector<int>());

    for(int i=0; i<str.size(); i++){
        int idx = str[i] - 'a';
        v[idx].push_back(i); // v[i][j] = 알파벳 i의 인덱스는 v[i][j]임.
        if(v[idx].size() == k){
            int len = v[idx][k-1] - v[idx][0] + 1;
            // 어떤 문자를 k개 포함하는 가장 짧은 문자열의 길이
            minCnts[idx] = min(minCnts[idx], len);
            // 어떤 문자를 k개 포함하고, 어떤 문자로 시작하고 끝나는 가장 긴 문자열의 길이
            maxCnts[idx] = max(maxCnts[idx], len);

            // 시작부분 삭제.
            v[idx].erase(v[idx].begin());
        }
    }

    int maxAnswer = *max_element(maxCnts.begin(), maxCnts.end());
    int minAnswer = *min_element(minCnts.begin(), minCnts.end());
    if(maxAnswer == 0) cout << -1 << "\n";
    else cout << minAnswer << ' ' << maxAnswer << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        init();
        input();
        solve();
    }
    return 0;
}