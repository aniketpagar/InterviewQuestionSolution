/*
Mutex is a locking mechanism whereas Semaphore is a signaling mechanism
Mutex is just an object while Semaphore is an integer
Mutex has no subtype whereas Semaphore has two types, which are counting semaphore and binary semaphore.
Semaphore supports wait and signal operations modification, whereas Mutex is only modified by the process that may request or release a resource.
Semaphore value is modified using wait () and signal () operations, on the other hand, Mutex operations are locked or unlocked.
Use of Semaphore
In the case of a single buffer, we can separate the 4 KB buffer into four 1 KB buffers.
Semaphore can be associated with these four buffers. This allows users and producers to work on different buffers at the same time.

Use of Mutex
A mutex provides mutual exclusion, which can be either producer or consumer that can have the key (mutex) and proceed with their work. 
As long as producer fills buffer, the user needs to wait, and vice versa. In Mutex lock, all the time, only a single thread can work with the entire buffer.
*/
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
