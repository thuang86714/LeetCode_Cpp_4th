#include <unordered_map>>
#include <vector>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val) != map.end()){
            return false;
        }
        nums.push_back(val);
        map[val] = nums.size() -1;
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val) == map.end()){
            return false;
        }
        int n = nums.size();
        int back = nums.back();
        swap(nums[map[val]], nums[n - 1]);
        nums.pop_back();
        map[back] = map[val];
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = nums.size();
        return nums[rand()%n];
    }
private:
    vector<int> nums;
    unordered_map<int, int> map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */