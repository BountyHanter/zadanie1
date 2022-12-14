#pragma once
#include <iostream>
class DubleConnList
{
private: 
	struct Element
	{
		Element* ptrPrevElement;
		char data;
		Element* ptrNextElement;

	};
	void swap(Element*& a, Element*& b);
	Element* firstElement;
	Element* lastElement;

public:
	DubleConnList();
	~DubleConnList();

	void add(char data);
	void show();
	void reverse();
	void insert(char data, int index);
	void Void();
	void remove(int index);
	void clear();


	DubleConnList(const DubleConnList& other)
	{
		Element* current_element1 = other.firstElement; /* создаем внутреннюю новую переменную типа Element(в котором есть 3 параметра - 2 указателя и символьный тип данных)
		и засовывваем туда данные из первого элемента
		*/
		while (current_element1)
		{
			add(current_element1->data); // далее вызываем функцию добавления в котором повторяем тоже самое что и с первым списком но копируем это во второй
			current_element1 = current_element1->ptrNextElement; // и переносим наш элемент на следующий элемент, до тех пор пока наш элемент не равен MULL.
		}
		std::cout << "start copy constructor " << this << std::endl;
	}
	void operator = (const DubleConnList& other) // в отличии от конструктора копирования мы сначала зачищаем наш контейнер для того чтобы перенести в него новые значения
	{
		clear();
		std::cout << "Start assignment operator " << std::endl;
		Element* current_element1 = other.firstElement;
		while (current_element1) // переписываем из копируемого контейнера данные в новый
		{
			add(current_element1->data);
			current_element1 = current_element1->ptrNextElement;
		}
	}
	DubleConnList(DubleConnList&& other) noexcept // перемещаем данные и зачищаем данные в перемещаемом контейнере
	{
		firstElement = other.firstElement; // здесь мы просто перемещаем указатели, не нужно зачищать ничего
		lastElement = other.lastElement;
		other.firstElement = NULL; // а старые указатели зануляем
		other.lastElement = NULL;
	}
	void operator = (DubleConnList&& other) noexcept // зачищаем данные с контейнера в который перемещаем, перемещаем данные, и зачищаем перемещаемый контейнер
	{
		std::cout << "Start move operator " << std::endl; // здесь мы только зачищаем первоначальный контейнер, перемещаем указатели, а старые указатели зануляем
		clear();
		firstElement = other.firstElement;
		lastElement = other.lastElement;
		other.firstElement = NULL;
		other.lastElement = NULL;
	}


};

