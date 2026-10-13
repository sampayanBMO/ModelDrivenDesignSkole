#include "lab_booking/equipment.hpp"

#include "lab_booking/booking.hpp"

#include <stdexcept>
#include <utility>

namespace lab_booking {

Equipment::Equipment(int equipmentId, std::string name)
    : equipmentId(equipmentId), name(std::move(name))
{
}

void Equipment::startBooking(Booking& booking,
                             std::chrono::system_clock::time_point bookingStart,
                             std::chrono::system_clock::time_point bookingEnd)
{
    if (bookingStart >= bookingEnd) {
        throw std::invalid_argument("booking end must be after booking start");
    }
    if (inUse) {
        throw std::logic_error("equipment is already in use");
    }

    inUse = true;
    whichBooking = &booking;
    startDate = bookingStart;
    endDate = bookingEnd;
    booked_in_.push_back(&booking);
    booking.startBooking();
}

void Equipment::endBooking()
{
    if (!inUse || whichBooking == nullptr) {
        return;
    }

    whichBooking->endBooking();
    inUse = false;
    whichBooking = nullptr;
}

}  // namespace lab_booking
