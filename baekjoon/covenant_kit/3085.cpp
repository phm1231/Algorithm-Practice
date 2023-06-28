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
int check();

int n;
vector<string> candy;

void print_vector(){
    for(string s: candy) cout << s << endl;
    cout << endl;
}

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
        candy.push_back(tmp);
    }
}

void solve()
{
    int answer = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            // 좌우로 교환
            swap(candy[i][j], candy[i][j+1]);
            answer = max(answer, check());
            swap(candy[i][j], candy[i][j+1]);                
        }
    } 
    for(int j=0; j<n; j++){
        for(int i=0; i<n-1; i++){
            swap(candy[i][j], candy[i+1][j]);
            answer = max(answer, check());
            swap(candy[i][j], candy[i+1][j]);
            
        }
    }   
    /*
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            // 상하로 교환
            swap(candy[i][j], candy[i+1][j]);
            answer = max(answer, check());
            swap(candy[i][j], candy[i+1][j]);                
        }
    } 
    */ 
    cout << answer;
}

int check(){
    int ret = 1;
    for(int i=0; i<n; i++){
        int cnt = 1;
        for(int j=0; j<n; j++){
            if(candy[i][j] == candy[i][j+1]) cnt++;
            else{
                ret = max(cnt, ret);
                cnt = 1;
            }
        }
    }
    for(int j=0; j<n; j++){
        int cnt = 1;
        for(int i=0; i<n; i++){
            if(candy[i][j] == candy[i+1][j]) cnt++;
            else{
                ret = max(cnt, ret);
                cnt = 1;
            }
        }
    }
/*
    for(int i=0; i<n; i++){
        int cnt = 1;
        for(int j=0; j<n; j++){
            if(candy[j][i] == candy[j+1][i]) cnt++;
            else{
                ret = max(cnt, ret);
                cnt = 1;
            }
        }
    }
*/
    return ret;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}