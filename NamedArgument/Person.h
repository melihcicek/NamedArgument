#pragma once

#include "NamedType.h"

using FirstName = NamedType<std::string, struct fname>;
using LastName = NamedType<std::string, struct sname>;

using Address = NamedType<std::string, struct addr>;
using LicenseID = NamedType<int, struct lid>;
using CitizenID = NamedType<int, struct cid>;

template<typename ...Args>
class Person {
public:
    Person(Args&& ...args) :
        m_firstname{ pick<FirstName>((args)...) }, 
        m_lastname{ pick<LastName>((args)...) },
        m_address{ pick<Address>((args)...) },
        m_citizen_id {pick<CitizenID>((args)...)},
        m_license_id {pick<LicenseID>((args)...)}
    {}

    friend std::ostream& operator<<(std::ostream& os, const Person& p)
    {
        os << "My name is " << p.m_firstname.get() << ", " << p.m_lastname.get() << '\n';
        os << "Address " << p.m_address.get() << " CID: " << p.m_citizen_id.get() << " LID: " << p.m_license_id.get() << "\n";
        return os;
    }

private:
    template<typename TypeToPick, typename... Types>
    TypeToPick pick(Types&&... args)
    {
        return std::get<TypeToPick>(std::make_tuple(std::forward<Types>(args)...));
    }

    FirstName m_firstname{};
    LastName m_lastname{};
    CitizenID m_citizen_id{};
    Address m_address{};
    LicenseID m_license_id{};
};

