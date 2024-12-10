/// dev Volosikova M.A.
// суть функции, O(n), тип return
#pragma once
#include <vector>
#include <functional>
#include <stack>
#include <cassert>
using namespace std;

/// <summary>
/// Tree_node class - class for data structure binary tree.
/// </summary>
template <typename T>
struct TreeNode
{
public:

	/// data in the node
	T data;

	/// links for two leafes
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;

	/// default constructor
	TreeNode() 
	{
		data = NULL;
		left = nullptr;
		right = nullptr;
	}

	
	/// конструктор, принимающий данные и узлы-потомки
	TreeNode(T new_data, TreeNode<T>* new_left = nullptr, TreeNode<T>* new_right = nullptr)
	{
		data = new_data;
		left = new_left;
		right = new_right;
	}


	/// конструктор копирования
	TreeNode(const TreeNode<T>* copy)
	{
		data = copy->data;
		left = copy->left;
		right = copy->right;
	}




	/// конструктор перемещениия
	TreeNode(TreeNode&& other) : data(other.data), left(other.left), right(other.right)
	{
		// Перемещаем указатели на предыдущий и следующий узлы
		other.left = nullptr;
		other.right = nullptr;
	}

	/// оператор копирования

	TreeNode& operator = (const TreeNode& other)
	{
		// Проверяем самоприсваивание
		if (this == &other) {
			return *this;
		}

		// Удаляем текущие указатели на предыдущий и следующий узлы
		delete left;
		delete right;

		// Копируем данные и указатели из другого узла
		data = other.data;
		if (other.left != nullptr) {
			left = new TreeNode(other.left->data);
		}
		if (other.right != nullptr) {
			right = new TreeNode(other.right->data);
		}

		return *this;
	}


	//Оператор перемещения :

	TreeNode& operator = (TreeNode&& other)
	{
		// Проверяем самоприсваивание
		if (this == &other) {
			return *this;
		}

		// Перемещаем данные и указатели из другого узла
		data = other.data;
		left = other.left;
		right = other.right;

		// Очищаем указатели в перемещаемом узле
		other.left = nullptr;
		other.right = nullptr;

		return *this;
	}

};

/// <summary>
/// Tree class is data structure 
///  
/// </summary>
template <typename T>
class Tree
{
private:
	/// <summary>
	///  first node for Tree, the main node
	/// </summary>
	TreeNode<T>* root = nullptr;

public:
	Tree() :root(nullptr) {}
	Tree(T value) {
		root = new TreeNode<T>(value);
	}

	~Tree() {
		deleteTree(root);
	}

	
	// Копировать древо. Возвращает древо
	Tree copy()
	{
		Tree tree;
		copyTreeRecursive(root, tree);
		return tree;
	}


	// Очистка древа
	void clear() {
		deleteTree(root);   // Очищаем дерево
		root = nullptr; // Обнуляем корень дерева
	}
	
	// Добавить значение к узлу в виде нового узла
	static void addNode(TreeNode<T>* node, T value) {
		if (value < node->data) {
			if (node->left) {
				addNode(node->left, value);
			}
			else
			{
				node->left = new TreeNode<T>(value);
			}
		}
		else
		{
			if (node->right) {
				addNode(node->right, value);
			}
			else
			{
				node->right = new TreeNode<T>(value);
			}
		}
	}
	// Добавить значение дереву
	void insert(const T& value) {
		if (!root) {
			root = new TreeNode<T>(value);
		}
		else
		{
			addNode(root, value);
		}
	}


	// Вывести значение узла на экран
	void printNode(TreeNode<T>* node) const {
		if (node) {
			cout << node->data << endl;
		}
		else {
			cout << "Пусто" << endl;
		}
	}

	

	

	
	void remove(T value)
	{
		if (isEmpty())
			throw std::out_of_range("Дерево пустое");
		deleteNodeRecursive(&root, value);
	}

	// Функция определения глубины дерева
	int getDepth() const {
		return depth(root);
	}
	// Функция подсчета числа узлов
	size_t countNodes() const {
		return count(root);
	}
	// Проверка на пустоту дерева
	bool isEmpty() const {
		if (root != nullptr)
			return false;
		else
			return true;
	}

	// Поиск следующего наибольшего элемента, возвращает значение, иначе бросает исключение
	// O(n)
	T succesor(const T& value) {
		if (isEmpty())
			throw std::out_of_range("Дерево пустое");
		TreeNode<T>* nextNode = searchSucc(root, value);
		if (nextNode == nullptr) {
			throw std::out_of_range("Значение не найдено в дереве");
		}
		return nextNode->data;
	}



	// Класс итератора по бинарному дереву поиска
		// Односторонний (вперёд) в инордерном порядке (LNR), не чувствительный к изменениям дерева
	class Iterator {
	private:

		// Служебный рабочий стак
		std::stack<TreeNode<T>*> nodeStack;

		// Узел в данной итерации
		TreeNode<T>* currentNode;

		// Помещает всю левую ветку в стэк
		void pushLeftBranch(TreeNode<T>* node) {
			while (node != nullptr) {
				nodeStack.push(node);
				node = node->left;
			}
		}

	public:

		Iterator(TreeNode<T>* root) {
			// Полностью помещает ссылки на узлы дерева в стэк, N | N | N
			pushLeftBranch(root);
		}

		bool operator!=(const Iterator& other) const {
			return !nodeStack.empty() || !other.nodeStack.empty();
		}

		// Проверяет есть ли ещё узлы в служебном стэке
		bool hasNext() {
			return !nodeStack.empty() || currentNode != nullptr;
		}

		// Оператор возвратит данные узла текущей итерации
		T& operator*() const {
			return currentNode->data;
		}

		// Данные узла текущей итерации
		T& data() {
			return currentNode->data;
		}

		// Переход на следующую итерацию
		Iterator& operator++() {
			return next();
		}

		// Сбрасывает итератор до изначального состояния, обновляя данные N | N | N
		void reset() {
			nodeStack.empty();
			currentNode = root;
			inorderStack(root, nodeStack);
		}

		// Перейти на следующую итерацию
		Iterator& next() {
			TreeNode<T>* currentNode = nodeStack.top();
			if (!hasNext()) {
				throw std::out_of_range("No more elements in the iterator");
			}
			currentNode = nodeStack.top();
			nodeStack.pop();
			pushLeftBranch(currentNode->n_right);
			return *this;
		}

	};

	// Возвращает итератор в начальной позиции
	Iterator begin() {
		return Iterator(root);
	}

	// Возвращает итератор в конечной позиции
	Iterator end() {
		return Iterator(nullptr);
	}



	// Метод для поиска узла по значению
	TreeNode<T>* search(const T& value) const {
		return searchRecursive(root, value); // Запускаем поиск с корневого узла
	}
	// Получить указатель на корень
	TreeNode<T>* get_root() const {
		return root;
	}

	// Функция тестирования
	static void runTests() {
		// Тест для обычного дерева
		Tree<int> normalTree;
		normalTree.insert(10);
		normalTree.insert(5);
		normalTree.insert(15);
		normalTree.insert(2);
		normalTree.insert(7);
		normalTree.insert(12);
		normalTree.insert(20);

		assert(normalTree.countNodes() == 7);
		assert(normalTree.getDepth() == 2);

		normalTree.clear();
		assert(normalTree.countNodes() == 0);
		assert(normalTree.getDepth() == -1);

		// Тест для вырожденного дерева (слева)
		Tree<int> leftSkewedTree;
		leftSkewedTree.insert(10);
		leftSkewedTree.insert(5);
		leftSkewedTree.insert(2);
		assert(leftSkewedTree.countNodes() == 3);
		assert(leftSkewedTree.getDepth() == 2);

		leftSkewedTree.clear();
		assert(leftSkewedTree.countNodes() == 0);
		assert(leftSkewedTree.getDepth() == -1);

		// Тест для вырожденного дерева (справа)
		Tree<int> rightSkewedTree;
		rightSkewedTree.insert(10);
		rightSkewedTree.insert(15);
		rightSkewedTree.insert(20);

		assert(rightSkewedTree.countNodes() == 3);
		assert(rightSkewedTree.getDepth() == 2);

		rightSkewedTree.clear();
		assert(rightSkewedTree.countNodes() == 0);
		assert(rightSkewedTree.getDepth() == -1);

		// Тест для пустого дерева
		Tree<int> emptyTree;
		assert(emptyTree.countNodes() == 0);
		assert(emptyTree.getDepth() == -1);

		emptyTree.clear();
		assert(emptyTree.countNodes() == 0);
		assert(emptyTree.getDepth() == -1);

		// Тест для дерева из одного узла
		Tree<int> singleNodeTree;
		singleNodeTree.insert(10);
		assert(singleNodeTree.countNodes() == 1);
		assert(singleNodeTree.getDepth() == 0);

		singleNodeTree.clear();
		assert(singleNodeTree.countNodes() == 0);
		assert(singleNodeTree.getDepth() == -1);

		// Тест для создания массива на основе обхода
		Tree<int> arrayTree;
		arrayTree.insert(10);
		arrayTree.insert(5);
		arrayTree.insert(15);
		arrayTree.insert(2);
		arrayTree.insert(7);
		arrayTree.insert(12);
		arrayTree.insert(20);

		


		// Тест для дерева с одним узлом
		singleNodeTree.insert(10);
		singleNodeTree.clear();
		cout << "Тесты пройдены" << endl;
	}

};









///  ФУНКЦИИ  ///



///  обходы  ///


/// <summary>
/// traverse function printed tree by Left-Right-Node method
/// O(n)
/// </summary>
template <typename T>
void LRN(TreeNode<T>* headNode)
{
	if (headNode != nullptr)
	{
		LRN<T>(headNode->left);
		LRN<T>(headNode->right);
		std::cout << headNode->data;
	}
}

/// <summary>
/// traverse function printed tree by Left-Node-Right method
/// O(n)
/// </summary>
template <typename T>
void LNR(TreeNode<T>* headNode)
{
	if (headNode != nullptr)
	{
		LNR<T>(headNode->left);
		std::cout << headNode->data;
		LNR<T>(headNode->right);
	}
}

/// <summary>
/// traverse function printed tree by Node-Left-Right method
/// O(n)
/// </summary>
template <typename T>
void NLR(TreeNode<T>* headNode)
{
	if (headNode != nullptr)
	{
		std::cout << headNode->data;
		NLR<T>(headNode->left);
		NLR<T>(headNode->right);
	}
}



/// <summary>
/// traverse function printed tree by Node-Left-Right method
/// O(n)
/// </summary>
template <typename T>
void toVecNRL(TreeNode<T>* headNode, vector<T>& result)
{

	if (headNode != nullptr)
	{
		result.push_back(headNode->data);
		toVecNRL<T>(headNode->right, result);
		toVecNRL<T>(headNode->left, result);
	}
}

/// <summary>
/// traverse function printed tree by Node-Left-Right method
/// O(n)
/// </summary>
template <typename T>
void toVecRNL(TreeNode<T>* headNode, vector<T>& result)
{

	if (headNode != nullptr)
	{
		toVecRNL<T>(headNode->right, result);
		result.push_back(headNode->data);
		toVecRNL<T>(headNode->left, result);
	}
}

/// <summary>
/// traverse function printed tree by Node-Left-Right method
/// O(n)
/// </summary>
template <typename T>
void toVecRLN(TreeNode<T>* headNode, vector<T>& result)
{

	if (headNode != nullptr)
	{
		toVecRLN<T>(headNode->right, result);
		toVecRLN<T>(headNode->left, result);
		result.push_back(headNode->data);
	}
}





















/// КОЛ-ВО УЗЛОВ, ГЛУБИНА, УДАЛЕНИЕ, ПОИСК, КОПИРОВАНИЕ///



/// <summary>
/// count quantity of elements 
/// O(n)
/// returned uantity of elements 
/// </summary>
template <typename T>
size_t count(TreeNode<T>* headNode)
{
	if (headNode == nullptr)
		return 0;
	else return count(headNode->left) + count(headNode->right) + 1;
}









/// Рекурсивная функция определения глубины (инордерный обход - NLR)
/// O(n)
/// 
/// returned depth of tree
template<typename T>
int depth(const TreeNode<T>* node) {
	if (node == nullptr) return -1;
	int leftDepth = depth(node->left);
	int rightDepth = depth(node->right);
	return 1 + max(leftDepth, rightDepth);
}









/// uses LRN traverse for delete each node
/// O(n)
template <typename T>
void deleteTree(TreeNode<T>* headNode)
{
	if (headNode != nullptr)
	{
		deleteTree(headNode->left);
		headNode->left = nullptr;
		deleteTree(headNode->right);
		headNode->right = nullptr;
		delete headNode;
	}
}









template<typename T>
/// Вспомогательный метод для рекурсивного поиска узла (node.data = value) в BST (с корнем node)
/// лучший, средний - O (log(n)), худший - O (n) нелинейный 
TreeNode<T>* searchRecursive(TreeNode<T>* node, const T& value) {
	if (node == nullptr) {
		return nullptr; // Значение не найдено
	}

	if (node->data == value) {
		return node; // Значение найдено, возвращаем узел
	}
	else if (value < node->data) {
		return searchRecursive(node->left, value); // Ищем в левом поддереве
	}
	else {
		return searchRecursive(node->right, value); // Ищем в правом поддереве
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="toCopy"></param>
/// <returns></returns>
template <typename T>
TreeNode<T>* copyTree(TreeNode<T>* toCopy)
{
	if (toCopy != nullptr)
	{
		TreeNode<T>* newTree = new TreeNode<T>;
		newTree->data = toCopy->data;
		newTree->left = copyTree(toCopy->left);
		newTree->right = copyTree(toCopy->right);
		return newTree;
	}
	else return nullptr;
}






template <typename T>
// Проверка на пустоту дерева, 1 если пустое
bool isEmpty(TreeNode<T>* root)
{
	if (root == nullptr)
		return true;
	else
		return false;
}







template<typename T>
// Поиск следующего наибольшего элемента, возвращает узел, иначе нуллптр
TreeNode<T>* searchSucc(TreeNode<T>* current, const T& value) {
	TreeNode<T>* prev = nullptr;

	// Найдем узел с заданным значением и сохраним путь в стек (prev)
	while (current != nullptr) {
		if (current->data == value) {
			break;
		}
		else if (value < current->data) {
			prev = current;
			current = current->left;
		}
		else {
			prev = current;
			current = current->right;
		}
	}
	if (current == nullptr) {
		return nullptr; // Значение не найдено
	}
	// Если у текущего узла есть правый потомок, то следующий наибольший элемент - это наименьший элемент в правом поддереве
	if (current->right != nullptr) {
		current = current->right;
		while (current->left != nullptr) {
			current = current->left;
		}
		return current;
	}
	// Иначе ищем следующий наибольший элемент, поднимаясь вверх по дереву
	if (prev)
		return prev;
	else
		return nullptr;
}








template <typename T>
// Поиск следующего наибольшего элемента, возвращает значение, иначе бросает исключение
T succesor(TreeNode<T>* root, const T& value) {
	if (isEmpty(TreeNode<T>*root))
		throw std::out_of_range("Дерево пустое");
	TreeNode<T>* nextNode = searchSucc(root, value);
	if (nextNode == nullptr) {
		throw std::out_of_range("Значение не найдено в дереве");
	}
	return nextNode->data;
}








template <typename T>
// Удаление узла рекурсивно.
void deleteNodeRecursive(TreeNode<T>** node, const T& value) 
{

	if (*node == nullptr) {
		return; // Узел не найден
	}

	// Если значение меньше, чем значение в текущем узле, идем влево
	if (value < (*node)->data) {
		deleteNodeRecursive(&(*node)->left, value);
	}
	// Если значение больше, чем значение в текущем узле, идем вправо
	else if (value > (*node)->data) {
		deleteNodeRecursive(&(*node)->right, value);
	}
	// Найден узел для удаления
	else {
		TreeNode<T>* nodeToDelete = *node;

		// Если у узла нет дочерних узлов, просто удаляем его
		if ((*node)->left == nullptr && (*node)->right == nullptr) {
			*node = nullptr;
			delete nodeToDelete;
		}
		// Если у узла есть только левый дочерний узел, присоединяем его к родителю
		else if ((*node)->left != nullptr && (*node)->right == nullptr) {
			*node = (*node)->left;
			nodeToDelete->left = nullptr;
			delete nodeToDelete;
		}
		// Если у узла есть только правый дочерний узел, присоединяем его к родителю
		else if ((*node)->left == nullptr && (*node)->right != nullptr) {
			*node = (*node)->right;
			nodeToDelete->right = nullptr;
			delete nodeToDelete;
		}
		// Если у узла есть оба дочерних узла, ищем следующий наибольший элемент и меняем местами
		else {
			TreeNode<T>* nextLargest = searchSucc(*node, (*node)->data);
			(*node)->data = nextLargest->data;
			deleteNodeRecursive(&(*node)->right, nextLargest->data);
		}
	}
}









// A utility function to insert a new node with 
// insert new node to the BST
// the given key
template <typename T>
TreeNode<T>* insert(TreeNode<T>* node, T key) {

	// If the tree is empty, return a new node
	if (node == NULL)
		return new TreeNode<T>(key);

	// If the key is already present in the tree,
	// return the node
	if (node->data == key)
		return node;

	// Otherwise, recur down the tree/ If the key
	// to be inserted is greater than the node's key,
	// insert it in the right subtree
	if (node->data < key)
		node->right = insert(node->right, key);

	// If the key to be inserted is smaller than 
	// the node's key,insert it in the left subtree
	else
		node->left = insert(node->left, key);

	// Return the (unchanged) node pointer
	return node;
}










/// APPLY ///




template<typename T>
/// Препорядковое применение функции NRL
/// O(n)
void applyPreorder(TreeNode<T>* node, const function<void(T&)>& func) {
	if (node == nullptr) return;
	func(node->data);
	applyPreorder(node->right, func);
	applyPreorder(node->left, func);
}

template<typename T>
/// Инордерное применение функции RNL
/// O(n)
void applyInorder(TreeNode<T>* node, const function<void(T&)>& func) {
	if (node == nullptr) return;
	applyInorder(node->right, func);
	func(node->data);
	applyInorder(node->left, func);
}

template<typename T>
/// Постпорядковое применение функции RLN
/// O(n)
void applyPostorder(TreeNode<T>* node, const function<void(T&)>& func) {
	if (node == nullptr) return;
	applyPostorder(node->right, func);
	applyPostorder(node->left, func);
	func(node->data);
}











/// TESTS


/// <summary>
/// test func for other functions cheking
/// pt. 1
/// COUNT
/// DEPTH
/// APPLY
/// TO VECTOR
/// COPY
/// ОБХОДЫ
/// </summary>
void TreeNodeTests1()
{
	/// handmade tree for tests
	TreeNode<int>* A0 = new TreeNode<int>(0);
	TreeNode<int>* A1 = new TreeNode<int>(1);
	TreeNode<int>* A2 = new TreeNode<int>(2);
	TreeNode<int>* A3 = new TreeNode<int>(3);
	TreeNode<int>* A4 = new TreeNode<int>(4);
	TreeNode<int>* A5 = nullptr;
	TreeNode<int>* A6 = nullptr;

	A0->left = A1;
	A0->right = A2;
	A1->left = A3;
	A2->left = A4;

	/// count func tests
	assert(count(A0) == 5);
	assert(count(A1) == 2);
	assert(count(A4) == 1);
	assert(count(A5) == 0);



	/// depth func tests
	assert(depth(A0) == 2);
	assert(depth(A1) == 1);
	assert(depth(A4) == 0);
	assert(depth(A5) == -1);






	/// applyPreorder func tests
	applyPreorder<int>(A0, [](int& data) {data = data+1;});
	assert(A0->data == 1);
	assert(A1->data == 2);
	assert(A2->data == 3);
	assert(A3->data == 4);
	assert(A4->data == 5);
	
	
	
	
	/// applyInorder func tests
	applyInorder<int>(A0, [](int& data) {data = data+1;});
	assert(A0->data == 2);
	assert(A1->data == 3);
	assert(A2->data == 4);
	assert(A3->data == 5);
	assert(A4->data == 6);
	
	

	/// applyPostorder func tests
	applyPostorder<int>(A0, [](int& data) {data = data-2;});
	assert(A0->data == 0);
	assert(A1->data == 1);
	assert(A2->data == 2);
	assert(A3->data == 3);
	assert(A4->data == 4);




	/// to vector funcs tests
	vector<int> vec;
	vector<int> vec1;


	/// NRL
	toVecNRL(A0, vec);
	assert(vec[0] == 0);
	assert(vec[1] == 2);
	assert(vec[2] == 4);
	assert(vec[3] == 1);
	assert(vec[4] == 3);
	
	vec.clear();
	
	
	/// RNL
	toVecRNL(A0, vec);
	assert(vec[0] == 2);
	assert(vec[1] == 4);
	assert(vec[2] == 0);
	assert(vec[3] == 1);
	assert(vec[4] == 3);
	


	vec.clear();

	
	/// RLN
 	toVecRLN(A0, vec);
	assert(vec[0] == 4);
	assert(vec[1] == 2);
	assert(vec[2] == 3);
	assert(vec[3] == 1);
	assert(vec[4] == 0);
	

	vec.clear();

	/// copyTree func tests

	// пустой узел
	A6 = copyTree<int>(A5);
	assert(A6 == nullptr);

	// заполненное дерево
	A6 = copyTree<int>(A0);
	toVecNRL(A0, vec);
	toVecNRL(A6, vec1);
	assert(vec1 == vec);

	// проверка, что удаление копируемого не влияет на новый
	vec.clear();
	vec1.clear();
	deleteTree(A0);
	A0 = nullptr;
	toVecNRL(A6, vec1);
	assert(vec1[0] == 0);
	assert(vec1[1] == 2);
	assert(vec1[2] == 4);
	assert(vec1[3] == 1);
	assert(vec1[4] == 3);



	/// applyPreorder func tests
	/*applyPostorder<int>(A0, [](int& data) {data = 0; });
	assert(A0->data == 0);
	assert(A1->data == 0);
	assert(A2->data == 0);
	assert(A3->data == 0);
	assert(A4->data == 0);*/


	

	
}






/// <summary>
/// test func for other functions cheking
/// pt. 1
/// INSERT
/// SUCCCESSOR
/// REMOVE
/// IS EMPTY
/// </summary>
void TreeNodeTests2()
{
	// create nodes for tests
	TreeNode<int>* A0 = new TreeNode<int>(3);
	// an empty node
	TreeNode<int>* A1 = nullptr;

	// insert tests
	insert(A0, 0);
	insert(A0, 2);
	insert(A0, 1);
	insert(A0, 4);
	//double insert for checking
	insert(A0, 4);

	// check inserts
	assert(A0->data == 3);
	assert(A0->left->data == 0);
	assert(A0->right->data == 4);
	assert(A0->left->right->data == 2);
	assert(A0->left->right->left->data == 1);

	// isEmpty tests
	assert(isEmpty(A0)==false);
	assert(isEmpty(A1)==true);




}