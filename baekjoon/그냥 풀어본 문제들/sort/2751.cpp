#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

void bubbleSort();
void selecionSort();
void insertionSort();
void mergeSort();
void quickSort();

int n;
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}

void solve()
{
    // bubbleSort();
    selecionSort();
    for(int item: v) cout << item << "\n";
}

// 인접한 두 원소를 반복적으로 비교
void bubbleSort(){
    for(int i=0; i<v.size() - 1; i++){
        for(int j=0; j<v.size() - 1 - i; j++){
            if(v[j] > v[j+1]){
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}

// 정렬되지 않은 데이터들에 대해 가장 작은 데이터를 찾아 가장 앞의 데이터와 교환하는 방식.
void selecionSort(){
    for(int i=0; i<v.size(); i++){
        int minIdx = i;
        for(int j = i+1; j<v.size(); j++){
            if(v[minIdx] > v[j]){
                minIdx = j;
            }
        }
        int tmp = v[minIdx];
        v[minIdx] = v[i];
        v[i] = tmp;
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}