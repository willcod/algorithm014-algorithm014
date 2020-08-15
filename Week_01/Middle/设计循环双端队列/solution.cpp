class MyCircularDeque {
 private:
  vector<int> buffer;
  int _cnt;
  int MAX;
  int _front;
  int _rear;

 public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int k)
      : buffer(k, 0), _cnt(0), MAX(k), _front(k - 1), _rear(0) {}

  /** Adds an item at the front of Deque. Return true if the operation is
   * successful. */
  bool insertFront(int value) {
    if (_cnt == MAX) {
      return false;
    }
    buffer[_front] = value;
    _front = (_front - 1 + MAX) % MAX;
    ++_cnt;

    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is
   * successful. */
  bool insertLast(int value) {
    if (_cnt == MAX) {
      return false;
    }
    buffer[_rear] = value;
    _rear = (_rear + 1) % MAX;
    ++_cnt;

    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is
   * successful. */
  bool deleteFront() {
    if (_cnt == 0) {
      return false;
    }
    _front = (_front + 1) % MAX;
    --_cnt;

    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is
   * successful. */
  bool deleteLast() {
    if (_cnt == 0) {
      return false;
    }
    _rear = (_rear - 1 + MAX) % MAX;
    --_cnt;

    return true;
  }

  /** Get the front item from the deque. */
  int getFront() {
    if (_cnt == 0) {
      return -1;
    }
    return buffer[(_front + 1) % MAX];
  }

  /** Get the last item from the deque. */
  int getRear() {
    if (_cnt == 0) {
      return -1;
    }
    return buffer[(_rear - 1 + MAX) % MAX];
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty() { return _cnt == 0; }

  /** Checks whether the circular deque is full or not. */
  bool isFull() { return _cnt == MAX; }
};