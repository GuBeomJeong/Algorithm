# All O`one Data Structure
자료구조 구현하는 문제.   
쉽게 생각했지만 생각보다 구현이 까다로웠다. stl로 하려다보니 iterator를 써야하는데 제한이 있어서 직접 구현하는 방식으로 다시 진행했다.    
key를 hashMap으로 저장하고, 각 값들을 hashMap에 List로 저장하였다.   
즉 nums[1] = 1 의 key 리스트, nums[2] = 2의 key 리스트 ...   
또한 values는 nums 의 list이다.    
values 의 노드들은 list[1], list[2] ...이다. values의 head가 최소, values의 tail이 최대값이 된다.

``` c++
class AllOne {
public:

	class Node {
	public:
		int value;
		string key;
		Node* next;
		Node* prev;

		Node(string _key, int _value) {
			key = _key;
			value = _value;
			next = 0;
			prev = 0;
		}
	};

	template <typename T>
	class List {
	public:
		T head;
		T tail;
		int size;
		List<T>* next;
		List<T>* prev;

		List() {
			head = 0;
			tail = 0;
			next = 0;
			prev = 0;
			size = 0;
		}

		void push_back(T node) {

			if (size == 0) {
				head = node;
				tail = node;
				size++;
				return;
			}

			if (tail) {
				tail->next = node;
			}
			node->prev = tail;
			tail = node;

			size++;
		}

		void push_front(T node) {

			if (size == 0) {
				head = node;
				tail = node;
				size++;
				return;
			}

			if (head) {
				head->prev = node;
			}
			node->next = head;
			head = node;

			size++;

		}

		void insert_front(T node, T newNode) {

			newNode->prev = node->prev;
			newNode->next = node;

			if (node->prev) {
				node->prev->next = newNode;
				
			}
			else {
				head = newNode;
			}
			node->prev = newNode;
			size++;
		}

		void insert_back(T node, T newNode) {

			newNode->next = node->next;
			newNode->prev = node;

			if (node->next) {
				node->next->prev = newNode;
			}
			else {
				tail = newNode;
			}
			node->next = newNode;
			size++;
		}

		void remove(T node) {
			if (node->prev) {
				node->prev->next = node->next;
			}
			else {
				head = node->next;
			}

			if (node->next) {
				node->next->prev = node->prev;
			}
			else {
				tail = node->prev;
			}

			node->prev = 0;
			node->next = 0;

			size--;
		}
	};

	unordered_map<string, Node*> datas;
	unordered_map<int, List<Node*>*> nums;
	List<List<Node*>*> values;

	/** Initialize your data structure here. */
	AllOne() {
		values = List<List<Node*>*>();
	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {

		Node* node;
		List<Node*>* list;
		List<Node*>* nextList;

		if (datas.count(key)) {
			node = datas[key];
			list = nums[node->value];
			nextList = nums[node->value + 1];
			node->value++;

			list->remove(node);

			if (nextList == 0) {
				nextList = new List<Node*>();
				nums[node->value] = nextList;
				values.insert_back(list, nextList);
			}

			if (list->size == 0) {
				nums.erase(node->value - 1);
				values.remove(list);
			}

			nextList->push_back(node);

		}
		else {
			node = new Node(key, 1);
			datas[key] = node;

			list = nums[1];
			if (list == 0) {
				list = new List<Node*>();
				nums[1] = list;
				values.push_front(list);
			}
			list->push_back(node);
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		Node* node;
		List<Node*>* list;
		List<Node*>* nextList;

		if (datas.count(key)) {
			node = datas[key];
			list = nums[node->value];
			nextList = nums[node->value - 1];
			node->value--;

			list->remove(node);

			if (node->value == 0) {
				datas.erase(key);
				if (list->size == 0) {
					nums.erase(node->value + 1);
					values.remove(list);
				}
				return;
			}

			if (nextList == 0) {
				nextList = new List<Node*>();
				nums[node->value] = nextList;
				values.insert_front(list, nextList);
			}

			if (list->size == 0) {
				nums.erase(node->value + 1);
				values.remove(list);
			}

			nextList->push_back(node);

		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (values.size == 0) {
			return "";
		}

		cout << values.head->head->key << endl;

		List<Node*>* list = values.tail;
		return list->head->key;
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (values.size == 0) {
			return "";
		}
		return values.head->head->key;
	}
};
```
> Runtime: 44 ms, faster than 94.36% of C++ online submissions for All O`one Data Structure.
Memory Usage: 24.9 MB, less than 100.00% of C++ online submissions for All O`one Data Structure.
Next challenges:
