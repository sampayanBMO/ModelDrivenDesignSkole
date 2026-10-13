#include "lab_booking/admin.hpp"
#include "lab_booking/booking.hpp"
#include "lab_booking/equipment.hpp"
#include "lab_booking/student.hpp"

#include <chrono>

namespace {

void scenario(lab_booking::Student& student, lab_booking::Admin& admin,
              lab_booking::Booking& booking, lab_booking::Equipment& equipment)
{
    using Clock = std::chrono::system_clock;
    const auto start = Clock::time_point(Clock::duration(0));
    const auto end = start + std::chrono::hours(1);

    student.requestBooking(booking, equipment, start, end);
    admin.approveBooking(booking, student);
    admin.rejectBooking(booking, student);
    admin.notifyStudent(student, "decision");
    student.cancelBooking(booking, equipment);
    student.viewBookings();
    booking.startBooking();
    booking.endBooking();
}

}  // namespace

int main()
{
    lab_booking::Student student(1, 10, "Student");
    lab_booking::Admin admin(2, 10, "Admin");
    lab_booking::Booking booking(4);
    lab_booking::Equipment equipment(3, "Oscilloscope");
    scenario(student, admin, booking, equipment);
    return 0;
}
