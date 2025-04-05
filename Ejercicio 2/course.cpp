#include "course.h"

#include <iostream>
#include <algorithm>
#include <iomanip>

void Course::enrollStudent(shared_ptr<Student> student, shared_ptr<Course> course) {
    if (isFull()) {
        cout << "El curso " << *this << " está completo, no se puede inscribir al alumno " << *student << "." << endl << endl;
        return;
    };

    if (isStudentEnrolled(student) >= 0) {
        cout << "El alumno " << *student << " ya está inscripto en el curso " << *this << "." << endl << endl;
        return;
    }

    student->courseInscribe(course);
    students.push_back(student);
    
    cout << "Se inscribió al alumno " << *student << " en el curso " << *this << "." << endl << endl;
};

void Course::unenrollStudent(shared_ptr<Student> student, shared_ptr<Course> course) {
    int studentIndex = isStudentEnrolled(student);

    if (studentIndex == -1) {
        cout << "El estudiante " << *student << " no está inscripto en el curso " << *this << "." << endl << endl;
    } else {
        student->courseDesinscribe(course);
        students.erase(students.begin() + studentIndex);
    
        cout << "Se desinscribió al alumno " << *student << " del curso " << *this << "." << endl << endl;
    };
};

int Course::isStudentEnrolled(const shared_ptr<Student> student) const {
    for (unsigned int i = 0; i < students.size(); i++) {
        if (*students[i] == *student) {
            return i;
        };
    };
    
    return -1;
};

bool Course::isFull() const {
    return students.size() >= 20;
};

unsigned int Course::getStudentsCount() const {
    return students.size();
};

string Course::getName() const {
    return name;
};

const vector<shared_ptr<Student>>& Course::getEnrolledStudents() const {
    return students;
}

void Course::showStudents() {
    sort(students.begin(), students.end(),
        [](const shared_ptr<Student>& a, const shared_ptr<Student>& b) {return *a < *b;});
    
    for (unsigned int i = 0; i < students.size(); i++) {
        cout << setw(2) << right << (i + 1) << ". > " << *students[i] << " (" << students[i]->getGrade(make_shared<Course>(*this, name)) << ")." << endl;
    };

    cout << endl;
};

bool Course::operator== (const Course &course) const {return this->name == course.name;};

ostream& operator<<(ostream &os, const Course &course) {
    os << "'" << course.getName() << "'";
    return os;
};