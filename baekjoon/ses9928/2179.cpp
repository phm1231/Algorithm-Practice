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
vector<string> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}

void solve()
{
    int answer = 0;
    string s = "";
    string t = "";

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){

            int siz = min(v[i].size(), v[j].size());
            int cnt = 0;

            for(int k=0; k<siz; k++){
                if(v[i][k] == v[j][k]) cnt++;
                else break;
            }
        
            if(answer < cnt){
                answer = cnt;
                s = v[i];
                t = v[j];
            }

        }
    }

    cout << s << "\n" << t;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}