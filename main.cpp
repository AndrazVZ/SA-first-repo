#include <iostream> //za debug
#include <fstream>
#include <vector>
using namespace std;

bool Branje_Stevil(vector<int> &vec, const char s[]) {
    ifstream input(s);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (!input.eof()) {
        input >> st;
        vec.push_back(st);
        while (isspace(input.peek())) input.get();
    }
    input.close();
    return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
    ofstream output("out.txt");

    for (int i = 0; i<velikost; i++)
        output << polje[i] << ' ';
}


int findMax(vector<int> &vec){
    int max = -9999;

    for(int i = 0; i < vec.size(); i++){
        if(vec[i] > max){
            max = vec[i];
        }
    }

    return max;
}

int findMin(vector<int> &vec){
    int min = 9999;

    for(int i = 0; i < vec.size(); i++){
        if(vec[i] < min){
            min = vec[i];
        }
    }
    return min;
}

void addMin(vector<int> &vec, int min){
    for(int i = 0; i < vec.size(); i++){
        vec[i] += min;
    }
}

void subtractMin(vector<int> &vec, int min){
    for(int i = 0; i < vec.size(); i++){
        vec[i] -= min;
    }
}

int main(int argc, const char* argv[]) {
    vector<int> A;

    if (argc < 3) return 0;
    if (!Branje_Stevil(A, argv[2])) return 0;

    if (argv[1][0] == '0') {
        //counting sort
    }
    else {
        //Roman sort
    }
    Izpis_Stevil(&A[0],A.size());

    return 0;
}
