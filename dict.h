#pragma once
#pragma once
#include <iostream>

using namespace std;

template <typename T>
class dictList {

private:

	template<typename T>
	class Node {

	public:

		Node* next;
		T key;

		Node(T key = T(), Node* next = nullptr) {

			this->key = key;
			this->next = next;

		}

	};

	Node<T>* head;
	Node<T>* tail;

	bool insertNode(Node<T>* head_n);
	Node<T>* searchNode(T key_s) const {

		Node<T>* temp = head;

		while (temp != nullptr) {

			if (temp->key == key_s) {

				return temp;

			}

			temp = temp->next;

		}

		return nullptr;

	}

public:

	dictList();
	dictList(const dictList& list) noexcept;
	dictList(dictList&& list) noexcept;
	~dictList() {};
	void insert(T key);
	void delete_(T key_n);
	void search(T key);
	T& operator[](int pos);
	void merge(dictList& list);
	void removeList(dictList& list);
	void out();

	dictList& operator = (const dictList& list) {
		Node<T>* tempnode = nullptr;
		Node<T>* next = head;
		while (next != nullptr) {

			tempnode = next;
			next = next->next;
			delete tempnode;

		}

		this->head = nullptr;
		next = list.head;

		while (next != nullptr) {

			Node<T>* temp = new Node<T>(next->key);
			this->insertNode(temp);
			next = next->next;

		}

		return *this;

	}

	dictList& operator = (dictList&& list) noexcept {

		if (this->head != list.head) {

			this->head = list.head;
			list.head = nullptr;

		}

		if (this->tail != list.tail) {

			this->tail = list.tail;
			list.tail = nullptr;

		}

		return *this;

	}


	friend dictList getInt(dictList& list1, dictList& list2) {

		dictList<T> new_;

		if (list1.head == nullptr || list2.head == nullptr) {

			std::cerr << "empty list/s";

			return new_;

		}

		dictList<T>::template Node<T>* temp1 = list1.head;

		while (temp1 != nullptr) {

			dictList<T>::template Node<T>* temp2 = list2.head;

			while (temp2 != nullptr) {

				if (temp1->key == temp2->key) {

					new_.insert(temp1->key);
					break;

				}

				temp2 = temp2->next;

			}

			temp1 = temp1->next;

		}

		return new_;

	}

};

template<typename T>
bool dictList<T>::insertNode(Node<T>* head_n)
{
	if (head_n == nullptr) {

		std::cerr << "Empty node";
		return false;

	}

	if (head == nullptr || tail == nullptr) {

		head = head_n;
		tail = head_n;
		return true;

	}

	if (head->key == head_n->key) {

		return false;

	}

	if (head->key > head_n->key) {

		head_n->next = head;
		head = head_n;
		return true;

	}

	Node<T>* temp = head;
	while (temp->next != nullptr) {

		if (temp->next->key == head_n->key) {

			return false;

		}

		if (temp->next->key > head_n->key) {

			head_n->next = temp->next;
			temp->next = head_n;
			return true;

		}

		temp = temp->next;

	}

	temp->next = head_n;
	return true;

}

template<typename T>
dictList<T>::dictList() {

	head = nullptr;
	tail = nullptr;

}

template<typename T>
dictList<T>::dictList(const dictList& list)noexcept {

	this->head = nullptr;
	this->tail = nullptr;
	Node<T>* next = list.head;

	while (next != nullptr) {

		Node<T>* temp = new Node<T>(next->key);
		this->insertNode(temp);
		next = next->next;

	}

}

template<typename T>
dictList<T>::dictList(dictList&& list)noexcept {

	this->head = list.head;
	list.head = nullptr;
	this->tail = list.tail;
	list.tail = nullptr;

}

template<typename T>
void dictList<T>::insert(T key) {

	Node<T>* temp = new Node<T>(key);
	if (insertNode(temp)) {

		return;

	}

	delete temp;

}

template<typename T>
void dictList<T>::delete_(T key_n) {

	Node<T>* toDel = searchNode(key_n);
	if (toDel == nullptr) {

		return;

	}

	if (head->key == toDel->key) {

		Node<T>* tempnode = head->next;
		delete head;
		head = tempnode;
		return;

	}

	Node<T>* temp = head;

	while (temp->next != toDel) {

		temp = temp->next;

	}

	temp->next = toDel->next;
	return;

}

template<typename T>
void dictList<T>::search(T key) {

	if (searchNode(key) == nullptr) {

		cout << "Not in dictionary";
		return;

	}

	cout << "Found in dictionary";

}

template<typename T>
T& dictList<T>::operator[](int pos) {

	int count = 0;
	Node<T>* over = this->head;

	while (over != nullptr) {

		if (count == pos) {

			return over->key;

		}

		over = over->next;
		count++;

	}

}

template<typename T>
void dictList<T>::merge(dictList& list) {

	while (list.head != nullptr) {

		Node<T>* tempnode = list.head->next;
		list.head->next = nullptr;

		if (insertNode(list.head)) {

			list.head = tempnode;
			continue;

		}

		delete list.head;
		list.head = tempnode;

	}

}

template<typename T>
void dictList<T>::removeList(dictList& list) {

	if (list.head == nullptr || head == nullptr) {

		std::cerr << "empty list";
		return;

	}

	else if (tail == nullptr) {

		std::cerr << "empty list";
		return;

	}

	Node<T>* temp = list.head;

	while (temp != nullptr) {

		this->delete_(temp->key);
		temp = temp->next;

	}

	Node<T>* temp_ = list.tail;

	while (temp_ != nullptr) {

		this->delete_(temp_->key);
		temp_ = temp_->next;

	}

}

template<typename T>
void dictList<T>::out() {

	Node<T>* over = this->head;

	while (over != nullptr) {

		cout<<over->key<< " ";

		over = over->next;

	}

}