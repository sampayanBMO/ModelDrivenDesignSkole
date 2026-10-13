#pragma once

#include <string>

namespace lab_booking {

class User
{
public:
    int id;
    int departmentId;
    std::string name;

    User(int id, int departmentId, std::string name);
    virtual ~User() = default;
};

}  // namespace lab_booking
