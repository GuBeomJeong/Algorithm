# 풀이
data(HashMap<int,vector<int>>) : val 은 진짜 리스트에서 val의 idx 리스트를 가지고 있음       
key: val   
value : nums 의 idx 리스트   
nums (vector<pair<int,int>>) : 진짜 리스트   
first : val 값    
second : hashMap의 자신의 val의 index를 가지고 있음   
만약 삭제 연산이 있다면 진짜 리스트의 마지막 값을 삭제할 val의 마지막 idx 위치로 바꿔치기 한다.   
그 후에 nums의 마지막과 맵[val]의 마지막 값을 삭제한다.    
```c++
class RandomizedCollection {
public:
    
    unordered_map<int,vector<int>> data;
    vector<pair<int,int>> nums;
    
    
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool result = data.find(val) == data.end();
        
        data[val].push_back(nums.size());
        nums.push_back({val,data[val].size() - 1});
        
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool result = data.find(val) != data.end();
        
        if(result){
            pair<int,int> last = nums.back();
            data[last.first][last.second] = data[val].back();
            nums[data[val].back()] = last;
            nums.pop_back();
            data[val].pop_back();
            if(data[val].empty()){
                data.erase(val);
            }
        }
        return result;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```