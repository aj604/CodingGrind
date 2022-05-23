#include <vector>
#include <stack>
using namespace std;

/* Bare minimum solution using vector
class MinStack {
private:
  vector<int> data;
public:
    MinStack() {}
    
    void push(int val) {
        data.insert(data.begin(), val);
    }
    
    void pop() {
        data.erase(data.begin(),data.begin()+1);
    }
    
    int top() {
        return data.front();
    }
    
    int getMin() {
      int min = data.front();
      for(int ii = 1; ii < data.size(); ii++){
        if(data[ii] < min) min = data[ii];
      }
      return min;
    }
};
*/
class MinStack {
private:
  stack<int> data;
public:
    MinStack() {}
    
    void push(int val) {
        data.insert(data.begin(), val);
    }
    
    void pop() {
        data.erase(data.begin(),data.begin()+1);
    }
    
    int top() {
        return data.front();
    }
    
    int getMin() {
      int min = data.front();
      for(int ii = 1; ii < data.size(); ii++){
        if(data[ii] < min) min = data[ii];
      }
      return min;
    }
};