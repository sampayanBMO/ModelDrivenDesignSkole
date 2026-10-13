#pragma once

#include "lab_booking/user.hpp"

#include <chrono>
#include <vector>

namespace lab_booking {

class Booking;
class Equipment;

class Student : public User
{
public:
    using TimePoint = std::chrono::system_clock::time_point;

    Student(int id, int departmentId, std::string name);

    void requestBooking(Booking& booking, Equipment& equipment,
                        TimePoint startDate, TimePoint endDate);
    void cancelBooking(Booking& booking, Equipment& equipment);
    std::vector<Booking*> viewBookings() const;

private:
    std::vector<Booking*> requests_;
};

}  // namespace lab_booking
