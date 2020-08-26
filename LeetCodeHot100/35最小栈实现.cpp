/*
* ʵ����Сջ���ܣ�push, pop, top, getMin
*/

/*
* ����1��vector����
*/
class MinStack {
    vector<int> vec;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        vec.push_back(x);
    }

    void pop() {
        vec.erase(vec.end() - 1);
    }

    int top() {
        return vec.back();
    }

    int getMin() {
        int minVal = INT_MAX;
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] < minVal)
                minVal = vec[i];
        }
        return minVal;
    }
};


/*
* ����2��stack����
*/
class MinStack {
    stack<int> stk, minStk;
public:
    /** initialize your data structure here. */
    MinStack() {
        minStk.push(INT_MAX);
    }

    void push(int x) {
        stk.push(x);
        minStk.push(min(minStk.top(), x));
    }

    void pop() {
        stk.pop();
        minStk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
};