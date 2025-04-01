#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

// Forward declaration
class Course;

class Student {
private:
    string name;
    vector<pair<shared_ptr<Course>, float>> courses;
    unsigned int id; // único
    
public:
    Student(string _name, unsigned int _id);
    Student(string _name, vector<pair<shared_ptr<Course>, float>> _courses, unsigned int _id);

    void courseInscribe(Course& course, float grade = 0);
    void courseDesinscribe(Course course);
    void setGrade(Course course, float grade);

    string getName() const;
    unsigned int getID() const;
    vector<Course> getCourses();
    float getAverage();

    bool operator == (Student& student) const;
    bool operator << (Student& student) const;
};

#endif