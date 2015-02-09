#include <sstream>
#include "Deque.h"

using namespace std;

Deque::Deque() {
    this.sizeofDeque = 0;
    this.sizeofArray = 8;
    this.dequeArray = new string[sizeofArray];
}

Deque::~Deque() {

}

void Deque::push_front(std::string item) {
    for (int i = sizeofDeque - 1; i > -1; i--) {
        dequeArray[i + 1] = dequeArray[i];
    }
    dequeArray[0] = item;
    sizeofDeque++;
}

void Deque::push_back(std::string item) {
    dequeArray[sizeofDeque] = item;
    sizeofDeque++;
}

std::string Deque::pop_front() {
    if (sizeofDeque > 0) {
        popString = dequeArray[0];
        sizeofDeque--;

        for(int i = 0; i < sizeofDeque; i++)
            dequeArray[i] = dequeArray[i+1];

        return popString;
    }
    return "There is nothing in the Deque";
}

std::string Deque::pop_back() {
    if (sizeofDeque > 0) {
        popString = dequeArray[sizeofDeque - 1];
        sizeofDeque--;
        return popString;
    }
    return "There is nothing in the Deque";
}

int Deque::size() {
    return sizeofDeque;
}

bool Deque::empty() {
    if (sizeofDeque == 0)
        return true;
    else
        return false;
}

std::string Deque::toStr() {
    std::stringstream toString;

    for (int i = 0; i < sizeofDeque; i++) {
        toString << dequeArray[i] << '\n';
    }
    return toString.str();
}

void Deque::resize(void) {
    //Expands the Deque to twice the size if full.
    if (sizeofDeque == sizeofArray) {
        sizeofArray = 2 * sizeofArray;
        tempDeque = new std::string[sizeofArray];
        for (int i = 0; i < sizeofDeque; i++) {
            tempDeque[i] = dequeArray[i];
        }
        dequeArray = tempDeque;
    }

    //Decreases the Deque to half the size if 0.25 full
    else if (sizeofDeque < (0.25 * (sizeofArray)) && (sizeofArray > 8)) {
        sizeofArray = sizeofArray / 2;
        tempDeque = new std::string[sizeofArray];
        for (int i = 0; i < sizeofDeque; i++) {
            tempDeque[i] = dequeArray[i];
        }
        dequeArray = tempDeque;
    }
}
