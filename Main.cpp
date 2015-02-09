#include <iostream>
#include "Deque.h"

using namespace std;

int main(int argc, char **argv) {
    int operationCode = 0;
    string input;
    Deque *deque = new Deque();

    while (operationCode >= 0 && operationCode < 5)
    {
        cin >> operationCode;

        switch(operationCode) {
            case 0:
                cin >> input;
                deque->push_front(input);
                break;
            case 1:
                cin >> input;
                deque->push_back(input);
                break;
            case 2:
                deque->pop_front();
                break;
            case 3:
                deque->pop_back();
                break;
            case 4:
                cout << deque->toStr();
                break;
            default:
                break;
        }

        deque->resize();
    }

    return 0;
}
