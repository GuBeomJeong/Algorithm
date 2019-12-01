# LFU Cache
All O`one Data Structure 과 거의 비슷한 문제이다.

``` c++
class LFUCache {
public:
    
    class Node {
	public:
		int value;
        int freq;
		int key;
        
		Node* next;
		Node* prev;

		Node(int _key, int _value) {
			key = _key;
			value = _value;
			next = 0;
			prev = 0;
            freq = 1;
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
    
    unordered_map<int,Node*> datas;
    unordered_map<int,List<Node*>*> freq;
    List<List<Node*>*> freqList;
    int cap,size;
    
    LFUCache(int capacity) {
        size = 0;
        cap = capacity;
        freqList = List<List<Node*>*>();
    }
    
    void increase(Node* node){
        List<Node*>* list;
        List<Node*>* nextList;

        list = freq[node->freq];
        nextList = freq[node->freq + 1];
        list->remove(node);

        if(nextList == 0){
            nextList = new List<Node*>();
            freq[node->freq+1] = nextList;
            freqList.insert_back(list, nextList);
        }
        
        if(list->size == 0){
            freq.erase(node->freq);
            freqList.remove(list);
        }

        node->freq++;
        nextList->push_back(node);
    }
    
    int get(int key) {
        
        if(cap == 0){
            return -1;
        }
        
        if(datas.count(key)){
            Node* node = datas[key];
            
            increase(node);
            
            return node->value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        Node* node;
        List<Node*>* list;
        
        if(cap == 0){
            return;
        }
        
        if(datas.count(key)){
            
            node = datas[key];
            node->value = value;
            increase(node);
            
            return;
        }else{
            if(size >= cap){
                list = freqList.head;
                node = list->head;

                list->remove(node);

                if(list->size==0){
                    freq.erase(node->freq);
                    freqList.remove(list);
                }
                
                datas.erase(node->key);
            }
            node = new Node(key, value);
            datas[key] = node;

	    list = freq[1];
            
   	    if (list == 0) {
		list = new List<Node*>();
		freq[1] = list;
		freqList.push_front(list);
	    }
	    list->push_back(node);
            size++;
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 ```
 
 > Runtime: 104 ms, faster than 97.06% of C++ online submissions for LFU Cache.
Memory Usage: 38.3 MB, less than 81.82% of C++ online submissions for LFU Cache.
Next challenges:
