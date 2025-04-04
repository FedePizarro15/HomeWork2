#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Course;

class Student {
private:
    const string name;
    const unsigned int id; // único
    vector<pair<shared_ptr<Course>, float>> courses;
    
public:
    Student(const unsigned int _id) : name("Alumno"), id(_id), courses({}) {};
    Student(const string _name, const unsigned int _id) : name(_name), id(_id), courses({}) {};

    void courseInscribe(shared_ptr<Course> course, const float grade = 0);
    void courseDesinscribe(shared_ptr<Course> course);

    bool setGrade(const shared_ptr<Course> course, const float grade);

    const string getName() const;
    const unsigned int getID() const;
    const float getAverage() const;
    const float getGrade(shared_ptr<Course> course) const;

    bool operator == (const Student& student) const;
    bool operator < (const Student& student) const;
    friend ostream& operator <<(ostream& os, const Student& student);
};

#endif