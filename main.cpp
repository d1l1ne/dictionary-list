#include <iostream>
#include "dict.h"

using namespace std;

int main() {

	dictList<int> empty1;
	dictList<int> list1;
	list1.insert(2);
	list1.insert(1);
	list1.insert(3);
	dictList<int> list2(list1);
	list2.insert(4);

	cout << "list1: ";
	list1.out();
	cout << endl << "list2: ";
	list2.out();
	cout << endl;

	dictList<int> list1c = getInt(list1, list2);

	cout << "list1 and list2 getInt: ";
	list1c.out();
	cout << endl;

	cout << "getInt list1 and empty list: ";
	getInt(empty1, list1);
	cout << endl;

	list2.delete_(4);
	cout << "list2 deleted 4: ";
	list2.out();
	cout << endl;

	list2.delete_(5);
	cout << "list2 deleted 5: ";
	list2.out();
	cout << endl;

	list2.insert(4);
	list1.merge(list2);
	cout << "list1 after merging with list2: ";
	list1.out();
	cout << endl << "list2 after this: ";
	list2.out();
	cout << endl;
	
	list1c.removeList(list1);
	cout << "list1c after removeList list1: ";
	list1c.out();
	cout << endl;

	cout << "first elem in list1: " << list1[0] << endl;

	system("pause");
	return 0;

}