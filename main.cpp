
// =================================================================
// File: main.cpp
// Author: Frida Bailleres Gonzalez
// Date:23/10/2022
// =================================================================


#include <iostream>
#include "priority_queue.h"
using namespace std;

int main(){

    Priority_Queue<int> queue(10);

    cout  <<  " Empty (before) = "  << queue.empty() << endl;

    queue.push(78);
    queue.push(45);
    queue.push(6);
    queue.push(23);
    queue.push(64);
    queue.push(2);
    queue.push(5);
    queue.push(100);
    queue.push(37);
    queue.push(32);

    int aux = 0;
    aux = queue.size();
    cout  << " Top = "  << queue.top() << endl;
    cout  << " Empty (after) = " << queue.empty() << endl;
    cout << " Size = " << aux<< endl;


}