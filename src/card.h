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

#endif