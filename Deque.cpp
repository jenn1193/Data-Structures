#include "sDeque.h"
#include <iostream>

int main(int argc, char **argv) {
    int op = 0;
    std::string input;
    Deque *DQ = new Deque();
    
    while (op < 5)
    {
        std::cin >> op;
        switch(op) {
            case 0:
                std::cin >> input;
                DQ -> push_front(input);
                break;
            case 1:
                std::cin >> input;
                DQ -> push_back(input);
                break;
            case 2:
                DQ -> pop_front();
                break;
            case 3:
                DQ -> pop_back();
                break;
            case 4:
                std::cout << DQ -> toStr();
                break;
        }
        
        //Resizes the array if full or less than 1/4 full
        DQ -> resize();
    }
    
    return 0;
}
