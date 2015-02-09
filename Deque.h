#ifndef DEQUE_H
#define DEQUE_H

class Deque {

private:
    int sizeofDeque;
    int sizeofArray;
    std::string* dequeArray;
    std::string* tempDeque;
    std::string popString;

public:
    Deque();

    ~Deque();

    /**
     * Shift the elements right and insert the item in front.
     */
    void push_front(std::string item);

    /**
     * Inserts the element at the back of the queue.
     */
    void push_back(std::string item);

    /**
     * Pops the front element (index 0) and shifts all the other elements left by 1.
     */
    std::string pop_front();

    /**
     * Returns the element at the back of the queue, and decreases the pointer location.
     */
    std::string pop_back();

    /**
     * Returns the number of elements in the queue.
     */
    int size();

    bool empty();

    /**
     * Puts the contents of the queue from front to back into a retrun string with each string item followed by a newline.
     */
    std::string toStr();

    /**
     * Resizes the array if full or less than 1/4 full.
     */
    void resize(void);
};

#endif
