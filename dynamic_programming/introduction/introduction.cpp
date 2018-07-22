#include <iostream>
#include <vector>
#include <fstream>
#include "comparison.h"
using namespace std;
#define ll long long

ll divisor = 1000000007;
vector<ll> factorials(99999);

ll factorial(ll n){
    if(n == 1||n == 0){
        return factorials[0] = 1;
    }
    if(factorials[n] != 0)
        return factorials[n - 1] % divisor;
    else{
        factorials[n - 1] = n*factorial(n - 1) % divisor;
        return factorials[n - 1];
    }
}

int main(){
    ifstream inFile("data/intro.txt");
    ofstream outFile("data/factorial.txt");
    int n, cases;
    inFile >> cases;
    factorials[0] = 1;


    for(int i = 0; i < cases; i++){
        inFile >> n;
        outFile << factorial(n) << endl;
    }



    //cout << "compare: " << comparison() << endl;


    return 0;
}
