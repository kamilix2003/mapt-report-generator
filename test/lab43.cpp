#include <iostream>
#include <queue>
using namespace std;

class Applicant {
public:
    static int applicants_count;
    int applicant_num = 0;
    int time;
};
    
int Applicant::applicants_count = 0;

void new_applicant(std::queue<Applicant>& q, Applicant* a) //1
{
    q.push(*a);
    a->applicants_count++;
    a->applicant_num = a->applicants_count;
}

bool queue_limit(std::queue<Applicant>& q, int limit)//3
{
    if(q.size() >= limit+1) { return true; }
    else { return false; }
}

void new_applicant(std::queue<Applicant>& q, Applicant* a, int limit) //3
{
    if(!queue_limit(q, limit))
    {
        q.push(*a);
        a->applicants_count++;
        a->applicant_num = a->applicants_count;
    }
    else
    {
        std::cout<<"the queue exeeded size limit of "<<limit<<" applicants\n";
    }
}

void serve_applicant(std::queue<Applicant>& q) //2
{
    if(q.size() > 1)
    {
        q.pop();
        cout << "applicant served\n" 
            << "applicants waiting for service:  " << q.size() - 1 << endl;
    }
    else { std::cout<< "all applicants are served!";}
}

int main() {
    queue<Applicant> eit;
    int limit = 3;
    Applicant p, p1, p2, p3, p4; 
    new_applicant(eit, &p, limit);

    Applicant temp = eit.back();
  
    cout << "last applicant number: " << temp.applicant_num
        << ", queue size: " << eit.size() << endl;
  
    cout << "applicants waiting for service:  " << eit.size() - 1 << endl;

    new_applicant(eit, &p1, limit);

        cout << "last applicant number: " << eit.back().applicant_num
        << ", queue size: " << eit.size() << endl;

    cout << "applicants waiting for service:  " << eit.size() - 1 << endl;
    new_applicant(eit, &p2, limit);
    new_applicant(eit, &p3, limit);
    new_applicant(eit, &p4, limit);
    serve_applicant(eit);
    new_applicant(eit, &p4, limit);
}
