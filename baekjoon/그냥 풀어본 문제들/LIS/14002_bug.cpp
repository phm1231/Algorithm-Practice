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

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    v.resize(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];
}

void solve()
{
    vector<int> dp(n, 0);
    vector<vector<int> > answer(n, vector<int>());

    answer[0].push_back(v[0]);
    dp[0] = 1;
    int answerIdx = -1;
    int maxLen = -1; // -1로 하면 안되고 1로 하면 된다.

    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(v[i] > v[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;

                answer[i].clear();
                for(int k=0; k<answer[j].size(); k++) answer[i].push_back(answer[j][k]);
                answer[i].push_back(v[i]);
                
                cout << "maxLen is " << maxLen << endl;
                cout << "answer[i].size is " << answer[i].size() << endl;

                if(maxLen < answer[i].size()){
                    maxLen = answer[i].size();
                    answerIdx = i;
                }
            }
        }
    }

    cout << "maxLen is " << maxLen << endl;
    cout << "answerIDx is " << answerIdx << endl;
    cout << "answer\n";
    for(int i=0; i<answer.size(); i++){
        for(int j=0; j<answer[i].size(); j++){
            cout << answer[i][j] << ' ';
        }
        cout << endl;
    }
   
    for(int i=0; i<answer[answerIdx].size(); i++) cout << answer[answerIdx][i] << ' ';

}

int main()
{
    init();
    input();
    solve();
    return 0;
}