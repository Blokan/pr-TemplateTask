#include "pch.h"
#pragma once
#include <iostream>
#include "vector"
using namespace std;

template <class t> class BinaryTree {
private:
	struct Node {
		t value;
		int parent = -1;
		int left = -1; 
		int right = -1;
	};
	vector<Node> ArrPoint;
public:
	BinaryTree(t element) {
		Node newpoint; //создать элемент в дереве (самый первый, как корень дерева)
		newpoint.value = element; //записать в элемент значение
		ArrPoint.push_back(newpoint); //записать в массив (в душе не ебу, зачем, пока что, но Ќикита сказал, что надо)
	}

	void Print()
	{
		
		/*PrintTree(0);
		cout << endl;*/
		for (int i = 0; i < ArrPoint.size(); i++)
			cout << ArrPoint[i].value << ' ';
		cout << endl;
	}
	/*void PrintTree(int i) 
	{
		if (i != -1 && i < ArrPoint.size()) {
			if (ArrPoint[i].left != -1) PrintTree(ArrPoint[i].left);
			cout << ArrPoint[i].value << " ";
			if (ArrPoint[i].right != -1) PrintTree(ArrPoint[i].right);
		}
	}*/

	void Add(t element)
	{
		Node newpoint;
		newpoint.value = element;

		bool addelem = false; //пока на место не взойдет
		int i = 0;
		while (!addelem)
		{
			if (newpoint.value < ArrPoint[i].value) //если элемент меньше и левого потомка нет, то это левый потомок, иначе перейти к левому потомку и с ним работать
			{
				if (ArrPoint[i].left == -1)
				{
					ArrPoint[i].left = ArrPoint.size();
					newpoint.parent = i;
					ArrPoint.push_back(newpoint);
					addelem = true;
				}
				else
					i = ArrPoint[i].left;
			}
			else
			{
				if (ArrPoint[i].right == -1)
				{
					ArrPoint[i].right = ArrPoint.size();
					newpoint.parent = i;
					ArrPoint.push_back(newpoint);
					addelem = true;
				}
				else
					i = ArrPoint[i].right;
			}
		}
	}

	void Delete(t value)
	{
		int i = this->Search(value);
		if (i != -1) //если элемент существует
		{
			cout << "Delete "<< ArrPoint[i].value << endl;
			if (ArrPoint[i].left == -1 && ArrPoint[i].right == -1) //если у узла нет потомков, то просто удалить
			{
				if (i == ArrPoint[ArrPoint[i].parent].right) ArrPoint[ArrPoint[i].parent].right = -1;
				else /*if (i == ArrPoint[ArrPoint[i].parent].left) */ArrPoint[ArrPoint[i].parent].left = -1;
				ArrPoint.erase(ArrPoint.begin() + i);
			}
			else {
				if (ArrPoint[i].left == -1) //нет левого потомка
				{
					int j = ArrPoint[i].right;
					ArrPoint[i].value = ArrPoint[j].value;
					ArrPoint[i].right = ArrPoint[j].right;
					ArrPoint[i].left = ArrPoint[j].left;
					ArrPoint[j].parent = i;
					ArrPoint.erase(ArrPoint.begin() + j);
				}
				else {
					if (ArrPoint[i].right == -1) //нет правого
					{
						int j = ArrPoint[i].left;
						ArrPoint[i].value = ArrPoint[j].value;
						ArrPoint[i].right = ArrPoint[j].right; 
						ArrPoint[i].left = ArrPoint[j].left;
						ArrPoint[j].parent = i;
						ArrPoint.erase(ArrPoint.begin() + j);
					}
					else //есть оба потомка
					{ 
						int j = ArrPoint[i].right;
						int k = ArrPoint[i].left;
						int z = ArrPoint[i].right;
						ArrPoint[i].value = ArrPoint[j].value;
						
						
						ArrPoint[i].left = ArrPoint[j].left;
						ArrPoint[j].parent = i;
						ArrPoint[k].parent = i;
						while (ArrPoint[z].left != -1)
						{
							z = ArrPoint[z].left;
						}
						ArrPoint[i].value = ArrPoint[z].value;
						ArrPoint[i].left = k;
						i = z;
						if (z == ArrPoint[ArrPoint[z].parent].left) ArrPoint[ArrPoint[z].parent].left = -1;
						ArrPoint.erase(ArrPoint.begin() + z);
					}
				}
			}
			for (int n = i; n < ArrPoint.size(); n++)
				{
				if (ArrPoint[n].left != -1) { 
					ArrPoint[n].left--; 
					if (ArrPoint[n].parent != -1 && ArrPoint[ArrPoint[n].parent].left != n && ArrPoint[n].parent == 0/*ArrPoint[n].left*/)
						ArrPoint[ArrPoint[n].parent].left = n/*ArrPoint[n].left*/;
				}
				if (ArrPoint[n].right != -1) {
					ArrPoint[n].right--;
					if (ArrPoint[n].parent != -1 && ArrPoint[ArrPoint[n].parent].right == ArrPoint[n].parent + 1)/*ArrPoint[n].right*/
					ArrPoint[ArrPoint[n].parent].right = ArrPoint[n].parent;
				}
					if (ArrPoint[n].parent > i) ArrPoint[n].parent--;
				}
		}
	}

	int Search(t element)
	{
		int i = 0;
		bool exist = false;
		int indexvect = -1;
		while (!exist)
		{
			if (element < ArrPoint[i].value) //проверка значени€
			{
				if (ArrPoint[i].value == element) //если равен узлу дерева
				{
					indexvect = i; //нужный элемент
					exist = true;
				}
				else {
					if (ArrPoint[i].left == -1) exist = true; //не найден
					else i = ArrPoint[i].left; //перейти в левый конец
				}
			}
			else
			{
				if (ArrPoint[i].value == element)
				{
					indexvect = i;
					exist = true;
				}
				else {
					if (ArrPoint[i].right == -1) exist = true;
					else i = ArrPoint[i].right;
				}
			}

		}
		return indexvect;
	}

	void ListNode() {
		for (int i = 0; i < ArrPoint.size(); i++)
			if (ArrPoint[i].left == -1 && ArrPoint[i].right == -1)
			cout << ArrPoint[i].value << ' ';
		cout << endl;
	}

	~BinaryTree() {}
};

