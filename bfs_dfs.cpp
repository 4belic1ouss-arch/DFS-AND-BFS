#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[10];
bool visited[10];

// DFS
void DFS(int node){
    visited[node] = true;
    cout << node << " ";

    for(int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if(!visited[next]){
            DFS(next);
        }
    }
}

// BFS
void BFS(int start){
    bool visit[10] = {false};
    queue<int> q;

    visit[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            if(!visit[next]){
                visit[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){

    // Membuat graf
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);
    graph[2].push_back(5);
    graph[3].push_back(6);

    cout << "DFS : ";
    DFS(1);

    cout << endl;

    cout << "BFS : ";
    BFS(1);

    return 0;
}