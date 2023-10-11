#include "Single_Linked_List.h"
#include "Employee.h"
#include <iostream>

int main() {
    // Testing Single_Linked_List
    Single_Linked_List<int> list;

    // Initial operations
    list.push_front(1);
    list.push_back(3);
    list.insert(1, 2); // This should insert "2" between "1" and "3"
    std::cout << "Front of list after inserts: " << list.front() << std::endl;
    std::cout << "Back of list after inserts: " << list.back() << std::endl;

    // Testing find
    size_t position = list.find(2);
    if (position != list.size()) {
        std::cout << "Found '2' at position: " << position << std::endl;
    }
    else {
        std::cout << "'2' not found in the list." << std::endl;
    }

    // Testing remove
    list.remove(1); // Remove the element "2"
    std::cout << "Front of list after remove: " << list.front() << std::endl;
    std::cout << "Back of list after remove: " << list.back() << std::endl;

    // Testing Employee classes
    Professional prof(4000);  // Monthly salary of 4000
    NonProfessional non_prof(20);  // Hourly rate of 20

    std::cout << "Professional weekly salary: " << prof.calculate_weekly_salary(40) << std::endl;
    std::cout << "Professional health care contributions: " << prof.health_care_contributions() << std::endl;
    std::cout << "Professional vacation days for 40 hours: " << prof.vacation_days(40) << std::endl;

    std::cout << "NonProfessional weekly salary for 40 hours: " << non_prof.calculate_weekly_salary(40) << std::endl;
    std::cout << "NonProfessional health care contributions: " << non_prof.health_care_contributions() << std::endl;
    std::cout << "NonProfessional vacation days for 40 hours: " << non_prof.vacation_days(40) << std::endl;

    return 0;
}
