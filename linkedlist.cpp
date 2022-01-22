#include <iostream>

class node
{
    int data;
    node* next;
    public:
    node()
    {
        std::cout<<"Enter the data"<<std::endl;
        std::cin>>data;
        next = NULL;
    }
    friend class list;
};

class list
{
    node* head;
    public:
    list():head(NULL){}
    list(node* n):head(n){}

    void listtraverse(int n)
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