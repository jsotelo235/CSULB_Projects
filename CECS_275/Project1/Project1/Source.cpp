#include <iostream>
using namespace std;

char emp_class();

int main()
{
	double x = 4;
	int y = 1;

	int j = 0;
	for (int i = 0; i <= 5; i = i + 2)
	{
		j = j + 5;
		cout << j << endl;
		cout << i << endl;
	}

	cout << x * y << endl;

	system("pause");
	return 0;
}

char emp_class()
{
	return 0;
}
