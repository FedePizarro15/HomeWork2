#include "student.h"
#include "course.h"
#include <iostream>

using namespace std;

Student::Student(string _name, unsigned int _id) {
    name = _name;
    courses = {};
    id = _id;
};

Student::Student(string _name, vector<pair<shared_ptr<Course>, float>> _courses, unsigned int _id) {
    name = _name;
    courses = _courses;
    id = _id;
};

void Student::courseInscribe(Course& course, float grade) {
    pair<shared_ptr<Course>, float> coursePair = {make_shared<Course>(course), grade};
    courses.push_back(coursePair);
    //??: ¿Debo añadir una relación de vuelta que asegura inscribir en el curso?
};

void Student::courseDesinscribe(Course course) {
    for (unsigned int i = 0; i < courses.size(); i++) {
        if (*courses[i].first == course) {
            courses.erase(courses.begin() + i);
            return;
        };
    };

    cout << "El estudiante no está inscripto en el curso '" << course.getName() << "'.";
};

void Student::setGrade(Course course, float grade) {
    for (unsigned int i = 0; i < courses.size(); i++) {
        if (*courses[i].first == course) {
            courses[i].second = grade;
            return;
        };
    };

    cout << "El estudiante no está inscripto en el curso '" << course.getName() << "'.";
};

string Student::getName() const {
    return name;
};

unsigned int Student::getID() const {
    return id;
};

vector<Course> Student::getCourses() {
    vector<Course> _courses;

    for (unsigned int i = 0; i < courses.size(); i++) {
        _courses.push_back(*courses[i].first);
    };

    return _courses;
};

float Student::getAverage() {
    float gradesSum, average;

    for (unsigned int i = 0; i < courses.size(); i++) {
        gradesSum += courses[i].second;
    };

    average = gradesSum / courses.size();

    return average;
};

bool Student::operator == (Student& student) const {return (id == student.id ? true : false);}

bool Student::operator << (Student& student) const {return (name <= student.name ? true : false);}