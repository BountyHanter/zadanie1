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
		Element* current_element1 = other.firstElement; /* ������� ���������� ����� ���������� ���� Element(� ������� ���� 3 ��������� - 2 ��������� � ���������� ��� ������)
		� ����������� ���� ������ �� ������� ��������
		*/
		while (current_element1)
		{
			add(current_element1->data); // ����� �������� ������� ���������� � ������� ��������� ���� ����� ��� � � ������ ������� �� �������� ��� �� ������
			current_element1 = current_element1->ptrNextElement; // � ��������� ��� ������� �� ��������� �������, �� ��� ��� ���� ��� ������� �� ����� MULL.
		}
		std::cout << "start copy constructor " << this << std::endl;
	}
	void operator = (const DubleConnList& other) // � ������� �� ������������ ����������� �� ������� �������� ��� ��������� ��� ���� ����� ��������� � ���� ����� ��������
	{
		clear();
		std::cout << "Start assignment operator " << std::endl;
		Element* current_element1 = other.firstElement;
		while (current_element1) // ������������ �� ����������� ���������� ������ � �����
		{
			add(current_element1->data);
			current_element1 = current_element1->ptrNextElement;
		}
	}
	DubleConnList(DubleConnList&& other) noexcept // ���������� ������ � �������� ������ � ������������ ����������
	{
		firstElement = other.firstElement; // ����� �� ������ ���������� ���������, �� ����� �������� ������
		lastElement = other.lastElement;
		other.firstElement = NULL; // � ������ ��������� ��������
		other.lastElement = NULL;
	}
	void operator = (DubleConnList&& other) noexcept // �������� ������ � ���������� � ������� ����������, ���������� ������, � �������� ������������ ���������
	{
		std::cout << "Start move operator " << std::endl; // ����� �� ������ �������� �������������� ���������, ���������� ���������, � ������ ��������� ��������
		clear();
		firstElement = other.firstElement;
		lastElement = other.lastElement;
		other.firstElement = NULL;
		other.lastElement = NULL;
	}


};

