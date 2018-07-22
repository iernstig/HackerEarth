#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool determine_if_connected(vector<vector<int>> adj, int a, int b){
    if(adj[a][b] == 1 || adj[b][a] == 1)
        return true;
    else
        return false;
}

void print_adj_list(vector<vector<int>> adj){
    for(int i = 0; i < adj.size(); i++){
        cout << "node " << i << " connects to:" << endl;
        for(int j = 0; j < adj[0].size(); j++){
            if(adj[i][j]){
                cout << j << " ";
            }
        }
        cout << endl <<  "----------------------------" << endl;
    }
}

int main(){

    // row <==> "outer container vector" (1st index)
    // col <==> "inner vectors" (2nd index)
    // this is why column vectors are used to represent
    // the simplest kinds of arrays.

    int m, n;
    //fstream cin("data.txt");
    cin >> n >> m;
    vector<vector<int>> adj_list(m + 10, vector<int>(n));

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(a != b){
            adj_list[a][b] = 1;
            adj_list[b][a] = 1;

        }
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        if(determine_if_connected(adj_list, a, b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

//    print_adj_list(adj_list);






    return 0;
}
