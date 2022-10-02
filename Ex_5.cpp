#include <iostream>
#include <fstream>
#include <vector>

class Priority_queue
{
private:
	std::vector<int>Data;
public:

	void Insert(int val)
	{
		Data.push_back(0);
		Increase_Key(Data.size() - 1, val);
	}

	void Increase_Key(int i, int val)
	{
		int p;
		if (val > Data[i])
		{
			Data[i]= val;
			p = (i-1)/2;
			while (i > 0 && Data[p] < val)
			{
				Data[i]= Data[p];
				i = p;
				p = (i - 1) / 2;
			}
			Data[i] = val;
		}
	}

	void Extract_Max()
	{
		Priority_queue temp;
		Data[0] = Data[Data.size() - 1];
		Data.pop_back();
		Max_Heapfy(0);
	}

	int getMax_Element()
	{
		return Data[0];
	}

	void Max_Heapfy(int i)
	{
		int left, right, imax;
		left = 2 * i + 1;
		right = 2 * i + 2;
		imax = i;
		if (left<Data.size() && Data[left] > Data[imax])
		{
			imax = left;
		}
		if (right<Data.size() && Data[right] > Data[imax])
		{
			imax = right;
		}
		if (i != imax)
		{
			std::swap(Data[i], Data[imax]);
			Max_Heapfy(imax);
		}
	}

	void printPriority_Queue()
	{
		for (int i = 0; i < Data.size(); i++)
		{
			std::cout << Data[i] << " ";
		}
	}

	int getDataSize()
	{
		return Data.size();
	}

	void clearData()
	{
		Data.clear();
	}

};

void menu(Priority_queue p)
{
	int op=1, element;
	while (op != 0)
	{
		std::cout << std::endl;
		std::cout << "Menu" << std::endl;
		std::cout << "1. Insereaza un nod in coada" << std::endl;
		std::cout << "2. Extrage elementul de prioritate maxima din coada" << std::endl;
		std::cout << "3. Obtine elementul de prioritate maxima din coada" << std::endl;
		std::cout << "4. Afiseaza coada" << std::endl;
		std::cout << "5. Goleste coada" << std::endl;

		std::cout << "Alege optiune: ";
		std::cin >> op;
		std::cout << std::endl;

		switch (op)
		{
		case 1:
			std::cout << "Citeste elementul pe care doresti sa il inserezi in coada: ";
			std::cin >> element;
			p.Insert(element);
			std::cout << std::endl;
			break;
		case 2:
			if (p.getDataSize() != 0)
			{
				p.Extract_Max();
				std::cout << "Elementul cu prioritate maxima a fost extras" << std::endl;
			}
			else
			{
				std::cout << "Elementul cu prioritate maxima nu a fost extras deoarece coada este goala" << std::endl;
			}
			break;
		case 3:
			if (p.getDataSize() != 0)
			{
				std::cout << "Elementul cu prioritate maxima din coada este:" << p.getMax_Element() << std::endl;
			}
			else
			{
				std::cout << "Coada este goala"<<std::endl;
			}
			break;
		case 4:
			if (p.getDataSize() != 0)
			{
				std::cout << "Coada contine urmatoarele elemente" << std::endl;
				p.printPriority_Queue();
			}
			else
			{
				std::cout << "Coada este goala" << std::endl;
			}
			std::cout << std::endl;
			break;
		case 5:
			p.clearData();
			std::cout << "Elementele din coada au fost sterse" << std::endl;
			break;
		}
	}
}


int main()
{
	Priority_queue p;
	menu(p);
}