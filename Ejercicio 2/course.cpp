#include "course.h"
#include <iostream>
#include <algorithm>

Course::Course(string _name) {
    name = _name;
    students = {};
};

Course::Course(string _name, vector<shared_ptr<Student>> _students) {
    name = _name;
    students = _students;
};

void Course::enrollStudent(Student& student) {
    if (isFull()) {
        cout << "El curso '" << name << "' está completo, no se puede inscribir al alumno '" << student.getName() << "'." << endl << endl;
        return;
    };

    if (isStudentErolled(student) >= 0) {
        cout << "El alumno '" << student.getName() << "' ya está inscripto en el curso '" << name << "'." << endl << endl;
        return;
    }

    students.push_back(make_shared<Student>(student));
    student.courseInscribe(*this);
    
    cout << "Se inscribió al alumno '" << student.getName() << "' en el curso '" << name << "'." << endl << endl;
};

void Course::unenrollStudent(Student& student) {
    int studentIndex = isStudentErolled(student);

    if (studentIndex == -1) {
        cout << "El estudiante no está inscripto en el curso '" << student.getName() << "'." << endl << endl;
    } else {
        students.erase(students.begin() + studentIndex);
        student.courseDesinscribe(*this);
    
        cout << "Se desinscribió al alumno '" << student.getName() << "' del curso '" << name << "'." << endl << endl;
    };
};

int Course::isStudentErolled(Student& student) {
    for (unsigned int i = 0; i < students.size(); i++) {
        if (*students[i] == student) {
            return i;
        };
    };
    
    return -1;
};

bool Course::isFull() {
    return students.size() >= 20 ? true : false;
};

unsigned int Course::getStudentsCount() {
    return students.size();
};

string Course::getName() const {
    return name;
};

void Course::showStudents() {
    sort(students.begin(), students.end());
    
    for (unsigned int i = 0; i < students.size(); i++) {
        cout << "> " << students[i]->getName() << endl;
    };
};

bool Course::operator== (const Course& course) const {
    if (this->name == course.name) return true;
    else return false;
};