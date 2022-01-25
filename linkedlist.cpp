#include <iostream>

class list;

class node
{
    int data;
    node* next;
    public:
    node(){}
    template <class T>
    node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
    friend class list;
};

class list
{
    node* head;
    public:
    list():head(NULL){}

    template <class T>
    void insert_last(T data)
    {
        node* newnode = createNode(data);
        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            node* ptr = new node();
            ptr = head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }

    template <class T>
    void insert_before(T pos, T data)
    {
        node* newnode = createNode(data);
        node* ptr = new node;
        node* prev;
        ptr = prev = head;
        if(ptr == NULL)
        {
            std::cout <<"List is empty!"<< std::endl;
            return;
        }
        else
        {
            if(head->data == pos)
            {
                newnode->next = head;
                head = newnode;
                return;
            }
            while(ptr != NULL)
            {
                if(ptr->data == pos)
                {
                    prev->next = newnode;
                    newnode->next = ptr;
                    return;
                }
                prev = ptr;
                ptr = ptr->next;
            }
        }
    }

    template <class T>
    void delete_before(T pos)
    {
        node* ptr = new node;
        node* prev;
        ptr = prev = head;
        if(ptr == NULL)
        {
            std::cout <<"List is empty!"<< std::endl;
            return;
        }
        else
        {
            if(head->data == pos)
            {
                std::cout <<"Node doesn't exist" <<std::endl;
                return;
            }
            while(ptr != NULL)
            {
                if(ptr->data == pos)
                {
                    prev->next = ptr->next;
                    prev->data = ptr->data;
                    delete ptr;
                    return;
                }
                prev = ptr;
                ptr = ptr->next;
            }
        }
    }

    template <class T>
    node* createNode(T data)
    {
        node* newnode = new node(data);
        return newnode;
    }

    void displayall()
    {
        node* ptr = new node;
        ptr = head;
        while(ptr!=NULL)
        {
            std::cout<<ptr->data<<std::endl;
            ptr = ptr->next;
        }
    }
};

int main()
{ 
    list li;
    li.insert_last(12);
    li.insert_last(18);
    li.insert_last(16);
    li.insert_before(16, 3);
    li.delete_before(3);

    li.displayall();
    return 0;
}