#include <iostream>
#include <cstdlib>

class node
{
	int data;
	node* next;
	node* prev;
	friend class list;
};

class list
{
	node* head;
	node* tail;
public:
	list():head(NULL), tail(NULL){}

	node* getnewnode(int data)
	{
		node* newnode = new node;
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = NULL;
		return newnode;
	}

	void insert_beginning(int data)
	{
		node* newnode = getnewnode(data);
		if(head == NULL)
		{
			head = newnode;
			return;
		}
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}

	void delete_beginning()
	{
		if(head == NULL)
		{
			std::cout<<"List is empty"<<std::endl;
			return;
		}
		node* temp = new node;
		temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
	}

	void insert_end(int data)
	{
		node* newnode = getnewnode(data);
		if(head == NULL)
		{
			head = newnode;
			return;
		}
		node* ptr = new node;
		ptr = head;
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newnode;
		newnode->prev = ptr;
	}

	void insert_before(int pos, int data)
	{
		node* newnode = getnewnode(data);
		if(head == NULL)
		{
			std::cout <<"List is empty"<< std::endl;
			return;
		}
		else
		{
			if(head->data == pos)
			{
				newnode->next = head;
				head->prev = newnode;
				head = newnode;
			}
			else
			{
				node* ptr = new node;
				ptr = head;
				while(ptr != NULL)
				{
					if(ptr->data == pos)
					{
						ptr->prev->next = newnode;
						newnode->prev = ptr->prev;
						newnode->next = ptr;
						ptr->prev = newnode;
						return;
					}
					ptr = ptr->next;
				}
			}
		}
	}

	void delete_before(int pos)
	{
		node* ptr = new node;
		ptr = head;
		if(head == NULL)
		{
			std::cout <<"List is empty"<< std::endl;
			return;
		}
		else
		{
			if(head->data == pos)
			{
				std::cout <<"Node doesn't exist"<< std::endl;
			}
			else
			{
				while(ptr != NULL)
				{
					if(ptr->data == pos)
					{
						ptr = ptr->prev;
						ptr->prev->next = ptr->next;
						delete ptr;
						return;
					}
					ptr = ptr->next;
				}
			}
		}
	}

	void delete_end()
	{
		if(head == NULL)
		{
			std::cout<<"List is empty"<<std::endl;
			return;
		}
		else
		{
			node* ptr = new node;
			ptr = head;
			while(ptr->next!=NULL)
			{
				ptr = ptr->next;
			}
			if(ptr == head)
			{
				delete ptr;
				head = NULL;
			}
			else
			{
				ptr->prev->next = NULL;
				delete ptr;
			}
		}
	}

	void displayall()
	{
		if(head == NULL)
		{
			std::cout<<"List is empty"<<std::endl;
			return;
		}

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
	list l;
	l.insert_end(67);
	l.insert_end(60);
	l.insert_end(10);
	l.insert_end(4);
	l.insert_end(2);
	l.insert_before(10, 56);
	l.delete_before(10);
	// l.delete_end();
	l.displayall();
	return 0;
}