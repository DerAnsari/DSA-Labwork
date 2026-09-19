#include <iostream>
#include <set>

using std::cout, std::set;

class ExamRoom {
private:
  int n_;
  set<int> occupied_;

public:
  ExamRoom(int n) : n_(n) {}

  int seat() {
    int prevPosition{0}, prevDistance{0}, lastSeat{-1};
    if (occupied_.empty()) {
      occupied_.insert(0);
      return 0;
    }

    for (int i{0}; i < n_; i++) {
      if (occupied_.count(i)) {

        int distance, position;
        // in case of it being our first time like the first run
        if (lastSeat == -1) {
          distance = i;
          position = 0;
        } else {
          distance = (i - lastSeat) / 2;
          position = lastSeat + distance;
        }

        if (distance > prevDistance) {
          prevDistance = distance;
          prevPosition = position;
        }

        lastSeat = i;
      }
    }

    if (n_ - 1 - lastSeat > prevDistance)
      prevPosition = n_ - 1;

    occupied_.insert(prevPosition);
    return prevPosition;
  }

  void leave(int p) { occupied_.erase(p); }
};

int main() {
  ExamRoom examRoom(10);
  cout << examRoom.seat() << "\n"; // expected: 0
  cout << examRoom.seat() << "\n"; // expected: 9
  cout << examRoom.seat() << "\n"; // expected: 4
  cout << examRoom.seat() << "\n"; // expected: 2
  examRoom.leave(4);
  cout << examRoom.seat() << "\n"; // expected: 5
}
