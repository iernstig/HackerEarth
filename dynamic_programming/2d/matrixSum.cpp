#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Pair{
    int x;
    int y;
};

void printMatrix(vector<vector<int>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j <matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printQueries(vector<Pair> queries){
    for(int i = 0; i < queries.size(); i++){
        cout << "x: " << queries[i].x << " y: " << queries[i].y << endl;
    }
}

int main(){
    ifstream file("data/sample.txt");
    int m, n;
    file >> m >> n;
    vector<vector<int>> SumMatrix(m, vector<int>(n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            file >> SumMatrix[i][j];

            if(i == 0 && j != 0){
                SumMatrix[i][j] += SumMatrix[i][j - 1];
            }
            else if(i != 0 && j == 0){
                SumMatrix[i][j] += SumMatrix[i - 1][j];
            }
            else if(i != 0 && j != 0){ // please note the minus sign
                SumMatrix[i][j] += SumMatrix[i - 1][j] + SumMatrix[i][j - 1] - SumMatrix[i- 1][j - 1];
            }
        }
    }


    int q;
    file >> q;
    vector<Pair> queries;
    for(int i = 0; i < q; i++){
        Pair p;
        file >> p.x >> p.y;
        queries.push_back(p);
    }

    for(int i = 0; i < queries.size(); i++){
        cout << SumMatrix[queries[i].x - 1][queries[i].y - 1] << endl;
    }

    return 0;
}
