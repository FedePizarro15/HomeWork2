#pragma once

#include "student.h"

#include <vector>
#include <memory>
#include <string>

using namespace std;

class Course {
private:
        string name;
        vector<shared_ptr<Student>> students;

public:
    Course(string _name);
    Course(string _name, vector<shared_ptr<Student>> _students);

    void enrollStudent(Student& student);
    void unenrollStudent(Student& student);

    int isStudentErolled(Student& student);
    bool isFull();
    unsigned int getStudentsCount();

    string getName() const;
    void showStudents();

    bool operator== (const Course& course) const;
};