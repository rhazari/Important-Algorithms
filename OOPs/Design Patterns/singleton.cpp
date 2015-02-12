#include <iostream>

using namespace std;

class Singleton
{
	public:
		static Singleton* instance;
		
	private:
		Singleton();
	
	public:
		static Singleton* GetInstance();
};

Singleton* Singleton :: instance = NULL;

Singleton :: Singleton()
{
	cout << "In the Singleton constructor"<<endl;
}

Singleton* Singleton :: GetInstance()
{
	if ( instance == NULL)
	{
		instance = new Singleton();
	}
	return instance;
} 


int main()
{
	Singleton* obj;
	obj = Singleton::GetInstance();
	return 0;
}
