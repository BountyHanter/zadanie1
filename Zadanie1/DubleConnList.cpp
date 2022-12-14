#include "DubleConnList.h"

using namespace std;

DubleConnList::DubleConnList()
{
	firstElement = 0;
	lastElement = 0;
	cout << "Start constructor " << this << endl;
}

DubleConnList::~DubleConnList()
{
	while (firstElement)
	{
		lastElement = firstElement->ptrNextElement;
		delete firstElement;
		firstElement = lastElement;
	}
	cout << "Stard destructor " << this << endl;
}

void DubleConnList::swap(Element*& a, Element*& b)
{
	Element* c = b;
	b = a;
	a = c;
}

void DubleConnList::add(char data)
{
	Element* new_element = new Element; 
	new_element->data = data;
	new_element->ptrPrevElement = 0; 
	new_element->ptrNextElement = 0;

	if (!lastElement)
	{
		firstElement = new_element;
	}
	else
	{
		lastElement->ptrNextElement = new_element;
		new_element->ptrPrevElement = lastElement;
	}
	lastElement = new_element;
}

void DubleConnList::show()
{
	if (!lastElement)
	{
		cout << "list empty" << endl;
		return;
	}

	Element* currnet_element = firstElement;
	cout << currnet_element->data << endl;

	while (currnet_element->ptrNextElement)
	{
		currnet_element = currnet_element->ptrNextElement;
		cout << currnet_element->data << endl;
	}


}
void DubleConnList::reverse()
{
	Element* rev = firstElement;
	while (rev)
	{
		swap(rev->ptrNextElement, rev->ptrPrevElement);
		rev = rev->ptrPrevElement;
	}
	swap(firstElement, lastElement);
}

void DubleConnList::insert(char data, int index)
{
	int i = 0;

	Element* Ins = firstElement;

	while (i < index)
	{
		if (Ins->ptrNextElement == 0)
			return;
		Ins = Ins->ptrNextElement;
		i++;
	}

	if (index < 1 || index > i+1)
	{
		cout << "Incorrect position !!!\n";
		return;
	}
	if (index == i+1)
	{
		add(data);
		return;
	}
	else if (index == 0)
	{
		Element* temp = new Element;

		temp->ptrPrevElement = 0;
		temp->data = data;
		temp->ptrNextElement = firstElement;

		if (firstElement != 0)
			firstElement->ptrPrevElement = temp;

		if (i == 0)
			firstElement = lastElement = temp;
		else
			firstElement = temp;
		return;
	}


	Element* PrevIns = Ins->ptrPrevElement;

	Element* temp = new Element;

	temp->data = data;

	if (PrevIns != 0 && PrevIns->ptrNextElement!=0)
		PrevIns->ptrNextElement = temp;

	temp->ptrNextElement = Ins;
	temp->ptrPrevElement = PrevIns;
	Ins->ptrPrevElement = temp;

}


void DubleConnList::remove(int index)
	{
	int i = 0;

	Element* Ins = firstElement;

	while (i < index)
	{
		if (Ins->ptrNextElement == 0)
			break;
		Ins = Ins->ptrNextElement;
		i++;
	}
		if (index < 1 || index > i)
		{
			cout << "Incorrect position !!!\n";
			return;
		}

		int g = 0;
		Element* Del = firstElement;

		while (g < index)
		{
			Del = Del->ptrNextElement;
			g++;
		}
		// доходим до элемента который ДО удаляемого 
		Element* PrevDel = Del->ptrPrevElement;
		Element* AfterDel = Del->ptrNextElement;
		// обозначаем элементы После и ДО удаляемого
		if (PrevDel != 0 && PrevDel->ptrNextElement!=0)
			PrevDel->ptrNextElement = AfterDel;
		if (AfterDel !=0)
			AfterDel->ptrPrevElement = PrevDel;

		if (index == 1)
			firstElement = AfterDel;
		if (index == i)
			lastElement = PrevDel;

		delete Del;

	}

void DubleConnList::clear()
{
	while (firstElement)
	{
		lastElement = firstElement->ptrNextElement;
		delete firstElement;
		firstElement = lastElement;
	}
	firstElement = NULL;
	lastElement = NULL;
}