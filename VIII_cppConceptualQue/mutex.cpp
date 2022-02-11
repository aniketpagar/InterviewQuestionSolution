#include "iostream"
using namespace std;
#include "mutex"
#include "thread"
mutex mt;

void display()
{
    mt.lock(); //we can comment this line  to see the two thread getting resource at same time
    cout<<" I am in a display function : "<<this_thread::get_id()<<endl;
    mt.unlock();
}
int main()
{
    thread t1(display);
    thread t2(display);
    t1.join();
    t2.join();
}
