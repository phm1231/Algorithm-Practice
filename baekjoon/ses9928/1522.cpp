// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

string str;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> str;
}

void solve()
{
    int a = 0;
    int answer = 987654321;
    for(int i=0; i<str.size(); i++){
        if(str[i] == 'a') a++;
    }

    for(int i=0; i<str.size(); i++){
        int cnt = a;
        int tmp = 0;
        for(int j=i; j<i+str.size(); j++){
            if(cnt == 0) break;

            if(str[j % str.size()] == 'b'){
                cnt--;
                tmp++;
            }
            else cnt--;
        }
        answer = min(answer, tmp);
    }
    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}