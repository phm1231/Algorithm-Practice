// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
bool check(const string);

int ys[] = {0, 2, 1, 1, 1};
int xs[] = {1, 1, 0, 2, 1};

string str;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{

}

void solve()
{
    while(1){
        cin >> str;
        if(str == "end") return;
        if(check(str)) cout << "valid\n";
        else cout << "invalid\n";
    }
}

bool check(const string s){
    int xcnt, ocnt;
    xcnt = ocnt = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'O') ocnt++;
        else if(s[i] == 'X') xcnt++;
    }

    bool xwin, owin;
    xwin = owin = false;
    if(s[0] == s[3] && s[3] == s[6]){
        if(s[0] == 'O') owin = true;
        else if(s[0] == 'X') xwin = true;
    }
    if(s[1] == s[4] && s[4] == s[7]){
        if(s[1] == 'O') owin = true;
        else if(s[1] == 'X') xwin = true;
    }
    if(s[2] == s[5] && s[5] == s[8]){
        if(s[2] == 'O') owin = true;
        else if(s[2] == 'X') xwin = true;
    }
    if(s[0] == s[1] && s[1] == s[2]){
        if(s[0] == 'O') owin = true;
        else if(s[0] == 'X') xwin = true;
    }
    if(s[3] == s[4] && s[4] == s[5]){
        if(s[3] == 'O') owin = true;
        else if(s[3] == 'X') xwin = true;
    }
    if(s[6] == s[7] && s[7] == s[8]){
        if(s[6] == 'O') owin = true;
        else if(s[6] == 'X') xwin = true;
    }
    if(s[0] == s[4] && s[4] == s[8]){
        if(s[0] == 'O') owin = true;
        else if(s[0] == 'X') xwin = true;
    }
    if(s[2] == s[4] && s[4] == s[6]){
        if(s[2] == 'O') owin = true;
        else if(s[2] == 'X') xwin = true;
    }

    // X 승
    if(xwin && !owin && xcnt == ocnt + 1) return true;
    // O 승
    if(owin && !xwin && xcnt == ocnt) return true;
    // 무승부
    if(!owin && !xwin && xcnt == 5 && ocnt == 4) return true;
    // 그 외
    return false;

}


int main()
{
    init();
    input();
    solve();
    return 0;
}