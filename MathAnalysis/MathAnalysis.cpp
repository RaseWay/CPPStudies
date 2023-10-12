#include <iostream>
#include <windows.h>
#include <cmath>

double f(double x)
{
	return pow(x, 4) - pow(x, 3) - 2 * (pow(x, 2)) + 3 * x - 3;
}

double root(double a, double b, double eps)
{
	double c;
	while ((b - a) > 2 * eps) //������� ���� �� ������� ����� � ���������� �����������
	{
		c = (a + b) / 2; // ����� �������� �������
		if (f(a) * f(c) > 0) // ���� ������������ f(c) � f(a) ������������, �.�. f(a) � f(c) ������������ ��� ������������, 
		{					   // �� �� �������� ������ ������� �� 'c'. ����� - ������.
			a = c;
		}
		else
		{
			b = c;
		}
	}
	return c;
}

int halfdevmeth()
{
	double a, b, x, eps;
	std::cout << "������� ������� ��������� � ����������� (a, b, eps): \n";
	std::cout << "a: ";
	std::cin >> a;
	std::cout << "b: ";
	std::cin >> b;
	if (f(a) * f(b) > 0) //�������� ��������� �� ���������� 
	{
		std::cout << "�������� �������� ��� ����������� ����� �� �������� ���������. ���������� ����� ����� 3 �������.\n";
		Sleep(3000);
		return 0;
	}
	else
	{
		std::cout << "eps: ";
		std::cin >> eps;
	}
	x = root(a, b, eps);
	std::cout << "x =" << x << std::endl;
	return 0;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	std::cout << "����� ���� ����������� ��������� �����\n";
	Sleep(1000);
	std::cout << "������� ����� ��������� ������������\n";
	Sleep(1000);
	std::cout << "�� ���� ����� ������ ���� �����.\n";
	Sleep(1000);
	std::cout << "����� ����������.\n";
	int n = 1, num;
	while (n == 1)
	{
		std::cout << "������� 1 ��� �������� ����� ��������� ������� ����������� �������. ������� 2 ��� �������� (� ������� ��������� ������). \n";
		std::cin >> num;
		switch (num)
		{
		case 1:
			halfdevmeth();
			break;
		case 2:
			std::cout << "������� ����� ��������. ����� �� ������ ����� � ����� ������� �� ����. ����� ��������� ����.\n";
			break;
		}
		std::cout << "����������? ���� 1, ����� ����� ������� �����. ���� 2, ����� break.\n";
		std::cin >> n;
	}
}