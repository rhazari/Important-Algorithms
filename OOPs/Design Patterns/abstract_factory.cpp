#include <iostream>
#include <string>

using namespace std;

//Abstract class
class CPU
{
	public:
	virtual void Architecture() = 0;
	virtual void Make() = 0;
};

class Intel : public CPU
{
	public:
	void Architecture()
	{
		cout <<"X-86"<<endl;
	}
	void Make()
	{
		cout <<"Intel"<<endl;
	}
};

class AMD : public CPU
{
	public:
	void Architecture()
	{
		cout <<"X-64"<<endl;
	}
	void Make()
	{
		cout <<"AMD"<<endl;
	}
};

class CPUFactory
{
	public:
	CPU* GetType(string type)
	{
		if (type == "amd")
		{
			return new AMD();
		}
		if (type == "intel")
		{
			return new Intel();
		}
		return NULL;
	}
};

int main()
{
	CPUFactory* factory;
	CPU* cpu1 = factory->GetType("amd");
	cpu1->Architecture();

	CPU* cpu2 = factory->GetType("intel");
	cpu2->Make();
	return 0;
}
