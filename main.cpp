#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
#include <array>
#include <algorithm>
#include "SecondaryFunction.h"

/*
Создать класс Data, содержащий в качестве полей скалярные
данные и мьютекс. Создать функцию swap, которая принимает
ссылки на два объекта класса Data и обменивает их местами.

В функция необходимо сначала захватить мьютексы обоих объектов,
а затем выполнеть обмен данными. Реализовать три варианта данной
функции: при помощи lock, scoped_lock и unique_lock.
*/

class Data
{
private:
	int id;
	std::mutex m;
public:
	Data(int data) : id(data) {}
	int getData() { return id; }
	std::mutex* getMutexPtr() { return &m; }
	friend void swapclass(Data& lhs, Data& rhs)
	{
		std::swap(lhs.id, rhs.id);
	}
};

void swap(Data& d1, Data& d2)
{
	d1.getMutexPtr()->lock();
	d2.getMutexPtr()->lock();
	swapclass(d1, d2);
	d1.getMutexPtr()->unlock();
	d2.getMutexPtr()->unlock();
}

void swap2(Data& d1, Data& d2)
{
	std::scoped_lock sl(*d1.getMutexPtr(), *d2.getMutexPtr());
	swapclass(d1, d2);
}

void swap3(Data& d1, Data& d2)
{
	std::unique_lock<std::mutex> ul1(*d1.getMutexPtr());
	std::unique_lock<std::mutex> ul2(*d2.getMutexPtr());
	swapclass(d1, d2);
}

int main(int argc, char** argv)
{
	printHeader(L"Защищенный обмен данными");

	Data d1(10), d2(12);
	std::wcout << "d1 = " << d1.getData() << "  d2 = " << d2.getData() << "\n";
	swap(d1, d2);
	swap(d1, d2);
	swap(d1, d2);
	std::wcout << "Make swap data...\n";
	std::wcout << "d1 = " << d1.getData() << "  d2 = " << d2.getData() << "\n";
	swap2(d1, d2);
	swap2(d1, d2);
	swap2(d1, d2);
	std::wcout << "Make swap data...\n";
	std::wcout << "d1 = " << d1.getData() << "  d2 = " << d2.getData() << "\n";
	swap3(d1, d2);
	swap3(d1, d2);
	swap3(d1, d2);
	std::wcout << "Make swap data...\n";
	std::wcout << "d1 = " << d1.getData() << "  d2 = " << d2.getData() << "\n";
	
	std::wcout << "\n";

	return 0;
}
