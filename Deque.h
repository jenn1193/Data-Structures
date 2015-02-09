#include <string>
#include <sstream>


//Implementing a double ended queue using arrays
class Deque{
private:
    int sizeofDeque;
    int sizeofArray;
    std::string* dequeArray;
    std::string* tempDeque;
    std::string popString;
    
    
public:
    Deque()
    {
        sizeofDeque = 0;
        sizeofArray = 8;
        dequeArray = new std::string[sizeofArray];
    }
    
    ~Deque() {}
    
    //Shift the elements right and insert the item in front
    void push_front(std::string item)
    {
        for(int i = sizeofDeque - 1; i > -1; i--)
            dequeArray[i + 1] = dequeArray[i];
        dequeArray[0] = item;
        sizeofDeque++;
    }
    
    // Inserts the element at the back of the queue
    void push_back(std::string item)
    {
        dequeArray[sizeofDeque] = item;
        sizeofDeque++;
    }
    

    //Pops the front element (index 0) and shifts all the other elements left by 1
    std::string pop_front()
    {
        if(sizeofDeque > 0)
        {
            popString = dequeArray[0];
            sizeofDeque--;
            
            for(int i = 0; i < sizeofDeque; i++)
                dequeArray[i] = dequeArray[i+1];
            
            return popString;
        }
        return "There is nothing in the Deque";
    }
    
    // Returns the element at the back of the queue, and decreases the pointer location.
    std::string pop_back()
    {
        if(sizeofDeque > 0)
        {
            popString = dequeArray[sizeofDeque - 1];
            sizeofDeque--;
            return popString;
        }
        return "There is nothing in the Deque";
    }
    
    // Returns the number of elements in the queue.
    int size()
    {
        return sizeofDeque;
    }
    
    bool empty()
    {
        if(sizeofDeque == 0)
            return true;
        else
            return false;
    }
    
    /* Puts the contents of the queue from front to back into a
     retrun string with each string item followed by a newline
     */
    std::string toStr()
    {
        std::stringstream toString;
        
        for(int i = 0; i < sizeofDeque; i++)
        {
            toString << dequeArray[i] << '\n';
        }
        return toString.str();
    }
    
    void resize(void)
    {
        //Expands the Deque to twice the size if full
        if(sizeofDeque == sizeofArray)
        {
            sizeofArray = 2 * sizeofArray;
            tempDeque = new std::string[sizeofArray];
            for(int i = 0; i < sizeofDeque; i++)
            {
                tempDeque[i] = dequeArray[i];
            }
            dequeArray = tempDeque;
            
            
        }
        
        //Decreases the Deque to half the size if 0.25 full
        else if(sizeofDeque < (0.25 * (sizeofArray)) && (sizeofArray > 8))
        {
            sizeofArray = sizeofArray / 2;
            tempDeque = new std::string[sizeofArray];
            for(int i = 0; i < sizeofDeque; i++)
            {
                tempDeque[i] = dequeArray[i];
            }
            dequeArray = tempDeque;
            
        }
    }
    
};
