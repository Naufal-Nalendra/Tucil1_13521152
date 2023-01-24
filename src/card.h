#include <bits/stdc++.h>
#ifndef _CARD_H
#define _CARD_H

#include "operations.h"
using namespace std;

char operators[4] = {'+', '-', '*', '/'};
int counter = 0;
vector<string> solutions;

void displaySaved() {
    cout << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "| Your solutions have been exported into a .txt file |" << endl;
    cout << "------------------------------------------------------" << endl;
}

// Fungsi untuk menyimpan jawaban ke file
void saveAnswer(string input[]) {
    ofstream file;
    file.open("../test/solutions_" + input[0] + "_" + input[1] + "_" + input[2] + "_" + input[3] + "_" + ".txt");
    if (counter != 0){
        file << "There are " << counter << " solutions!" << endl;
        for (int i = 0; i < solutions.size(); i++){
            file << solutions[i] << endl;
        } 
    }
    else {
        file << "No solutions found!" << endl;
    }
    file.close();
    
    // Menunjukkan bahwa hasil save berhasil
    displaySaved();
    
}

// Fungsi untuk memberi input kartu secara acak
void randomizedCards(string input[])
{
    srand(time(0));
    for (int i = 0; i < 4; i++){
        
        int random = (rand() % 13) + 1;

        if (random == 1){
            input[i] = "A";
        }
        else if (random == 11){
            input[i] = "J";
        }
        else if (random == 12){
            input[i] = "Q";
        }
        else if (random == 13){
            input[i] = "K";
        }
        else{
            input[i] = to_string(random);
        }
    }

}

// Fungsi untuk mengubah kartu menjadi angka
void changeInteger(string Cards[4], int num[4])
{
    for (int i = 0; i < 4; i++) {
        if (Cards[i] == "A"){
            num[i] = 1;
        }
        else if (Cards[i] == "J"){
            num[i] = 11;
        }
        else if (Cards[i] == "Q"){
            num[i] = 12;
        }
        else if (Cards[i] == "K"){
            num[i] = 13;
        }
        else if (Cards[i][0] >= '2' && Cards[i][0] <= '9' && Cards[i][1] == '\0'){
            num[i] = stoi(Cards[i]);
        }
        else if (Cards[i][0] == '1' && Cards[i][1] == '0'){
            num[i] = 10;
        }
        else{
            num[i] = -1;
        }
    }
}

#endif