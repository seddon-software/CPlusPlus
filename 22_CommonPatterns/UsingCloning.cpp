////////////////////////////////////////////////////////////
//
//		Virtual Construction using Cloning
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;


class Account
{
protected:
	string name;
public:
	Account(string name) { this->name = name; }
	virtual ~Account() {}
	void set_name(string name) { this->name = name; }
	virtual void get_balance() = 0;
	virtual void deposit() = 0;
	virtual void withdraw() = 0;
	
	// virtual CTOR
	virtual Account* clone(string name) = 0;
};

void Account::withdraw() { cout << name + " is withdrawing money "; }

class Business : public Account
{
public:
	Business(string name) : Account(name) { }
	virtual ~Business() {}
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() { this->Account::withdraw(); cout << "from Business account" << endl; }
	
	// virtual CTOR
	Account* clone(string name)
	{
		Account* account = new Business(*this);
		account->set_name(name);
		return account;
	}
};

class Personal : public Account
{
public:
	Personal(string name) : Account(name) { }
	virtual ~Personal() {}
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() { this->Account::withdraw(); cout << "from Personal account" << endl; }

	// virtual CTOR
	Account* clone(string name)
	{
		Account* account = new Personal(*this);
		account->set_name(name);
		return account;
	}
};


/////

void takeMoney(Account *a)
{
	a->withdraw();
}

int main()
{
	// accounts are coupled to hierachy, but clones use virtual contructors
	Account* bruce = new Personal("Bruce");
	Account* dave = new Business("Dave");
	takeMoney(bruce);
	takeMoney(dave);
	
	Account* zoe = bruce->clone("Zoe");
	takeMoney(zoe);
	
	Account* susan = dave->clone("Susan");
	takeMoney(susan);
	
	return 0;
}
