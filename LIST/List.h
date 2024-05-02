#pragma once
#include <cassert>
namespace mylist{
	///  Node - element for List class
	template <typename T>
	class Node
	{
	public:
		/// data
		T data;
		/// 
		Node* next, * prev;
	public:
		Node(T data)
		{
			this->data = data;
			this->next = this->prev = nullptr;
		}
	};

	/// LinkedList class
	template <typename T>
	class List
	{
	private:
		Node<T>* head;
		Node<T>* tail;

	public:
		List()
		{
			head = tail = nullptr;
		}

		/// push new Node to front of list
		Node<T>* push_front(T newData)
		{
			Node<T>* ptr = new Node<T>(newData);
			ptr->next = head;
			if (head != nullptr)
				head->prev = ptr;
			if (tail == nullptr)
				tail = ptr;
			head = ptr;

			return ptr;
		}

		/// push new Node to back of list
		Node<T>* push_back(T newData)
		{
			Node<T>* ptr = new Node<T>(newData);
			ptr->prev = tail;
			if (tail != nullptr)
				tail->next = ptr;
			if (head == nullptr)
				head = ptr; 
			tail = ptr;

			return ptr;
		}

		/// delete first element
		void pop_front()
		{
			if (head == nullptr) return;

			Node<T>* ptr = head->next;
			if (ptr != nullptr)
				ptr->prev = nullptr;
			else
				tail = nullptr;
			delete head;
			head = ptr;
		}

		/// delete last elm
		void pop_back()
		{
			if (tail == nullptr) return;

			Node<T>* ptr = tail->prev;
			if (ptr != nullptr)
				ptr->next = nullptr;
			else
				head = nullptr;
			delete tail;
			tail = ptr;
		}

		Node<T>* getAt(size_t index)
		{
			Node<T>* ptr = head;
			size_t n = 0;
			while (n != index)
			{
				if (ptr == nullptr)
					return ptr;
				ptr = ptr->next;
				n++;
			}
			return ptr;
		}

		size_t listSize()
		{
			Node<T>* ptr = head;
			size_t n = 0;
			while (ptr != nullptr)
			{
				ptr = ptr->next;
				n++;
			}
			return n;
		}

		Node<T>* operator [](size_t index)
		{
			return getAt(index);
		}

		Node<T>* insert(size_t index, T data)
		{
			Node<T>* right = getAt(index);
			if (right == nullptr)
				return push_back(data);
			Node<T>* left = right->prev;
			if (left == nullptr)
				return push_front(data);

			Node<T>* ptr = new Node<T>(data);
			ptr->prev = left;
			ptr->next = right;
			left->next = ptr;
			right->prev = ptr;

			return ptr;
		}

		void erase(size_t index)
		{
			Node<T>* ptr = getAt(index);
			if (ptr == NULL)
				return;
			if (ptr->prev == NULL)
			{
				pop_front();
				return;
			}
			
			if (ptr->next == NULL)
			{
				pop_back();
				return;
			}
			
			Node<T>* left = ptr->prev;
			Node<T>* right = ptr->next;
			left->next = right;
			right->prev = left;
			delete ptr;
			return;
			
		}

		void clear()
		{
			while (head != nullptr)
				pop_front();
		}

		~List()
		{
			clear();
		}
	};


	void listTest()
	{
		List<int> list;
		list.push_back(0);
		list.push_back(2);
		list.push_back(5);
		assert(list.getAt(0)->data == 0);
		assert(list.getAt(1)->data == 2);
		assert(list.getAt(2)->data == 5);

		list.push_front(3);
		list.push_front(6);
		list.push_front(10);
		assert(list[0]->data == 10);
		assert(list[1]->data == 6);
		assert(list[5]->data == 5);

		list.insert(0, 4); // first
		list.insert(7, 6); // last
		list.insert(5, 9); // mid
		assert(list[0]->data == 4);
		assert(list[8]->data == 6);
		assert(list[5]->data == 9);
	
		list.pop_front();
		assert(list[0]->data == 10);
		assert(list.listSize() == 8);
		list.pop_front();
		assert(list[0]->data == 6);
		assert(list.listSize() == 7);
		list.pop_front();
		assert(list[0]->data == 3);
		assert(list.listSize() == 6);
		
		list.pop_back();
		assert(list[4]->data == 5);
		list.pop_back();
		assert(list[3]->data == 2);
		list.pop_back();
		assert(list[2]->data == 9);

		list.clear();
		assert(list.listSize() == 0);
		list.push_back(0);
		list.push_back(2);
		list.push_back(5);
		list.push_back(3);
		list.push_back(8);
		list.clear();
		assert(list.listSize() == 0);
		list.push_back(0);
		list.push_back(2);
		list.clear();
		assert(list.listSize() == 0);


		list.push_back(0);
		list.push_back(2);
		list.push_back(5);
		list.push_back(1);
		list.push_back(3);
		list.push_back(8);
		list.erase(0);
		assert(list.listSize() == 5);
		assert(list[0]->data == 2);
		list.erase(4);
		assert(list.listSize() == 4);
		assert(list[3]->data == 3);
		list.erase(2);
		assert(list.listSize() == 3);
		assert(list[2]->data == 3);
	}
}

