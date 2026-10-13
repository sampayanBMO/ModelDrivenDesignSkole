#include "lab_booking/student.hpp"

#include "lab_booking/booking.hpp"
#include "lab_booking/equipment.hpp"

#include <stdexcept>
#include <utility>

namespace lab_booking {

Student::Student(int id, int departmentId, std::string name)
    : User(id, departmentId, std::move(name))
{
}

void Student::requestBooking(Booking& booking, Equipment& equipment,
                             TimePoint startDate, TimePoint endDate)
{
    if (startDate >= endDate) {
        throw std::invalid_argument("booking end must be after booking start");
    }
    for (const Booking* existing : equipment.booked_in_) {
        if (existing == &booking) {
            throw std::logic_error("booking has already been requested");
        }
    }

    requests_.push_back(&booking);
    equipment.booked_in_.push_back(&booking);
}

void Student::cancelBooking(Booking& booking, Equipment& equipment)
{
    booking.handle(Booking::Event::cancelBooking);
    if (equipment.whichBooking == &booking) {
        equipment.endBooking();
    }
}

std::vector<Booking*> Student::viewBookings() const
{
    return requests_;
}

}  // namespace lab_booking
