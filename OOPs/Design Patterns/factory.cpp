#include <iostream>
#include <string>

using namespace std;

//Abstact Class
class Human
{
    public:
    virtual void Walk() = 0;
    virtual void Talk() = 0;

    static Human* Create(string type);
};

class Boy : public Human
{
    public:
    void Walk()
    {
        cout << "Boy is Walking"<<endl;
    }
    void Talk()
    {
        cout << "Boy is Talking"<<endl; 
    }
};    

class Girl : public Human
{
    public:
    void Walk()
    {
        cout << "Girl is Walking"<<endl;
    }
    void Talk()
    {
        cout << "Girl is Talking" << endl;
    }
};

Human* Human::Create(string type)
{
    if (type == "boy")
    {
        return new Boy();
    }
    if (type == "girl")
    {
        return new Girl();
    }
    return NULL;
}

int main()
{
    Human* obj1 = Human::Create("boy");
    Human* obj2 = Human::Create("girl");

    obj1->Walk();
    obj2->Talk();
    
    return 0;
}
