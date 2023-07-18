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
    sort(v.begin(), v.end());
    int answer = 0;
    for(int i=0; i<n; i++){
        int target = v[i];
        
        int left = 0;
        int right = n-1;

        while(left < right){
            if(v[left] + v[right] == target){
                if(i != left && i != right){
                    answer++;
                    break;
                }
                else if(i == left){
                    left++;
                }
                else if(i == right){
                    right--;
                }
            }
            else if(v[left] + v[right] < target){
                left++;
            }
            else if(v[left] + v[right] > target){
                right--;
            }
        }
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