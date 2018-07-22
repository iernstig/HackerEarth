#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

void print_adj_list(vector<vector<int>> adj){
    for(int i = 1; i < adj.size(); i++){
        cout << "node " << i << " connects to:" << endl;
        for(int j = 0; j < adj[0].size(); j++){
            if(adj[i][j]){
                cout << j << " ";
            }
        }
        cout << endl <<  "----------------------------" << endl;
    }
}

/*
// this recursive solution does not work in it's current form, maybe be bac
// at it at a later time

int nodes_on_level_x(vector<vector<int>> adj,int current_node, int x, int sum){
if(x == 0 && !marked[current_node])
return 1;
else{
marked[current_node] = true;
cout << "hello" << endl;
cout << adj[current_node].size();
for(int i = 0; i < adj[current_node].size(); i++){
cout << "(i, j): " << "(" << current_node << ", " << i << ")" << endl;
return max(nodes_on_level_x(adj, adj[current_node][i], x--, sum), sum);
}
}
return 0;
}
*/

int bfs_count_x_level(vector<vector<int>> adj, int start, int x){
    vector<int> level(adj.size());
    vector<bool> visited(adj.size());
    queue<int> q;
    q.push(start);
    level[start] = 0;
    visited[start] = true;
    int x_level_count = 0;
    while(!q.empty()){
        int current_vertex = q.front();
        q.pop();
        for(int i = 0; i < adj[current_vertex].size(); i++){
            int linked = adj[current_vertex][i];
            if(linked){
                int next_node = i;
                if(!visited[next_node]){
                    int* next_level = &level[next_node];
                    *next_level     = level[current_vertex]++;
                    q.push(next_node);
                    visited[next_node] = true;
                    if(*next_level == x)
                    x_level_count++;
                }
            }
        }
    }

    vector<int> level_counter(10);
    for(int i = 0; i < level.size(); i++)
    level_counter[level[i]]++;

    for(int i = 0; i < level_counter.size(); i++)
    cout << i + 1 << ": " <<  level_counter[i] << endl;

    return x_level_count;
}

vector<int> determine_levels_of_nodes(vector<vector<int>> adj){
    vector<int> level(adj.size());
    vector<bool> visited(adj.size());
    queue<int> q;
    q.push(1);
    level[1] = 0;
    visited[1] = true;
    int x_level_count = 0;
    while(!q.empty()){
        int current_vertex = q.front();
        q.pop();
        for(int i = 0; i < adj[current_vertex].size(); i++){
            int linked = adj[current_vertex][i];
            if(linked){
                int next_node = i;
                if(!visited[next_node]){
                    int* next_level = &level[next_node];
                    *next_level     = level[current_vertex]++;
                    q.push(next_node);
                    visited[next_node] = true;
                }
            }
        }
    }
    return level;
}

void print_tree(vector<vector<int>> adj){
    vector<int> level = determine_levels_of_nodes(adj);
    int max_level = 10;
    for(int i = 0; i < max_level; i++){
        for(int j = 0; j < level.size(); j++){
            if(level[j] == i)
                cout << j << " ";
        }
        cout << endl;
    }
}


int main(){
    int n, a, b;
    ifstream file("../txtfiles/bfs_data.txt");
    file >> n;
    vector<vector<int>> adj(n+1, vector<int> (n));
    for(int i = 0; i < n - 1; i++){
        file >> a >> b;
        if(a != b){
            adj[a][b] = 1;
            adj[b][a] = 1;
        }
    }
    int x;
    file >> x;
    print_tree(adj);
    /*
    for(int i = 0; i < level.size(); i++)
    cout << i << " " << level[i] << endl;
    //    cout << bfs_count_x_level(adj, 1,  x) << endl;
    */
    return 0;
}
