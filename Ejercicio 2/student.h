#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Course;

class Student {
private:
    string name;
    vector<pair<shared_ptr<Course>, float>> courses;
    unsigned int id; // único
    
public:
    Student(unsigned int _id) : name("Alumno"), courses({}), id(_id) {};
    Student(string _name, unsigned int _id) : name(_name), courses({}), id(_id) {};
    Student(string _name, vector<pair<shared_ptr<Course>, float>> _courses, unsigned int _id) : name(_name), courses(_courses), id(_id) {};

    void courseInscribe(shared_ptr<Course> course, float grade = 0);
    void courseDesinscribe(shared_ptr<Course> course);

    bool setGrade(shared_ptr<Course> course, float grade);

    string getName() const;
    unsigned int getID() const;
    // vector<Course*> getCourses() const;
    float getAverage() const;

    bool operator == (const Student& student) const;
    bool operator < (const Student& student) const;
    friend ostream& operator <<(ostream& os, const Student& student);
};

#endif