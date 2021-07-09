#include "DancePartner.h"

Person::Person()
{
}

Person::~Person()
{
}

void Person::setName(string n)
{
	this->name = n;
}

string Person::getName()
{
	return this->name;
}

void Person::setSex(char s)
{
	this->sex = s;
}

char Person::getSex()
{
	return this->sex;
}

void DancePartner(Person dancer[], int num)
{
	SqQueue<Person>* Mdancers = new SqQueue<Person>();
	SqQueue<Person>* Fdancers = new SqQueue<Person>();
	Person p;
	for (int i = 0; i < num; i++)
	{
		p = dancer[i];
		if (p.getSex() == 'F')
		{
			Fdancers->EnQueue(p);
		}
		else
		{
			Mdancers->EnQueue(p);
		}
	}
	cout << "The dancing partners are:\n";
	while (Fdancers->QueueLength() != 0 && Mdancers->QueueLength() != 0)
	{
		Fdancers->DeQueue(p);
		cout << p.getName() << "  ";
		Mdancers->DeQueue(p);
		cout << p.getName() << endl;
	}
	if (Fdancers->QueueLength() != 0)
	{
		p = Fdancers->GetHead();
		cout << "The first woman to get a partner is : " << p.getName() << endl;
	}
	else if (Mdancers->QueueLength() != 0)
	{
		p = Fdancers->GetHead();
		cout << "The first man to get a partner is : " << p.getName() << endl;
	}
}