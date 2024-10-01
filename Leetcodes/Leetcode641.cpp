class MyCircularDeque {
public:
    deque<int> sona;
    int size;
    MyCircularDeque(int k) {
        size = k;
    }
    bool insertFront(int value) {
        if (sona.size() < size) {
            sona.push_front(value);
            return true;
        }
        return false;
    }
    bool insertLast(int value) {
        if (sona.size() < size) {
            sona.push_back(value);
            return true;
        }
        return false;
    }
    bool deleteFront() {
        if (!sona.empty()) {
            sona.pop_front();
            return true;
        }
        return false;
    }
    bool deleteLast() {
        if (!sona.empty()) {
            sona.pop_back();
            return true;
        }
        return false;
    }
    int getFront() {
        if (sona.empty()) return -1;
        return sona.front();
    }
    int getRear() {
        if (sona.empty()) return -1;
        return sona.back();
    }
    bool isEmpty() {
        return sona.size() == 0;
    }
    bool isFull() {
        return sona.size() == size;
    }
};
