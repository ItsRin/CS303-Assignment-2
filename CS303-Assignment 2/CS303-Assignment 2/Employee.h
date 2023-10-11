#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
public:
    virtual double calculate_weekly_salary(double hours_worked) const = 0;
    virtual double health_care_contributions() const = 0;
    virtual double vacation_days(double hours_worked) const = 0;
};

class Professional : public Employee {
private:
    double monthly_salary;

public:
    Professional(double salary) : monthly_salary(salary) {}

    double calculate_weekly_salary(double hours_worked) const override {
        return monthly_salary / 4; // Assuming 4 weeks in a month.
    }

    double health_care_contributions() const override {
        return 200; // Example value
    }

    double vacation_days(double hours_worked) const override {
        return 1; // Example value
    }
};

class NonProfessional : public Employee {
private:
    double hourly_rate;

public:
    NonProfessional(double rate) : hourly_rate(rate) {}

    double calculate_weekly_salary(double hours_worked) const override {
        return hourly_rate * hours_worked;
    }

    double health_care_contributions() const override {
        return 100; // Example value
    }

    double vacation_days(double hours_worked) const override {
        return hours_worked / 40; // 1 day for every 40 hours worked as an example.
    }
};

#endif
