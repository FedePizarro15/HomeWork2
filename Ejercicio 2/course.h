#pragma once

#include "student.h"

#include <vector>
#include <memory>
#include <string>

using namespace std;

class Course {
private:
    const string name;

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
    vector<shared_ptr<Student>> students;

public:
    Course() : name("Curso"), students({}) {};
    Course(const string _name) : name(_name), students({}) {};

    /*
    Utilizo Shallow Copy para copiar el vector que contiene shared_ptr<Student>, 
    de esta manera el nuevo curso tendrá punteros a los mismos estudiantes que el original, 
    lo que permite continuar inscribiendo y desinscribiendo alumnos independientemente entre estos cursos.
    Sería innecesario hacer un deep copy, es decir crear una nueva copia de cada estudiante, 
    ya que estos deben ser exactamente los mismos, para poder obtener correctamente los promedios y mantener una lógica general.
    Sin embargo en este constructor no se completa la copia de los cursos, 
    ya que falta inscribir de vuelta a cada alumno y para eso necesito tener el shared_ptr<Course> del nuevo curso que retorna este constructor, 
    es por eso que para crear una copia, uso un método de la clase Course (copyCourse) la cuál llama a este constructor y además inscribe cada uno de los estudiantes en el nuevo curso.
    */
    Course(const Course& toCopy, string _name) : name(_name), students(toCopy.students) {};

    shared_ptr<Course> copyCourse(const shared_ptr<Course> toCopy) const;

    void enrollStudent(shared_ptr<Student> student, shared_ptr<Course> course);
    void unenrollStudent(shared_ptr<Student> student, shared_ptr<Course> course);

    int isStudentEnrolled(const shared_ptr<Student> student) const;
    bool isFull() const;

    unsigned int getStudentsCount() const;
    string getName() const;
    const vector<shared_ptr<Student>>& getEnrolledStudents() const;

    void showStudents(shared_ptr<Course> course);

    bool operator== (const Course& course) const;
    friend ostream& operator <<(ostream& os, const Course& course);
};