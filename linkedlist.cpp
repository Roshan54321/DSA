#include <iostream>

template <class T>
class node
{
    T data;
    node* next;
    public:
    node(T data)
    {
        this->data = data;
    }
    friend class list;
};

template <class T>
class list
{
    node* head;
    public:
    list():head(NULL){}
    list(node* n):head(n){}

    void addNode(T data)
    {
        node* current = head;
        int count = 0;
        while(true)
        {
            current = current->next;
            count++;
            if(count==n)
            {
            std::cout<<current->data;
            }
        }
    }

    node* createNode(T data)
    {
        node* newnode = new node(data);
        return newnode;
    }

    void displayall()
    {
        node* current = head;
        while(current!=NULL)
        {
            std::cout<<current->data<<std::endl;
            current = current->next;
        }
    }
};

int main()
{ 
    // node* n = new node();
    // list li(n);
    // li.displayall();
    return 0;
}