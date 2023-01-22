#include <bits/stdc++.h>
#include "ascii.h"
#include "orders.h"

using namespace std;

// Fungsi untuk menampilkan main menu ke layar
void displayMain() {
    cout << "Silahkan pilih cara memberikan input : " << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "1. Input secara manual" << endl;
    cout << "2. Input secara acak" << endl;
    cout << "3. Keluar" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Input : " << endl;
}
// Fungsi untuk menampilkan input kartu acak ke layar
void displayRandomInput(string input[4]) {
    cout << "Random Input : " << endl;

    for (int i = 0; i < 4; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}
// Fungsi untuk menampilkan waktu eksekusi ke layar
void displayExecTime() {
    float execTime = clock();
    execTime = clock() - execTime;
    
    cout << endl;
    
    cout << "--------------------------" << endl;
    cout << "Execution time is ";
    cout << fixed << setprecision(2) << execTime;
    cout << " ms" << endl;
    
}
// Fungsi untuk menampilkan pilihan untuk menyimpan solusi atau tidak
void displaySavePrompt(string input[4]) {
    cout << endl;
    cout << "Apakah anda ingin menyimpan solusi ke file? (tekan Y/y jika ingin) : ";
    string inp;
    cin >> inp;
    if (inp == "y" || inp == "Y") {
        saveAnswer(input);
    }
}
// Fungsi untuk menampilkan solusi dari 24 game
void displaySolutions() {
    // Output solutions
    cout << endl << "Output : " << endl;

    if (counter == 0)
    {
        cout << "No Solutions found!" << endl;
    }
    else
    {
        cout << endl << "There are " << counter << " solutions!" << endl << endl;
        for (int i = 0; i < solutions.size(); i++)
        {
            cout << solutions[i] << endl;
        }
    }
}

// Fungsi untuk menjalankan program dengan input dari user
void userInput(string message)
{   
    int output[100];
    string input[1000];
    vector<int> card(4);

    while (true)
    {
        ASCII();
        string input_4;
        int j = 0;

        cout << message;

        cout << "Masukkan input 4 kartu yang dipisahkan dengan spasi : " << endl;
        cout << "Petunjuk --> (A = 1, J = 11, Q = 12, K = 13)" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Input : " << endl;

        getline(cin, input_4);

        for (int i = 0; i < input_4.length(); i++){
            if (input_4[i] == ' '){
                j++;
            }
            else{
                input[j] += input_4[i];
            }
        }

        if (j != 3) {
            message = "Input Anda wajib memiliki 4 karakter! Silahkan coba lagi\n";
            continue;
        }

        changeInteger(input, output);

        if (output[0] == -1 || output[1] == -1 || output[2] == -1 || output[3] == -1){
            message = "Input Anda tidak valid! Silahkan coba lagi\n";
            continue;
        }
        else{
            break;
        }
    }

    for (int i = 0; i < 4; i++){
        card[i] = output[i];
    }

    while (next_permutation(card.begin(), card.end()))
    {
        operFirstTwo(card);
    }
    
    // tampilan solusi 24 game
    displaySolutions();
    // tampilan waktu eksekusi
    displayExecTime();
    // tampilan pilihan saving
    displaySavePrompt(input);
}
// Fungsi untuk menjalankan program dengan input secara acak
void randomInput() {
    int output[4];
    string input[4];
    vector<int> card(4);

    // Memberi input kartu secara acak
    randomizedCards(input);

    // Menampilkan input yang diacak ke layar dan mengubah card ke integer
    ASCII();
    displayRandomInput(input);
    changeInteger(input, output);

    for (int i = 0; i < 4; i++){
        card[i] = output[i];
    }
    
    while (next_permutation(card.begin(), card.end()))
    {
        operFirstTwo(card);
    }

    // tampilan solusi 24 game
    displaySolutions();
    // tampilan waktu eksekusi
    displayExecTime();
    // tampilan pilihan saving
    displaySavePrompt(input);

}
// Fungsi untuk menampilkan main menu ke layar
void displayMenu(string message) {
    while (true)
    {
        ASCII();
        string input;

        cout << message;

        displayMain();

        getline(cin, input);
        
        if (input == "1"){
            userInput("");
            break;
        }
        else if (input == "2"){
            randomInput();
            break;
        }
        else if (input == "3"){
            exit(0);
        }
        else{
            message = "Input Anda tidak valid, silahkan coba lagi!.\n";
            continue;
        }
    }
}

int main() {
    displayMenu("");
}