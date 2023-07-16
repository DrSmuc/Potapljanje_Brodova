#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream robotBrod;
    int robot[11][11];
    char robovis[12][12];
    robotBrod.open("robot_brod.txt", ios::in);
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			robotBrod >> robot[i][j];
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			switch (robot[i][j])
			{
			case 2:
				robovis[i][j] = '2';
				break;
			case 3:
				robovis[i][j] = '3';
				break;
			case 4:
				robovis[i][j] = '4';
				break;
			case 5:
				robovis[i][j] = '2';
				break;
			case 6:
				robovis[i][j] = '3';
				break;
			default:
				robovis[i][j] = '0';
			}
		}
	}
	system("cls");
	cout << " ";
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (i == 0)
				cout << j << " ";
			else if (j == 0)
			{
				if (i < 10)
					cout << " " << i << " ";
				else
					cout << i << " ";
			}
			else if (j == 0 && i == 0)
				cout << 0 << " ";
			else
				cout << robovis[i][j] << " ";
		}
		cout << endl;
	}
	robotBrod.close();
}
