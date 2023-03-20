#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
#include <array>
#include "SecondaryFunction.h"

/*
Создать класс Data, содержащий в качестве полей скалярные
данные и мьютекс. Создать функцию swap, которая принимает
ссылки на два объекта класса Data и обменивает их местами.

В функция необходимо сначала захватить мьютексы обоих объектов,
а затем выполнеть обмен данными. Реализовать три варианта данной
функции: при помощи lock, scoped_lock и unique_lock.
*/



int main(int argc, char** argv)
{
	printHeader(L"Защищенный обмен данными");

	
	std::wcout << "\n";

	return 0;
}
