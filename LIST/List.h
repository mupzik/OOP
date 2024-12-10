// developer Volosikova M.A.
#pragma once
#include <cassert>
#include <stack>
namespace mylist {
	///  Node - element for List class
	template <typename T>
	class Node
	{
	public:
		/// data
		T data;
		/// poiners to next and previous Nodes
		Node* next, * prev;
		/// конструктор
		Node(T data)
		{
			this->data = data;
			this->next = this->prev = nullptr;
		}

		/// конструктор по умолчанию
		Node()
		{
			this->data = this->next = this->prev = nullptr;
		}
	};

	/// LinkedList class
	template <typename T>
	class List
	{
	private:
		/// pointer to first elem
		Node<T>* head;
		/// pointer to last elem
		Node<T>* tail;
		/// size of list
		size_t size;

		//  ласс итератора по списку
		class Iterator {
		private:

			// —лужебный рабочий стак
			std::stack<List<T>*> nodeStack;

			// ”зел в данной итерации
			List<T>* currentNode;

			// ѕомещает всю левую ветку в стэк
			void pushLeftBranch(List<T>* node) {
				while (node != nullptr) {
					nodeStack.push(node);
					node = node->next;
				}
			}

		public:

			Iterator(List<T>* root) {
				// ѕолностью помещает ссылки на узлы дерева в стэк, N | N | N
				pushLeftBranch(root);
			}

			bool operator!=(const Iterator& other) const {
				return !nodeStack.empty() || !other.nodeStack.empty();
			}

			// ѕровер€ет есть ли ещЄ узлы в служебном стэке
			bool hasNext() {
				return !nodeStack.empty() || currentNode != nullptr;
			}

			// ќператор возвратит данные узла текущей итерации
			T& operator*() const {
				return currentNode->data;
			}

			// ƒанные узла текущей итерации
			T& data() {
				return currentNode->data;
			}

			// ѕереход на следующую итерацию
			Iterator& operator++() {
				return next();
			}

			// —брасывает итератор до изначального состо€ни€, обновл€€ данные N | N | N
			void reset() {
				nodeStack.empty();
				currentNode = head;
				inorderStack(head, nodeStack);
			}

			// ѕерейти на следующую итерацию
			Iterator& next() {
				List<T>* currentNode = nodeStack.top();
				if (!hasNext()) {
					throw std::out_of_range("No more elements in the iterator");
				}
				currentNode = nodeStack.top();
				nodeStack.pop();
				return *this;
			}

		};

		// ¬озвращает итератор в начальной позиции
		Iterator begin() {
			return Iterator(head);
		}

		// ¬озвращает итератор в конечной позиции
		Iterator end() {
			return Iterator(nullptr);
		}





	public:
		/// конструктор по умолчанию
		List()
		{
			head = tail = nullptr;
			size = 0;
		}

		/// конструктор с параметрами
		List(const T data)
		{
			push_front(data);
			size = 1;
		}

		/// конструктор с параметрами
		List(const Node<T>* newData)
		{
			head->data = newData->data;
			head->next = newData->next;
			head->prev = newData->prev;
			size = 1;
		}

		/// конструктор перемещени€
		List(List<T>&& list)
		{
			head = list->head;
			tail = list->tail;
			size = list.getSize();
			list.untie();
		}

		/// конструктор копировании€
		List(const List<T>& list)
		{
			copy(list);
		}

		/// оператор присваивани€ копированием
		List& operator = (const List&& list)
		{
			// clear data
			clear();

			// copy list
			copy(list);

			return *this;
		}

		/// оператор присваивани€ перемещением
		List& operator = (List& list)
		{
			// clear data
			clear();

			// moving list
			head = list->head;
			tail = list->tail;
			size = list.getSize();
			list.untie();

			return *this;
		}

		/// untie variable from data
		void untie()
		{
			head = tail = nullptr;
			size = 0;
		}

		/// copy data from list node by node
		void copy(const List<T>& list)
		{
			// new node for work
			Node<T>* cur;
			cur = list->head;
			// copy node by node
			while (cur != nullptr)
			{
				push_back(cur->data);
				cur = cur->next;
			}

			// delete cur
			delete cur;
		}

		/// push new Node to front of list
		/// O(1)
		Node<T>* push_front(T newData)
		{
			// make new Node
			Node<T>* ptr = new Node<T>(newData);
			// shange pointers
			ptr->next = head;
			if (head != nullptr)
				head->prev = ptr;
			if (tail == nullptr)
				tail = ptr;
			// new Node is first now
			head = ptr;
			// size +1
			size++;

			return ptr;
		}

		/// push new Node to back of list
		/// O(1)
		Node<T>* push_back(T newData)
		{
			// make new Node
			Node<T>* ptr = new Node<T>(newData);
			// change poiters
			ptr->prev = tail;
			if (tail != nullptr)
				tail->next = ptr;
			if (head == nullptr)
				head = ptr;
			// new elem is the last one
			tail = ptr;
			// size+1
			size++;

			return ptr;
		}

		/// delete first element
		/// o(1)
		void pop_front()
		{
			// return if list is empty
			if (head == nullptr) return;

			// shange pointer
			Node<T>* ptr = head->next;
			if (ptr != nullptr)
				ptr->prev = nullptr;
			else
				tail = nullptr;
			// delete memory
			delete head;
			// new head
			head = ptr;
			// size-1
			size--;
		}

		/// delete last elm
		/// o(1)
		void pop_back()
		{
			// return if list is empty
			if (tail == nullptr) return;

			// change pointers
			Node<T>* ptr = tail->prev;
			if (ptr != nullptr)
				ptr->next = nullptr;
			else
				head = nullptr;
			// delete memory
			delete tail;
			// new tail
			tail = ptr;
			// size-1
			size--;
		}

		/// return node at the index
		/// O(n)
		Node<T>* getAt(size_t index) const
		{

			// copy pointer to work
			Node<T>* ptr = head;
			// index to find
			size_t n = 0;
			while (n != index)
			{
				// return nullptr if index out of size
				if (ptr == nullptr)
					return ptr;
				ptr = ptr->next;
				n++;
			}
			// return Node at the index
			return ptr;
		}

		/// returned size of list
		/// O(n)
		size_t getSize() const
		{
			return size;
		}

		/// returned node at the index
		/// o(n)
		Node<T>* operator [](size_t index) const
		{
			return getAt(index);
		}

		/// insert new node at the list 
		/// O(n)
		Node<T>* insert(size_t index, T data)
		{
			// find Node at index (if not, then push_back
			Node<T>* right = getAt(index);
			// push new node at the tail
			if (right == nullptr)
				return push_back(data);
			// find prev Node
			Node<T>* left = right->prev;
			// push new node at the head
			if (left == nullptr)
				return push_front(data);

			// make new Node
			Node<T>* ptr = new Node<T>(data);
			// change pointers
			ptr->prev = left;
			ptr->next = right;
			left->next = ptr;
			right->prev = ptr;

			return ptr;
		}

		/// erase an element from list
		void erase(size_t index)
		{
			// get Node at index
			Node<T>* ptr = getAt(index);
			// return if there is nothing to erase
			if (ptr == NULL)
				return;
			// erase if it in head
			if (ptr->prev == NULL)
			{
				pop_front();
				return;
			}

			// erase if it in tail
			if (ptr->next == NULL)
			{
				pop_back();
				return;
			}

			// change pointers 
			Node<T>* left = ptr->prev;
			Node<T>* right = ptr->next;
			left->next = right;
			right->prev = left;
			// delete memory
			delete ptr;
			// size -1
			size--;
			return;

		}

		/// search
		/// O(n)
		long long search(T key) const
		{
			// new Node for work
			Node<T>* cur = head;
			// index for search
			long long index = 0;
			// searching
			while (cur != nullptr)
			{
				if (cur->data == key) return index;
				cur = cur->next;
				index++;
			}
			// return -1 if there is no key
			return -1;
		}

		// clear list
		void clear()
		{
			while (head != nullptr)
				pop_front();
			size = 0;
		}

		///returned head
		Node<T>* get_head()
		{
			return head;
		}
		
		/// returned tail
		Node<T>* get_tail()
		{
			return tail;
		}

		// destructor
		~List()
		{
			clear();
		}
	};

	/// test function for list class
	void listTest()
	{
		// list for work
		List<int> list;

		// push_back, getAt
		list.push_back(0);
		list.push_back(2);
		list.push_back(5);
		assert(list.getAt(0)->data == 0);
		assert(list.getAt(1)->data == 2);
		assert(list.getAt(2)->data == 5);

		// push_front, []
		list.push_front(3);
		list.push_front(6);
		list.push_front(10);
		assert(list[0]->data == 10);
		assert(list[1]->data == 6);
		assert(list[5]->data == 5);

		// insert
		list.insert(0, 4); // first
		list.insert(7, 6); // last
		list.insert(5, 9); // mid
		list.insert(200, 8); // > size
		assert(list[0]->data == 4);
		assert(list[8]->data == 6);
		assert(list[5]->data == 9);
		assert(list[9]->data == 8);

		// search
		assert(list.search(4) == 0); // first
		assert(list.search(8) == 9); // last
		assert(list.search(9) == 5); // mid
		assert(list.search(20) == -1); // no key

		// pop front
		list.pop_front();
		assert(list[0]->data == 10);
		assert(list.getSize() == 8);
		list.pop_front();
		assert(list[0]->data == 6);
		assert(list.getSize() == 7);
		list.pop_front();
		assert(list[0]->data == 3);
		assert(list.getSize() == 6);

		// pop_back
		list.pop_back();
		assert(list[4]->data == 5);
		list.pop_back();
		assert(list[3]->data == 2);
		list.pop_back();
		assert(list[2]->data == 9);

		// clear
		list.clear();
		assert(list.getSize() == 0);
		list.push_back(0);
		list.push_back(2);
		list.push_back(5);
		list.push_back(3);
		list.push_back(8);
		list.clear();
		assert(list.getSize() == 0);
		list.push_back(0);
		list.push_back(2);
		list.clear();
		assert(list.getSize() == 0);
		list.pop_back();
		assert(list.getSize() == 0);
		list.pop_front();
		assert(list.getSize() == 0);

		// erase
		list.push_back(0);
		list.push_back(2);
		list.push_back(5);
		list.push_back(1);
		list.push_back(3);
		list.push_back(8);
		list.erase(0);
		assert(list.getSize() == 5);
		assert(list[0]->data == 2);
		list.erase(4);
		assert(list.getSize() == 4);
		assert(list[3]->data == 3);
		list.erase(2);
		assert(list.getSize() == 3);
		assert(list[2]->data == 3);
	}

	/// class stack
	template <typename T>
	class Stack
	{
	private:
		/// data for Stack
		/// using class List
		List<T> list;
	public:
		/// конструктор 
		Stack()
		{
			List<T> list;
		}

		/// push new data on Stack
		/// O(1)
		void push(T newData)
		{
			list.push_back(newData);
			return;
		}

		/// pop data from stack
		/// O(1)
		T pop()
		{
			if (list.get_tail() == nullptr) 
					return T();
			
			T cur = list.get_tail()->data;
			list.pop_back();
			return cur;
		}

		/// return size of stack
		size_t getSize() const
		{
			return list.getSize();
		}

		/// see data
		/// O(1)
		T peek()
		{
			if (list.get_tail() == nullptr)
				return T();

			return list.get_tail()->data;
		}

		/// clear stack
		/// O(n)
		void clear()
		{
			list.clear();
			return;
		}
	};

	/// queue class
	template <typename T>
	class Queue
	{
	private:
		/// data for  Queue
		/// using class List
		List<T> list;

	public:
		/// конструктор класса
		Queue()
		{
			List<T> list;
		}

		/// O(1)
		/// push new data in Queue
		void push(T newData)
		{
			list.push_front(newData);
			return;
		}

		/// O(1)
		/// pop  data from the Queue
		T pop()
		{
			if (list.get_tail() == nullptr)
				return T();

			T cur = list.get_tail()->data;
			list.pop_back();
			return cur;
		}

		/// return size of queue
		size_t getSize() const
		{
			return list.getSize();
		}

		/// O(1)
		/// see data
		T peek()
		{
			if (list.get_tail() == nullptr)
				return T();

			return list.get_tail()->data;
		}

		/// O(n)
		/// clear Queue
		void clear()
		{
			list.clear();
			return;
		}
	};

	/// stack class test
	void stack_test()
	{
		Stack<int> stk;

		// getSize, peek, push test
		assert(stk.getSize() == 0);
		assert(stk.peek() == 0); // try to peek empty stack
		stk.push(0);
		assert(stk.getSize() == 1);
		assert(stk.peek() == 0);
		stk.push(1);
		assert(stk.getSize() == 2);
		assert(stk.peek() == 1);
		stk.push(2);
		assert(stk.getSize() == 3);
		assert(stk.peek() == 2);

		// pop test
		assert(stk.pop() == 2);
		assert(stk.peek() == 1);
		assert(stk.pop() == 1);
		assert(stk.peek() == 0);
		assert(stk.pop() == 0);
		assert(stk.peek() == 0);
		assert(stk.pop() == 0); // try to pop from empty stack

		// clear test
		for (int i = 0; i < 10; i++)
			stk.push(i);
		stk.clear();
		assert(stk.getSize() == 0);
		for (int i = 0; i < 10; i++)
			stk.push(i);
		stk.clear();
		assert(stk.getSize() == 0);
		for (int i = 0; i < 10; i++)
			stk.push(i);
		stk.clear();
		assert(stk.getSize() == 0);

	}

	/// queue class test
	void queue_test()
	{
		Queue<int> que;

		// getSize, peek, push test
		assert(que.getSize() == 0);
		assert(que.peek() == 0); // try to peek empty queue
		que.push(0);
		assert(que.getSize() == 1);
		assert(que.peek() == 0);
		que.push(1);
		assert(que.getSize() == 2);
		assert(que.peek() == 0);
		que.push(2);
		assert(que.getSize() == 3);
		assert(que.peek() == 0);

		// pop test
		assert(que.pop() == 0);
		assert(que.peek() == 1);
		assert(que.pop() == 1);
		assert(que.peek() == 2);
		assert(que.pop() == 2);
		assert(que.peek() == 0);
		assert(que.pop() == 0); // try to pop from empty queue

		// clear test
		for (int i = 0; i < 10; i++)
			que.push(i);
		que.clear();
		assert(que.getSize() == 0);
		for (int i = 0; i < 10; i++)
			que.push(i);
		que.clear();
		assert(que.getSize() == 0);
		for (int i = 0; i < 10; i++)
			que.push(i);
		que.clear();
		assert(que.getSize() == 0);
	}


	/// queue class
	template <typename T>
	class Deck
	{
	private:
		/// data for  Queue
		/// using class List
		List<T> list;

	public:
		/// конструктор класса
		Deck()
		{
			List<T> list;
		}

		/// O(1)
		/// push new data in front of Deck
		void push_front(T newData)
		{
			list.push_front(newData);
			return;
		}
		
		/// O(1)
		/// push new data in tail of Deck
		void push_back(T newData)
		{
			list.push_back(newData);
			return;
		}

		/// O(1)
		/// pop data from back of the Deck
		T pop_back()
		{
			if (list.get_tail() == nullptr)
				return T();

			T cur = list.get_tail()->data;
			list.pop_back();
			return cur;
		}

		/// O(1)
		/// pop  data from front of the Deck
		T pop_front()
		{
			if (list.get_head() == nullptr)
				return T();

			T cur = list.get_head()->data;
			list.pop_front();
			return cur;
		}

		/// return size of queue
		size_t getSize() const
		{
			return list.getSize();
		}

		/// O(1)
		/// see back data
		T peek_back()
		{
			if (list.get_tail() == nullptr)
				return T();

			return list.get_tail()->data;
		}
		
		/// O(1)
		/// see front data
		T peek_front()
		{
			if (list.get_head() == nullptr)
				return T();
		//	return list.get_head->data;
		}

		/// O(n)
		/// clear Queue
		void clear()
		{
			list.clear();
			return;
		}
	};


	/// stack class test
	void deck_test()
	{
		Deck<int> dck;

		// _back tests
		// getSize, peek_back, push_back test
		assert(dck.getSize() == 0);
		assert(dck.peek_back() == 0); // try to peek empty deck
		dck.push_back(0);
		assert(dck.getSize() == 1);
		assert(dck.peek_back() == 0);
		dck.push_back(1);
		assert(dck.getSize() == 2);
		assert(dck.peek_back() == 1);
		dck.push_back(2);
		assert(dck.getSize() == 3);
		assert(dck.peek_back() == 2);

		// pop test
		assert(dck.pop_back() == 2);
		assert(dck.peek_back() == 1);
		assert(dck.pop_back() == 1);
		assert(dck.peek_back() == 0);
		assert(dck.pop_back() == 0);
		assert(dck.peek_back() == 0);
		assert(dck.pop_back() == 0); // try to pop from empty deck

		// clear test
		for (int i = 0; i < 10; i++)
			dck.push_back(i);
		dck.clear();
		assert(dck.getSize() == 0);
		for (int i = 0; i < 10; i++)
			dck.push_back(i);
		dck.clear();
		assert(dck.getSize() == 0);
		for (int i = 0; i < 10; i++)
			dck.push_back(i);
		dck.clear();
		assert(dck.getSize() == 0);

		// _front tests
		// peek_front, push_front test
		assert(dck.getSize() == 0);
		assert(dck.peek_front() == 0); // try to peek empty deck
		dck.push_front(0);
		assert(dck.getSize() == 1);
		assert(dck.peek_front() == 0);
		dck.push_front(1);
		assert(dck.getSize() == 2);
		assert(dck.peek_front() == 0);
		dck.push_front(2);
		assert(dck.getSize() == 3);
		assert(dck.peek_front() == 0);

		// pop_front test
		assert(dck.pop_front() == 0);
		assert(dck.peek_front() == 1);
		assert(dck.pop_front() == 1);
		assert(dck.peek_front() == 2);
		assert(dck.pop_front() == 2);
		assert(dck.peek_front() == 0);
		assert(dck.pop_front() == 0); // try to pop from empty deck

	}
}

