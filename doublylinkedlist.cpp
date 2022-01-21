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

	void insertatbeginning(int data)
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

	void deleteatbeginning()
	{
		if(head == NULL)
		{
			std::cout<<"List is empty"<<std::endl;
			return;
		}
		node* aux = new node;
		aux = head;
		head = head->next;
		head->prev = NULL;
		free(aux);
	}

	void insertatend(int data)
	{
		node* newnode = getnewnode(data);
		if(head == NULL)
		{
			head = newnode;
			return;
		}
		node* temp = new node;
		temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
	}

	void insertrandom(int pos, int data)
	{
		node* newnode = getnewnode(data);
		if(head == NULL)
		{
			head = newnode;
			return;
		}
		node* temp = new node;
		temp = head;
		for(int i=0; i<pos-1; i++)
		{
			temp = temp->next;
			if(temp == NULL)
			{
				std::cout<<"The list is short"<<std::endl;
				return;
			}
		}
		node* aux = new node;
		temp = newnode;
		temp->next = aux;
		aux->prev = temp;
		newnode->prev = temp;
	}

	void deleteatend()
	{
		if(head == NULL)
		{
			std::cout<<"List is empty"<<std::endl;
			return;
		}
		node* temp = new node;
		temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		(temp->prev)->next = NULL;
		free(temp);
	}

	void displayall()
	{
		if(head == NULL)
		{
			std::cout<<"List is empty"<<std::endl;
			return;
		}

		node* temp = new node;
		temp = head;
		while(temp!=NULL)
		{
			std::cout<<temp->data<<std::endl;
			temp = temp->next;
		}
	}

};

int main()
{
	list l;
	l.insertatbeginning(2);
	l.deleteatend();
	l.displayall();
	return 0;
}