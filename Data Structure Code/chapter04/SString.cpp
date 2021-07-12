#include "SString.h"

SString::SString()
{
}

SString::SString(char c[])
{
	int i = 0;
	while (c[i])
	{
		i++;
	}
	this->setCh(c);
	this->setLength(i);
}

SString::~SString()
{
}

char* SString::getCh()
{
	return this->ch;
}

void SString::setCh(char c[])
{
	for (int i = 1; i < MAXLEN; i++)
	{
		this->ch[i] = c[i-1];
	}
}

int SString::getLength()
{
	return this->length;
}

void SString::setLength(int l)
{
	this->length = l;
}

int SString::Index_BF(SString T, int pos)
{
	int i = pos;
	int j = 1;
	while (i<=this->getLength()&&j<=T.getLength())
	{
		//std::cout << this->getCh()[i] << ":"<< T.getCh()[j]<<std::endl;
		//std::cout << i << ":" << j << std::endl;
		if (this->getCh()[i] == T.getCh()[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.getLength())
	{
		return i - T.getLength();
	}
	else
	{
		return 0;
	}
}


int SString::Index_KMP(SString T, int pos)
{
	int i = pos;
	int j = 1;
	int next[MAXLEN];
	int nextval[MAXLEN];
	get_Next( next);
	get_nextVal( nextval);
	int n = 1;
	for (int a = 1; a < T.getLength(); a++)
	{
		std::cout << next[a];
	}
	std::cout << std::endl;
	for (int a = 1; a < T.getLength(); a++)
	{
		std::cout << nextval[a] ;
	}
	std::cout << std::endl;
	while (i <= this->getLength() && j <= T.getLength())
	{
		std::cout << this->getCh()[i] << ":" << T.getCh()[j] << std::endl;
		std::cout << i << ":" << j << std::endl;
		if (j == 0 || this->getCh()[i] == T.getCh()[j])
		{
			j++;
			i++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j > T.getLength())
	{
		return i - T.getLength();
	}
	else
	{
		return 0;
	}
}

void SString::get_Next(int next[])
{
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < this->getLength())
	{
		if (j == 0 || this->getCh()[i] == this->getCh()[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

void SString::get_nextVal( int nextval[])
{
	int i = 1;
	nextval[1] = 0;
	int j = 0;
	while (i < this->getLength())
	{
		if (j == 0 || this->getCh()[i] == this->getCh()[j])
		{
			++i;
			++j;
			if (this->getCh()[i] != this->getCh()[j])
			{
				nextval[i] = j;
			}
			else
			{
				nextval[i] = nextval[j];
			}
		}
		else
		{
			j = nextval[j];
		}
	}
}