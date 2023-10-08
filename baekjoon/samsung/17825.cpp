#include <iostream>
#include <vector>

#define ll long long
#define endl "\n";

using namespace std;

typedef struct Node{
    int value;
    Node* red;
    Node* blue;
    Node(int value): value(value), red(nullptr), blue(nullptr) {}
}Node;

void Init();
void Input();
void Solve();
void Dfs(int idx, int score, vector<Node* > horses);

const int MAX = 1e9;

vector<int> numbers(10, 0);
Node head = Node(0);
Node* center = nullptr; // 25
int answer = -1;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    Node* here = &head;
    // 2 - 42
    for(int i=2; i<=42; i+=2){
        Node* next;
        if(i == 42) next = new Node(0);
        else next = new Node(i);

        here->red = next;
        here = next;
    }

    here = &head;
    while(here->value != 10) here = here->red;
    here->blue = new Node(13);
    here = here->blue;
    here->red = new Node(16);
    here = here->red;
    here->red = new Node(19);
    here = here->red;

    center = new Node(25);
    here->red = center;

    here = &head;
    while(here->value != 20) here = here->red;
    here->blue = new Node(22);
    here = here->blue;
    here->red = new Node(24);
    here = here->red;
    here->red = center;

    here = &head;
    while(here->value != 30) here = here->red;
    here->blue = new Node(28);
    here = here->blue;
    here->red = new Node(27);
    here = here->red;
    here->red = new Node(26);
    here = here->red;
    here->red = center;
    
    here = center;
    here->red = new Node(30);
    here = here->red;
    here->red = new Node(35);
    here = here->red;

    Node* tail = &head;
    while(tail->value != 40) tail = tail->red;
    here->red = tail;
}

void Input()
{
    for(int i=0; i<10; i++) cin >> numbers[i];
}

void Solve()
{
    vector<Node *> horses{&head};
    Dfs(0, 0, horses);
    cout << answer;
}

void Dfs(int idx, int score, vector<Node* > horses){
    if(idx == 10){
        answer = max(answer, score);
        return;
    }

    int cnt = numbers[idx];
    // 이미 말판위의 말들이 앞으로 가는 경우.
    for(int i=0; i<horses.size(); i++){
        Node* here = horses[i];
        if(here->value == 0) continue; // 이미 도착한 말은 하지 않음.

        // cnt만큼 앞으로 전진한다.
        for(int i=0; i<cnt; i++){            
            if(i == 0 && here->blue != nullptr) here = here->blue;
            else if(here->red != nullptr) here = here->red;
            else break; 
        }
        // 다른 말과 겹치는지 확인
        bool is_duplicated = false;
        for(int j=0; j<horses.size(); j++){
            if(i == j) continue;
            if(here == horses[j] && horses[j]->value != 0){
                is_duplicated = true;
                break;
            }
        }
        if (is_duplicated) continue;
        Node* tmp = horses[i];
        horses[i] = here;
        Dfs(idx + 1, score + here->value, horses);
        horses[i] = tmp;
    }
    // 새로 출발하는 경우
    Node* here = &head;
    // cnt만큼 앞으로 전진한다.
    for(int i=0; i<cnt; i++){            
        if(i == 0 && here->blue != nullptr) here = here->blue;
        else if(here->red != nullptr) here = here->red;
        else break; 
    }
    // 다른 말과 겹치는지 확인
    bool is_duplicated = false;
    for(int i=0; i<horses.size(); i++){
        if(here == horses[i] && horses[i]->value != 0){
            is_duplicated = true;
            break;
        }
    }
    if (!is_duplicated){
        horses.push_back(here);
        Dfs(idx + 1, score + here->value, horses);
        horses.pop_back();
    }
}

int main()
{
    Init();
    Input();
    Solve();
    return 0;
}