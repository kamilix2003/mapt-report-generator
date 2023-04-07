#include <iostream>
#include <queue>

bool push_limited_queue(std::queue<int>& q, int limit, int value)
{
    if(q.size() >= limit)
    {
        return true;
    }
    q.push(value);
    return false;
}

void display(std::queue<int>& q)
{
    int size = q.size();
    for(int i = 0; i < size; i++)
    {
        std::cout<<q.front()<<" ";
        q.pop();
    }
    std::cout<<"\n";
}

void pop_n_elements(std::queue<int>& q, int n)
{
    if(q.size() < n) { std::cout<<"queue is too small"; return; }
    for(int i = 0; i < n; i++)
    {
        q.pop();
    }
    std::cout<<"ereased "<<n<<" elements\n";
}

void populate_queue(std::queue<int>& q,int first_element, int step, int last_element)
{
    int i = first_element;
    for(; i <= last_element; i+=step)
    {
        q.push(i);
    }
    std::cout<<"populated queue with "<< (i-first_element)/step << " elements\n";
}

void populate_queue(std::queue<int>& q, int first_element, int step, int last_element, int limit)
{
    bool limit_reached = false;
    int i = first_element;
    for(; i <= last_element; i+=step)
    {
        limit_reached = push_limited_queue(q, limit, i);
        if(limit_reached)
        {
            std::cout<<"queue limit exeeded by "<< (i - first_element)/step 
                << " elements\n" << "all element over the limit will be erased\n";
            return;
        }
    }
    std::cout<<"populated queue with "<< (i-first_element)/step << " elements\n";
}

int main()
{
    std::queue<int> q;
    populate_queue(q, 1, 1, 12);
    display(q);
    std::string s = q.empty() ? "queue is empty!\n" : "queue isn't empty";
    std::cout<< s ;
    populate_queue(q, 1, 5, 55);
    pop_n_elements(q, 5);
    std::cout<<"length of the queue "<<q.size()<<" \n";
    display(q);
    populate_queue(q, 1, 1, 4, 3);
    display(q);
}