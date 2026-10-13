#pragma once

#include "lab_booking/user.hpp"

#include <string>
#include <vector>

namespace lab_booking {

class Booking;
class Student;

class Admin : public User
{
public:
    Admin(int id, int departmentId, std::string name);

    void approveBooking(Booking& booking, Student& student);
    void rejectBooking(Booking& booking, Student& student);
    void notifyStudent(Student& student, const std::string& decision);

private:
    std::vector<Booking*> reviews_;
};

}  // namespace lab_booking
