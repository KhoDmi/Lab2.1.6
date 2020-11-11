#include<stdlib.h>;      
#include<iostream>;
#include <limits>;
#include"cmath";
#include <cassert>

#include"CharQueue.h";
#include"Queue.h";
#include"IntQueue.h";
using namespace std;


int intInpCheck()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string num;
	cin >> num;
	int i = 0, finalnum = 0, negativCheck = 0, doubleCheck = 0, point = 0;
	double finalnumd = 0.0;
	if (num[0] == '-')
	{
		negativCheck = 1;
		i++;
	}
	while (num[i])
	{
		if (int(num[i]) >= 48 && int(num[i]) <= 57)
			finalnum = finalnum * 10 + int(num[i] - 48);
		if ((num[i] == '.') && (doubleCheck == 0) && (i > 0))
		{
			finalnumd = finalnum;
			point = i;
			doubleCheck = 1;
		}
		if (!(int(num[i]) >= 48 && int(num[i]) <= 57) && !((num[i] == '.') && ((doubleCheck == 0) || (doubleCheck == 1)) && (i > 0)))
		{
			cout << "Wrong input, try again\n";
			return intInpCheck();
		}
		i++;
	}
	if (doubleCheck == 1)
	{
		cout << "Wrong input, try again\n";
		return intInpCheck();
	}
	if (doubleCheck == 0)
	{
		if (negativCheck == 1)
			return -finalnum;
		return finalnum;
	}
}
double doubleInpCheck()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string num;
	cin >> num;
	int i = 0, finalnum = 0, negativCheck = 0, doubleCheck = 0, point = 0;
	double finalnumd = 0.0;
	if (num[0] == '-')
	{
		negativCheck = 1;
		i++;
	}
	while (num[i])
	{
		if (int(num[i]) >= 48 && int(num[i]) <= 57)
			finalnum = finalnum * 10 + int(num[i] - 48);
		if ((num[i] == '.') && (doubleCheck == 0) && (i > 0))
		{
			point = i;
			doubleCheck = 1;
		}
		if (!(int(num[i]) >= 48 && int(num[i]) <= 57) && !((num[i] == '.') && ((doubleCheck == 0) || (doubleCheck == 1)) && (i > 0)))
		{
			cout << "Wrong input, try again\n";
			return doubleInpCheck();
		}
		i++;
	}
	if (doubleCheck == 1)
	{
		finalnumd = finalnum / pow(10, (i - point-1));
		if (negativCheck == 1)
			return -finalnumd;
		return finalnumd;
	}
	if (doubleCheck == 0)
	{
		finalnumd = finalnum;
		if (negativCheck == 1)
			return -finalnumd;
		return finalnumd;
	}
}
int answerCheck()
{
	int check = 0;
	do
	{
		cout << "Input your answer (y or n)" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		char answer = cin.get();
		if (answer == 'y') check = 1;
		if (answer == 'n') check = -1;
	} while (check == 0);
	return check;
}

int main()
{
	cin.clear();
	cout << "Input anything to start" << endl;
	cin.get();
	system("cls");


	int c = 1;

	/*Queue<double> qd(100);
	double inp = 0;

	do
	{
		cout << "input new element" << endl;
		inp = doubleInpCheck();
		qd.Push(inp);
		cout << "is there any more elements?" << endl;
		c = answerCheck();
	} while (c != -1);

	qd.Pop();

	qd.Pop();

	qd.getQueue();*/



	Queue<char> qc(100);

	do
	{
		cout << "input new element" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		qc.Push();
		cout << "is there any more elements?" << endl;
		c = answerCheck();
	} while (c != -1);

	qc.Pop();

	qc.Pop();

	qc.getQueue();



	IntQueue<int> qi(100);
	int inpi = 0;

	do
	{
		cout << "input new element" << endl;
		inpi = intInpCheck();
		qi.Push(inpi);
		cout << "is there any more elements?" << endl;
		c = answerCheck();
	} while (c != -1);

	qi.Pop();

	qi.Pop();

	qi.getQueue();


	return 0;
}



