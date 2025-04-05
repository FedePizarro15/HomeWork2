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

    /*
    La relación entre estudiantes (Student) y cursos (Course), es de agregación, 
    ya que los cursos tienen un vector<shared_ptr<Student>>, es decir "tienen" una lista de estudiantes, 
    pero los estudiantes pueden existir independientemente de un curso y lo mismo para los cursos.
    Las gestiones de los ciclos de vida son independientes. Por otro lado los estudiantes "conocen" los cursos a los que están inscriptos, 
    ya que cuentan con un vector<weak_ptr<Course>>, esto es para romper con un ciclo de referencias.

    En este caso, los alumnos son las "partes", y el curso el "todo".
    Los alumnos pueden ser inscriptos y desincriptos, asignarles una nota, obtener su promedio, etc.
    En el caso que un curso cierre, los alumnos se pueden inscribir en un curso nuevo, sin dejar de ser alumnos.
    Por otro lado, si todos los estudiantes se desincriben de un curso, el curso puede tomar nuevos alumnos, sin dejar de existir.
    */
    vector<pair<weak_ptr<Course>, float>> courses;
    void courseDesinscribe(shared_ptr<Course> course);
    
public:
    Student(const string _name, const unsigned int _id) : name(_name), id(_id), courses({}) {};

    void courseInscribe(shared_ptr<Course> course, const float grade = 0);

    bool setGrade(const shared_ptr<Course> course, const float grade);

    const string getName() const;
    const unsigned int getID() const;
    const float getGrade(shared_ptr<Course> course) const;
    const float getAverage() const;

    bool operator == (const Student& student) const;
    bool operator < (const Student& student) const;
    friend ostream& operator <<(ostream& os, const Student& student);

    friend class Course;
};

#endif