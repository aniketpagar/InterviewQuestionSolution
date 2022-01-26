#include "iostream"
using namespace std;
#include "memory"
class singletone
{
    static singletone* instance;
    singletone()
    {
        cout<<"i am in default constructor"<<endl;
    }
    public:
     
    static singletone* getInstance()
    {
        if(instance == NULL)
        {
            instance = new singletone;
        }else
        {
            cout<<" memory is already defined \n";
        }
        return instance;
    }
};

singletone* singletone::instance = NULL;
int main()
{
    auto obj = singletone::getInstance();
    auto obj2 = singletone::getInstance();
}