    #include "iostream"
	using namespace std;
    #include "memory"
    class pagar;
    class aniket
    {
        int a;
        int b;
        public:
        aniket(){}
        
        friend class pagar;//friend class
        friend void temp(aniket &a);
    };
    void temp(aniket &a1)
    {
        cout<<"I am in friend temp function"<<endl;
        a1.a=3;// changing the private member value
    }
    class pagar:public aniket
    {
        public:
        pagar(){};
        void display()
        {
            cout<<"I am in a friend class display function"<<endl;   
            a = 4;
        }  
    };
	int main()
	{
        aniket a;
        pagar p;
        p.display();
        temp(a);
	}   