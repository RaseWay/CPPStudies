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
	while ((b - a) > 2 * eps) //считаем пока не получим ответ в допустимой погрешности
	{
		c = (a + b) / 2; // делим интервал пополам
		if (f(a) * f(c) > 0) // если произведение f(c) и f(a) положительно, т.е. f(a) и f(c) положительны или отрицательны, 
		{					   // то мы заменяем первую границу на 'c'. иначе - вторую.
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
	std::cout << "Введите границы интервала и погрешность (a, b, eps): \n";
	std::cout << "a: ";
	std::cin >> a;
	std::cout << "b: ";
	std::cin >> b;
	if (f(a) * f(b) > 0) //проверка интервала на валидность 
	{
		std::cout << "Неверный интервал или отсутствуют корни на заданном интервале. Попробуйте снова через 3 секунды.\n";
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
	std::cout << "Перед вами калькулятор различной херни\n";
	Sleep(1000);
	std::cout << "которая может впринципе существовать\n";
	Sleep(1000);
	std::cout << "но пока здесь только один метод.\n";
	Sleep(1000);
	std::cout << "ДОБРО ПОЖАЛОВАТЬ.\n";
	int n = 1, num;
	while (n == 1)
	{
		std::cout << "Нажмите 1 для рассчета корня уравнения методом половинного деления. Нажмите 2 для анекдота (в будущем добавятся методы). \n";
		std::cin >> num;
		switch (num)
		{
		case 1:
			halfdevmeth();
			break;
		case 2:
			std::cout << "Штирлиц бежал скачками. Потом он сделал рывок и резко свернул за угол. Качки пробежали мимо.\n";
			break;
		}
		std::cout << "Продолжаем? Жмай 1, чтобы снова выбрать метод. Жмай 2, чтобы break.\n";
		std::cin >> n;
	}
}