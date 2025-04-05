#pragma once

#include "student.h"

#include <vector>
#include <memory>
#include <string>

using namespace std;

class Course {
private:
    const string name;
    vector<shared_ptr<Student>> students;

public:
    Course() : name("Curso"), students({}) {};
    Course(const string _name) : name(_name), students({}) {};
    Course(const Course& toCopy, string _name) : name(_name), students(toCopy.students) {};

    void enrollStudent(shared_ptr<Student> student, shared_ptr<Course> course);
    void unenrollStudent(shared_ptr<Student> student, shared_ptr<Course> course);

    int isStudentEnrolled(const shared_ptr<Student> student) const;
    bool isFull() const;

    unsigned int getStudentsCount() const;
    string getName() const;
    const vector<shared_ptr<Student>>& getEnrolledStudents() const;

    void showStudents();

    bool operator== (const Course& course) const;
    friend ostream& operator <<(ostream& os, const Course& course);
};