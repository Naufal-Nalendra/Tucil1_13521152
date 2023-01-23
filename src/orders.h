#include "card.h"

#ifndef _ORDERS_H_
#define _ORDERS_H_

// Fungsi untuk cek jika hasil adalah 24 dan menampilkan persamaan ke layar
void Validate(int sol, string str){
    if (sol == 24){
        solutions.push_back(str);
        counter++;
    }
}

// Fungsi untuk memanggil fungsi Validate
void execValidate(vector<number> card, string str){
    if (card[0].numerator % card[0].denom == 0)
        Validate(card[0].numerator / card[0].denom, str);
}
// Prosedur untuk mengoperasikan hasil operasi 2 kartu pertama dengan kartu selanjutnya
void operLeftRight(vector<number> card, string str, int order){
    // Kemungkinan
    // 1. hasil operasi kartu 1 dan 2 lalu dilanjutkan kartu 3
    // 2. hasil operasi kartu 3 dan 4 lalu dilanjutkan kartu 2

    string tempStr = str;
    vector<number> operResult = card;

    for (int i = 0; i < 4; i++)
    {
        if (i == 3 && (isDivisible(card[0].numerator, card[1].numerator) == false)){
            break;
        }
        // operasi dengan kartu 2 atau 3
        operResult[1] = operation(operators[i], card[0], card[1]);

        operResult.erase(operResult.begin());

        if (order == 1)
            tempStr = "(" + str + operators[i] + to_string(card[1].numerator) + ")";
        else
            tempStr = "(" + to_string(card[0].numerator) + operators[i] + to_string(card[1].numerator) + ")";

        vector<number> backup = operResult;

        // Lanjutkan operasi dengan kartu 4
        for (int j = 0; j < 4; j++)
        {
            if (j == 3 && (isDivisible(card[0].numerator, card[1].numerator) == false)){
                break;
            }

            operResult[0] = operation(operators[j], operResult[0], card[2]);

            if (order == 1){
                tempStr = tempStr + operators[j] + to_string(card[2].numerator);
                execValidate(operResult,tempStr);
                tempStr = "(" + str + operators[i] + to_string(card[1].numerator) + ")";
                operResult = backup;
            }
            else {
                tempStr = tempStr + operators[j] + str;
                execValidate(operResult,tempStr);
                tempStr = "(" + to_string(card[0].numerator) + operators[i] + to_string(card[1].numerator) + ")";
                operResult = backup;
            }
        }
        // reset isi tempStr dan operResult
        tempStr = str;
        operResult = card;
    }
}
// Prosedur untuk mengoperasikan hasil operasi kartu 2 dan 3 dengan kartu 1 
void operMiddleLeft(vector<number> card, string str)
{
    string tempStr;
    vector<number> operResult = card;

    for (int i = 0; i < 4; i++)
    {
        if (i == 3)
        {
            if (isDivisible(card[0].numerator, card[1].numerator) == false)
            {
                break;
            }
        }

        operResult[1] = operation(operators[i], card[0], card[1]);

        operResult.erase(operResult.begin());
        tempStr = "(" + to_string(card[0].numerator) + operators[i] + str + ")";
        
        vector<number> backup = operResult;

        // Lanjutkan operasi dengan kartu 4
        for (int j = 0; j < 4; j++)
        {
            if (j == 3)
            {
                if (isDivisible(operResult[0].numerator, card[2].numerator) == false)
                {
                    break;
                }
            }
            operResult[0] = operation(operators[j], operResult[0], card[2]);

            tempStr = tempStr + operators[j] + to_string(card[2].numerator);
            execValidate(operResult,tempStr);

            tempStr = "(" + to_string(card[0].numerator) + operators[i] + str + ")";
            operResult = backup;
        }

        // reset isi tempStr dan operResult
        tempStr = str;
        operResult = card;
    }
}
// Prosedur untuk mengoperasikan hasil operasi kartu 2 dan 3 dengan kartu 4
void operMiddleRight(vector<number> card, string str)
{
    string tempStr;
    vector<number> operResult = card;

    // Operasikan kartu keempat dengan hasil kartu dari operasi pertama lalu operasikan dengan kartu pertama
    for (int i = 0; i < 4; i++)
    {
        // Kemungkinan semua operator
        if (i == 3)
        {
            if (isDivisible(card[1].numerator, card[2].numerator) == false)
            {
                break;
            }
        }

        operResult[1] = operation(operators[i], card[1], card[2]);

        operResult.erase(operResult.begin() + 2);
        tempStr = "(" + str + operators[i] + to_string(card[2].numerator) + ")";
        
        vector<number> backup = operResult;

        // Lanjutkan operasi dengan kartu 1
        for (int j = 0; j < 4; j++)
        {
            if (j == 3)
            {
                if (isDivisible(card[0].numerator, operResult[1].numerator) == false)
                {
                    break;
                }
            }
            operResult[0] = operation(operators[j], card[0], operResult[1]);

            tempStr = to_string(card[0].numerator) + operators[j] + tempStr;
            execValidate(operResult,tempStr);

            
            tempStr = "(" + str + operators[i] + to_string(card[2].numerator) + ")";
            operResult = backup;
        }

        // reset isi tempStr dan operResult
        tempStr = str;
        operResult = card;
    }
}

// Prosedur untuk mengoperasikan hasil operasi kartu 2 dan 3 dengan kartu 1 dan 4
void operMiddle(vector<number> card, string str)
{
    operMiddleLeft(card, str);
    operMiddleRight(card, str);
}

// Prosedur untuk mengoperasikan 2 kartu pertama dari 4 kartu
void operFirstTwo(vector<int> c)
{
    vector<number> card(4);
    for (int i = 0; i < 4; i++){
        card[i].numerator = c[i];
        card[i].denom = 1;
    }
    vector<number> operResult = card;
    string str;

    for (int i = 0; i < 3; i++){
        int j = i + 1;

        for (int k = 0; k < 4; k++){
            if (operators[k] == '/' && (isDivisible(card[i].numerator, card[j].numerator) == false)){
                break;
            }
            operResult[j] = operation(operators[k], card[i], card[j]);

            operResult.erase(operResult.begin() + i);
            str = "(" + to_string(card[i].numerator) + operators[k] + to_string(card[j].numerator) + ")";

            if (i == 0){
                operLeftRight(operResult, str, 1);
            }
            else if (i == 2){
                operLeftRight(operResult, str, 2);
            }
            else{
                operMiddle(operResult, str);
            }

            // Kembalikan string dan operResult ke semula
            str = "";
            operResult = card;
        }
    }
}

#endif