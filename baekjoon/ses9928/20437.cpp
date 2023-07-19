// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int getShortest();
int getLongest();
bool check(const vector<int>&);

string str;
int k;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    str.clear();
}

void input()
{
    cin >> str;
    cin >> k;
}

void solve()
{
    int r1 = getShortest();
    if(r1 == -1){
        cout << r1 << "\n";
        return;
    }
    int r2 = getLongest();
    cout << r1 << " " << r2 << "\n";
    return;
}
// 어떤 문자를 k개 포함하는 가장 짧은 연속 문자열의 길이를 구한다.
int getShortest(){
    // 알파벳은 26개.
    if(k == 1) return 1;

    int shortest = 987654321;

    vector<int> cnts(26, 0);
    int left = 0;
    int right = left + 1;

    cnts[str[left] - 'a']++;
    cnts[str[right] - 'a']++;

    while(right < str.size()){
        // 어떤 문자를 정확히 k개 포함한다.
        if(check(cnts)){
            shortest = min(shortest, right - left + 1);
            cnts[str[left] - 'a']--;
            left++;
        }
        // 포함하지 않는다
        else{
            right++;
            cnts[str[right]-'a']++;
        }
    }
    return shortest == 987654321 ? -1 : shortest;
}
// 어떤 문자를 K개 포함하고, 문자열의 첫 번째와 마지막 글자가 해당 문자로 같은 가장 긴 연속 문자열의 길이를 구한다.
int getLongest(){
    if(k == 1) return 1;
    int longest = -1;

    for(char target='a'; target<='z'; target++){
        int cnt = 0;
        int left = 0;
        int right = 1;
        if(str[left] == target) cnt++;
        if(str[right] == target) cnt++;

        while(right < str.size()){
            // 조건을 만족
            if(cnt == k){
                if(str[left] == target && str[right] == target){
                    longest = max(longest, right - left + 1);
                    cnt--;
                    left++;
                }
                else{
                    left++;
                }
            }
            else if(cnt < k){
                right++;
                if(str[right] == target) cnt++;
            }
        }
    }
    return longest;
}

bool check(const vector<int>& cnts){
    for(int cnt: cnts){
        if(cnt == k) return true;
    }
    return false;
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