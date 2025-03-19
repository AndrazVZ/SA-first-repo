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

        //poisci min
        int min = findMin(A);

        //vektor ki se zacne z 0
        subtractMin(A,min);
        int max = findMax(A);

        //pomozni vektor
        vector<int> C(max+1,0);

        //KORAK 2:
        for(int i = 0; i < A.size(); i++){
            C[A[i]] = C[A[i]] + 1;
        }
        //KORAK 3: i > 0!
        for(int i = 1; i < C.size(); i++){ //Pazi, mozna napaka: <=
            C[i] = C[i] + C[i-1];
        }
        //KORAK 4: izhodno polje
        vector<int> B(A.size());
        for(int i = A.size()-1; i >= 0; i--){
            B[C[A[i]]-1] = A[i];
            //dekrementiraj C
            C[A[i]] = C[A[i]]-1;
        }

        //KORAK 5: pretvori nazaj
        addMin(B,min);

        for(int i = 0; i < B.size(); i++){
            A[i] = B[i];
        }
    }
    else {
        //Roman sort
        //poisci min
        int min = findMin(A);

        //vektor ki se zacne z 0
        subtractMin(A,min);
        int max = findMax(A);


        //pomozni vektor
        vector<int> C(max+1,0);

        //KORAK 2:
        for(int i = 0; i < A.size(); i++){
            C[A[i]] = C[A[i]] + 1;
        }

        //KORAK 3:
        vector<int> B(A.size());
        int counter = 0; //za pomikanje v polju B

        for(int i = 0; i < C.size(); i++){
            if(C[i]!= 0){
                for(int j=0; j < C[i]; j++){
                    B[counter] = i;
                    counter++;
                }
            }
        }

        //KORAK 4: pretvori nazaj
        addMin(B,min);

        for(int i = 0; i < B.size(); i++){
            A[i] = B[i];
        }
    }
    Izpis_Stevil(&A[0],A.size());

    return 0;
}
