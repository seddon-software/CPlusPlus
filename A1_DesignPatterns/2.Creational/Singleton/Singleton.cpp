////////////////////////////////////////////////////////////
//
//		Singleton
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


class Singleton
{
private:
	static Singleton* pInstance;
protected:
	Singleton(const Singleton&) {}
	Singleton() {}
	~Singleton() {}
public:
    void PrintAddress() 
    {
    	cout << this << endl;
    }
    
	static Singleton *instance();
};

Singleton* Singleton::instance()
{
	if (pInstance == 0)	pInstance = new Singleton;
	return pInstance;
}

Singleton* Singleton::pInstance = 0;

/////

int main()
{
	Singleton* p = Singleton::instance();
	p->PrintAddress();
	
	Singleton* q = Singleton::instance();
	q->PrintAddress();
}
