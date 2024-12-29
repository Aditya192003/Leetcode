// class MyCalendarTwo {
// public:
//     MyCalendarTwo() {
        
//     }
    
//     bool book(int startTime, int endTime) {
        
//     }
// };

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */

 #include <map>
using namespace std;

class MyCalendarTwo {
public:
    MyCalendarTwo() {
    }
    
    bool book(int startTime, int endTime) {
        bookings[startTime]++;
        bookings[endTime]--;

        int activeBookings = 0;
        for (auto& [time, count] : bookings) {
            activeBookings += count;
            if (activeBookings >= 3) {
                bookings[startTime]--;
                bookings[endTime]++;
                if (bookings[startTime] == 0) bookings.erase(startTime);
                if (bookings[endTime] == 0) bookings.erase(endTime);
                return false;
            }
        }
        return true;
    }

private:
    map<int, int> bookings; 
};
