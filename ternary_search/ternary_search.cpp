#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#define ll long long
using namespace std;

double unimodal_func(double x){
    return 2*pow(x, 2) - 12*x + 7;
}

ll ternary_search_minimum(double l, double r){
    for(int i = 0; i < 200; i++){
        double l1 = (l*2 + r)/3;
        double l2 = (l + r*2)/3;
        if(unimodal_func(l1) < unimodal_func(l2))
            r = l2;
        else
            l = l1;

    }
    double x = l;
    return (ll)round(unimodal_func(x));
}

int main(){
    int n, l, r;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> l;
        cin >> r;
        cout << ternary_search_minimum(l, r) << endl;
    }

    return 0;
}
