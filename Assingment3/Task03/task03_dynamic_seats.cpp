#include <iostream>
using namespace std;

class Auditorium {
    int rows, seatsPerRow;
    bool** seats;
    int booked;

public:
    Auditorium(int r, int s)
        : rows(r < 0 ? 0 : r), seatsPerRow(s < 0 ? 0 : s),
          seats(nullptr), booked(0) {
        if (rows > 0 && seatsPerRow > 0) {
            seats = new bool*[rows];
            for (int i = 0; i < rows; ++i) {
                seats[i] = new bool[seatsPerRow]{};
            }
        }
        cout << "Auditorium opened: " << rows << " rows x "
             << seatsPerRow << " seats\n";
    }

    bool book(int r, int s) {
        if (!valid(r, s) || seats[r][s]) return false;
        seats[r][s] = true;
        ++booked;
        return true;
    }

    bool cancel(int r, int s) {
        if (!valid(r, s) || !seats[r][s]) return false;
        seats[r][s] = false;
        --booked;
        return true;
    }

    bool valid(int r, int s) const {
        return seats && r >= 0 && r < rows && s >= 0 && s < seatsPerRow;
    }

    ~Auditorium() {
        if (seats) {
            for (int i = 0; i < rows; ++i) delete[] seats[i];
            delete[] seats;
        }
        cout << "Auditorium closed. Final booked seats: " << booked << '\n';
    }
};

int main() {
    cout << "Stack object:\n";
    Auditorium hall(2, 3);
    cout << "Book seat (0,1): " << boolalpha << hall.book(0, 1) << '\n';
    cout << "Cancel seat (0,1): " << hall.cancel(0, 1) << '\n';

    cout << "Heap object:\n";
    Auditorium* event = new Auditorium(1, 2);
    event->book(0, 0);
    delete event;

    cout << "Block-scope object:\n";
    {
        Auditorium temporary(1, 1);
        temporary.book(0, 0);
    }

    cout << "Zero-row object:\n";
    Auditorium empty(0, 5);
}
