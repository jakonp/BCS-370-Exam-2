/*
 Nicholas Jakobczyk
 Exam #2
 10/28/2020
 */

#include <iostream>
#include <string>

using std::string;

struct Pair{
    string key;
    int value;
    Pair* next;
};

class Map{
private:
    Pair* head, * tail;
    
public:
    //constructor
    Map(){
        head = nullptr;
        tail = nullptr;
    }
    
    //destructor
    ~Map(){
        tail = head;
        
        while(tail != nullptr)
        {
            head = head->next;
            delete tail;
            tail = head;
        }
    }
    
    void display(){
        Pair* tmp;
        tmp = head;
        
        while (tmp != nullptr){
            std::cout << "Key: " << tmp-> key << " Value: " << tmp->value << std::endl;
            
            tmp = tmp->next;
        }
    }
    
    bool addBack(string k, int v)
    {
        Pair* tmp = nullptr;
        tmp = head;
        while(tmp != nullptr)
        {
            if (!tmp->key.compare(k))
            {
                //Duplicate key
                return false;
            }
            tmp = tmp->next;
        }
        tmp = new Pair();
        tmp->key = k;
        tmp->value = v;
        tmp->next = nullptr;
        
        if(!head)
        {
            head = tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
        return true;
    }
    
    bool removeByKey(const string k)
    {
        Pair* current = nullptr;
        Pair* pre = nullptr;
        
        current = pre = head;
        
        while(current != nullptr)
        {
            if(!current->key.compare(k))
            {
                if(current == head)
                {
                    head = current->next;
                }
                else if(current == tail)
                {
                    pre->next = nullptr;
                    tail = pre;
                }
                else
                {
                    pre->next = current->next;
                }
                delete current;
                return true;
            }
            pre = current;
            current = current->next;
        }
        return false;
    }
    
    bool equals(const Map& map)
    {
        Pair* temp1 = nullptr;
        Pair* temp2 = nullptr;
        temp1 = head;
        temp2 = map.head;
        
        while(temp1 != nullptr && temp2 != nullptr)
        {
            if (temp1->value != temp2->value)
            {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    
    int operator[](string k)
    {
        Pair* temp = head;
        
        while(temp!=NULL)
        {
            if(temp->key.compare(k) == false)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return -404; //if key is not found return -404
    }
    
};


int main() //test the struct
{
    Map a, b;
    
    a.addBack("a1", 2020);
    a.addBack("a2", 3030);
    a.addBack("a3", 4040);
    
    a.display();
    a.removeByKey("2");
    a.display();
    
    b.addBack("b1", 2020);
    b.addBack("b2", 4040);
    std::cout << a.equals(b) << std::endl;
    std::cout << b["3"] << std::endl;
}
