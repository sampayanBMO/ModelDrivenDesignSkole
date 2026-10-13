#pragma once

#include <chrono>
#include <string>
#include <vector>

namespace lab_booking {

class Booking;

class Equipment
{
public:
    int equipmentId;
    std::string name;
    bool inUse = false;
    Booking* whichBooking = nullptr;
    std::chrono::system_clock::time_point startDate;
    std::chrono::system_clock::time_point endDate;
    std::vector<Booking*> booked_in_;

    Equipment(int equipmentId, std::string name);

    void startBooking(Booking& booking,
                      std::chrono::system_clock::time_point startDate,
                      std::chrono::system_clock::time_point endDate);
    void endBooking();

private:
    friend class Student;

    struct Reservation
    {
        Booking* booking;
        std::chrono::system_clock::time_point start;
        std::chrono::system_clock::time_point end;
    };

    std::vector<Reservation> reservations_;
};

}  // namespace lab_booking
