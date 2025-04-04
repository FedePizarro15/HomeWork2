#include "student.h"
#include "course.h"

#include <iostream>

using namespace std;

void Student::courseInscribe(shared_ptr<Course> course, float grade) {courses.push_back(pair{course, grade});}

void Student::courseDesinscribe(shared_ptr<Course> course) {
    for (unsigned int i = 0; i < courses.size(); i++) {
        if (*courses[i].first == *course) {
            courses.erase(courses.begin() + i);
            return;
        };
    };

    cout << "El estudiante no está inscripto en el curso " << *course << "." << endl << endl;
};

bool Student::setGrade(shared_ptr<Course> course, float grade) {
    for (unsigned int i = 0; i < courses.size(); i++) {
        if (*courses[i].first == *course) {
            courses[i].second = grade;
            return true;
        };
    };

    cout << "El estudiante no está inscripto en el curso " << *course << "." << endl << endl;
    return false;
};

const string Student::getName() const {
    return name;
};

const unsigned int Student::getID() const {
    return id;
};

const float Student::getGrade(shared_ptr<Course> course) const {
    for (unsigned int i = 0; i < courses.size(); i++) {
        if (*courses[i].first == *course) {
            return courses[i].second;
        };
    };

    cout << "El estudiante no está inscripto en el curso " << *course << "." << endl << endl;
    return -1.0;
}

const float Student::getAverage() const {
    if (courses.empty()) return 0;
    
    float gradesSum = 0.0;
    unsigned int validCourses = 0;

    for (unsigned int i = 0; i < courses.size(); i++) {
        if (courses[i].second > 0) {
            gradesSum += courses[i].second;
            validCourses++;
        }
    };

    if (validCourses == 0) return 0;
    
    return gradesSum / validCourses;
};

bool Student::operator == (const Student &student) const {return id == student.id;}

bool Student::operator < (const Student &student) const {return name < student.name;}

ostream &operator <<(ostream &os, const Student &student) {
    os << "'" << student.getName() << "' (ID: " << student.getID() << ")";
    return os;
}