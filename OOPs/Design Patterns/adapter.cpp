#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

class LegacyAccount
{
	int no;
	public:
	LegacyAccount(int no)
	{
		this->no = no;
	}

	void AccountPrint()
	{
		cout <<"Legacy account details"<<endl;
	}
};

class DisplayInterface
{
	public:
		virtual void display() = 0;
};

class Account : public DisplayInterface
{
	string name;
	public:
		Account(string name)
		{
			this->name = name;
		}
		void display()
		{
			cout<<"Current account details"<<endl;
		}
};

class LegacyAdapter : public LegacyAccount, public DisplayInterface
{
	public:
		LegacyAdapter(string name): LegacyAccount(atoi(name.c_str()))
		{}
		
		void display()
		{
			this->AccountPrint();
		}
};

int main()
{
	list<DisplayInterface* > account_list;
	account_list.push_back(new Account("Raihan"));
	account_list.push_back(new Account("Hazarika"));
	account_list.push_back(new LegacyAdapter("123456"));	
	
	while(!account_list.empty())
	{
		DisplayInterface* obj = account_list.front();
		obj->display();
		account_list.pop_front();
	}
	
	return 0;
}
