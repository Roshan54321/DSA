//using binary heap, a minimum heap
#include <iostream>

class priorityqueue;
class heap
{
    int* nodes;
    int size;
    int lastindex;

public:
    heap()
    {
        size = 1;
        nodes = new int[size];
        lastindex = -1;
    }

    void swap(int index1, int index2)
    {
        int temp = index1;
        nodes[index1] = nodes[index2];
        nodes[index2] = nodes[temp];
    }

    int parentnode(int index)
    {
        if(index == 0 || index == 1 || index == 2) return 0;
        return index / 2;
    }

    int leftchild(int index)
    {
        int leftchild;
        if(index == 0)  leftchild = 1;
        else leftchild = index * 2;
        return (leftchild <= lastindex)? leftchild : -1; 
    }

    int rightchild(int index)
    {
        int rightchild;
        if(index == 0)  rightchild = 2;
        else rightchild = index * 2 + 1;
        return (rightchild <= lastindex)? rightchild : -1; 
    }

    void shiftup()
    {
        int minindex = lastindex; 
        int parentindex; 
        while(minindex > 0)
        {
            parentindex = parentnode(minindex);
            if(nodes[parentindex] < nodes[minindex] )
            {
                swap(parentindex, minindex);
                minindex = parentindex;
                continue;
            }
            break;
        }
    }

    void shiftdown()
    {
        int minindex = 0;
        while(minindex <= lastindex)
        {
            int left = leftchild(minindex);
            int right = rightchild(minindex);
            int child = left <= right? left : right;
            if(child <= lastindex && nodes[child] < nodes[minindex])
            {
                swap(child, minindex);
                minindex = child;
                continue;
            }
            return;
        }
    }

    friend class priorityqueue;
};

class priorityqueue
{
    heap h;
public:
    void enqueue(int data)
    {
        if(h.lastindex == h.size - 1)
        {
            int* temp = h.nodes;
            h.nodes = new int[h.size * 2];
            for(int i = 0; i< h.size - 1; i++)
            {
                h.nodes[i] = temp[i];
            }
            h.size *= 2;
        }
        h.lastindex++;
        h.nodes[h.lastindex] = data;
        h.shiftup();
    }

    int dequeue()
    {
        int popped = h.nodes[0];
        h.nodes[0] = h.nodes[h.lastindex];
        h.lastindex--;
        h.shiftdown();
        return popped;
    }

};

int main()
{
    priorityqueue q;
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(10);
    q.enqueue(10);
    q.enqueue(67);
    q.enqueue(50);
    std::cout<<q.dequeue()<<std::endl;
    std::cout<<q.dequeue()<<std::endl;

    return 0;
}