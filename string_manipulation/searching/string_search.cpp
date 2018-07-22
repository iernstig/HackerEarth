#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void print_array(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> generate_reoccurence_count_array(string pattern){
    // example: |a|b|c|d|a|b| generates: |0|0|0|0|1|2|
    // the algorithms keeps count of how many
    // reoccurring sub-patters which exists in the entire pattern
    int pattern_length = (int) pattern.length();
    vector<int> reoccurence_count_array (pattern_length);
    reoccurence_count_array[0] = 0;

    for(int lead_pointer = 1; lead_pointer < pattern_length; lead_pointer++){
        int lag_pointer = reoccurence_count_array[lead_pointer - 1];

        // skip non-reoccuring characters
        while(lag_pointer > 0 && pattern[lead_pointer] != pattern[lag_pointer])
            lag_pointer = reoccurence_count_array[lag_pointer - 1];

        // lag pointer also used to count the amount of
        // re-occuring characters in the pattern string
        if(pattern[lead_pointer] == pattern[lag_pointer])
            lag_pointer++;

        reoccurence_count_array[lead_pointer] = lag_pointer;
    }
    return reoccurence_count_array;
}


int count_occurences_KMP(string pattern, string text){
    int count          = 0;
    int pattern_length = pattern.length();
    int text_length    = text.length();

    vector<int> reoccurence_pattern = generate_reoccurence_count_array(pattern);

    int text_pointer    = 0;
    int pattern_pointer = 0;

    while(text_pointer < text_length){
        if(pattern[pattern_pointer] == text[text_pointer]){
            text_pointer++;
            pattern_pointer++;
        }
        if(pattern_pointer == pattern_length){
            count++;
            pattern_pointer = reoccurence_pattern[pattern_pointer - 1];
        }
        else if(pattern[pattern_pointer] != text[text_pointer]){
            if(pattern_pointer != 0){
                pattern_pointer = reoccurence_pattern[pattern_pointer - 1];
            }
            else
                text_pointer++;
        }
    }
    return count;
}

int main(){
    ifstream file("../data/string_search.txt");
    string q, str;
    file >> q >> str;
    cout << count_occurences_KMP(q, str) << endl;
    return 0;
}
