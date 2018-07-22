#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool comparison(){
    ifstream a("../data/factorial.txt");
    ifstream b("../data/correctFactorial.txt");
    int row = 0;

    while(a.peek()){
        int adata, bdata;
        a >> adata;
        b >> bdata;
        if(adata != bdata){
            cout << "inequality at row: " << row << endl;
            cout << "adata: " << adata << endl;
            cout << "badata: " << bdata << endl;
            return false;
        }
        row++;
    }
    a.close();
    b.close();
    return true;
}
