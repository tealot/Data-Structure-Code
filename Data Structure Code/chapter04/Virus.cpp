#include "Virus.h"

void Virus_detection()
{
	std::fstream inFile("病毒感染检测输入数据.txt");
	std::ofstream outFile("病毒感染检测输出数据.txt");
	int num;
	inFile >> num;
	//std::cout << num;

	while (num--)
	{
		//std::cout << num<<std::endl;
		char virusch[MAXLEN];
		char personch[MAXLEN];
		inFile >> personch;
		inFile >> virusch;
		SString Virus(personch);
		SString Person(virusch);

		std::cout << Virus.getCh() + 1 <<'\t'<< Person.getCh() + 1 << std::endl;
		std::cout << Virus.getLength() << '\t' << Person.getLength() << std::endl;

		char* Vir = Virus.getCh();
		int flag = 0;
		int m = Virus.getLength();
		for (int i = m + 1, j = 1; j <= m; j++)
		{
			Virus.getCh()[i++] = Virus.getCh()[j];
		}
		Virus.getCh()[2 * m + 1] = '\0';
		for (int i = 0; i < m; i++)
		{
			SString temp;
			for (int j = 1; j <= m; j++)
			{
				temp.getCh()[j] = Virus.getCh()[i + j];
			}
			temp.getCh()[m + 1] = '\0';
			temp.setLength(m);
			//std::cout << temp.getCh() +1<<std::endl;
			flag = Person.Index_BF(temp, 1);
			//flag = Person.Index_KMP(temp, 1);
			if (flag)
			{
				break;
			}
		}
		if (flag)
		{
			outFile << Virus.getCh()+1 << "   "<< Person.getCh() + 1 << " " << " YES" << std::endl;
		}
		else
		{
			outFile << Virus.getCh()+1 << "   " << Person.getCh() + 1 << " " << " NO" << std::endl;
		}
	}
}