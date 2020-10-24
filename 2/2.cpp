#include "pch.h"
#include <iostream>
#include <vector>
#include "BinaryTree.cpp"
using namespace std;

int main()
{
	BinaryTree <int> tree(5);
	tree.Add(3);
	tree.Add(1);
	tree.Add(9);
	tree.Add(1);
	tree.Add(10);
	tree.Add(4);
	tree.Add(7);
	tree.Add(6);
	tree.Add(8);
	tree.Print();
	tree.ListNode();
	//cout << "Delete 4" << endl;
	tree.Delete(4);
	tree.Print();
	//cout << "Delete 5" << endl;
	tree.Delete(5);
	tree.Print();
	//cout << "Delete 3" << endl;
	tree.Delete(3);
	tree.Print();
	tree.ListNode();
	system("pause");
	return 0;
}
