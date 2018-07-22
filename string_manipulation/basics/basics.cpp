#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ifstream file("../data/basics.txt");
    int n;
    file >> n;

    string s;
    int start, stop;
    for(int i = 0; i < n; i++){
        file >> s >> start >> stop;
        sort(s.begin() + start,s.begin() + stop + 1, greater<int>());
        cout << s << endl;
    }
    return 0;
}
