#include <iostream>
#include <cstdlib>

class darray{ int *array; int *temp; int length; int capacity; public: darray
(){ length = 0; capacity = 1; array = new int[capacity]; temp = new int
[capacity]; }

	void insertatend(int n)
	{
		length++;
		if(length > capacity)
		{
			resize();
		}
		array[length-1] = n;
	}

	void insertanywhere(int pos, int n)
	{
		if(length = capacity)
		{
			resize();
		}

	    for(int i = length-1; i>pos; i--) 
	    {
	    	array[i] = array[i-1];
	    }

		array[pos] = n;
		length++;
		
	}

	void deleteatend(int n)
	{
		if(length == 0)
		{
			std::cout<<"The array is empty!"<<std::endl;
			exit(1);
		}

		length--;
		array[length-1] = n;
		while(length == capacity/2)
		{
			shrink();
		}
	}

	void resize()
	{
		capacity *= 2;
		temp = array;
		array = new int[capacity];
		copy();
	}

	void shrink()
	{
		capacity /= 2;
		temp = array;
		array = new int[capacity];
		copyshrinked();
	}

	void copyshrinked()
	{
		for(int i=0; i<length; i++)
		{
			array[i] = temp[i];
		}
		temp = new int[capacity];
	}

	void copy()
	{
		for(int i=0; i<length; i++)
		{
			array[i] = temp[i];
		}
		temp = new int[capacity];
	}

	void show()
	{
		if(length == 0)
		{
			std::cout<<"Empty array"<<std::endl;
			exit(0);
		}
		for(int i=0; i<length; i++)
		{
			std::cout<<array[i]<<std::endl;
		}
	}

};

int main()
{
	darray a;
	a.insertatend(5);
	a.deleteatend(5);
	a.show();
	return 0;
}