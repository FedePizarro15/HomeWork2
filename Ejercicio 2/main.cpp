#include "course.h"
#include "student.h"
#include <iostream>
#include <limits>
#include <vector>
#include <memory>

using namespace std;

void input(string message, int* variable) {
    cout << message << endl << ">> ";
    cin >> *variable;
    cout << endl;
};

void input(string message, float* variable) {
    cout << message << endl << ">> ";
    cin >> *variable;
    cout << endl;
};

void input(string message, string* variable) {
    cout << message << endl << ">> ";
    cin >> *variable;
    cout << endl;
};

void input(string message, bool* variable) {
    cout << message << endl << ">> ";
    cin >> *variable;
    cout << endl;
};

void pauseAndContinue(string message = "Presione Enter para continuar...") {
    cout << message << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cin.get();
};

bool checkStudentsAndCoursesExist(const vector<Student>& students, const vector<Course>& courses) {
    if (students.empty() || courses.empty()) {
        cout << "Debe haber al menos un estudiante y un curso registrados." << endl;
        return false;
    }
    return true;
};

bool checkCoursesExist(const vector<Course>& courses) {
    if (courses.empty()) {
        cout << "No hay cursos registrados." << endl;
        return false;
    }
    return true;
};

bool checkStudentsExist(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No hay cursos registrados." << endl;
        return false;
    }
    return true;
};

bool selectCourse(const vector<Course>& courses, int& option) {
    cout << "Seleccione un curso (0 - " << courses.size() << "):" << endl;
    for (size_t i = 0; i < courses.size(); i++) {
        cout << i + 1 << ". " << courses[i].getName() << endl;
    }

    input("Ingrese una opción:", &option);
                
    if (option < 1 || option > static_cast<int>(courses.size())) {
        cout << "Opción inválida." << endl;
        return false;
    }

    return true;
};

bool selectStudent(const vector<Student>& students, int& option) {
    cout << "Seleccione un estudiante (0 - " << students.size() << "):" << endl;
    for (size_t i = 0; i < students.size(); i++) {
        cout << i + 1 << ". " << students[i].getName() << " (ID: " << students[i].getID() << ")" << endl;
    }

    input("Ingrese una opción:", &option);
                
    if (option < 1 || option > static_cast<int>(students.size())) {
        cout << "Opción inválida." << endl;
        return false;
    }

    return true;
};

int main() {
    vector<Course> courses;
    vector<Student> students;

    unsigned int nextStudentID = 1000;
    
    int option = 0;
    
    do {
        cout << "======== SISTEMA DE GESTIÓN ACADÉMICA ========" << endl;
        cout << "1. Crear Curso" << endl;
        cout << "2. Crear Estudiante" << endl;
        cout << "3. Listar Estudiantes de un Curso" << endl;
        cout << "4. Inscribir Estudiante en Curso" << endl;
        cout << "5. Desinscribir Estudiante de Curso" << endl;
        cout << "6. Asignar Calificación" << endl;
        cout << "7. Estado de Curso" << endl;
        cout << "8. Promedio de Estudiante" << endl;
        cout << "0. Salir" << endl;
        cout << "=============================================" << endl;
        cout << "Ingrese una opción: ";
        cin >> option;
        cout << endl;
        
        switch (option) {
            case 1: {
                string name;
                input("Ingrese el nombre del curso:", &name);

                courses.push_back(Course(name));
                cout << "Curso '" << name << "' creado exitosamente." << endl;
                break;
            };
            case 2: {
                string name;
                input("Ingrese el nombre del estudiante:", &name);

                students.push_back(Student(name, nextStudentID++));
                cout << "Estudiante '" << name << "' con ID " << nextStudentID - 1 << " creado exitosamente." << endl;
                break;
            };
            case 3: {
                if (!checkCoursesExist(courses)) break;
                
                int courseIndex;
                if (!selectCourse(courses, courseIndex)) break;

                if (courses[courseIndex - 1].getStudentsCount() == 0) {
                    cout << "No hay estudiantes inscriptos en este curso." << endl;
                    break;
                }
                
                cout << "\nEstudiantes en el curso '" << courses[courseIndex-1].getName() << "':" << endl;

                courses[courseIndex-1].showStudents();
                break;
            };
            case 4: {
                if (!checkStudentsAndCoursesExist(students, courses)) break;
                
                int courseIndex;
                if (!selectCourse(courses, courseIndex)) break;
                
                int studentIndex;
                if (!selectStudent(students, studentIndex)) break;
                
                courses[courseIndex-1].enrollStudent(students[studentIndex-1]);
                break;
            };
            case 5: {
                if (!checkStudentsAndCoursesExist(students, courses)) break;
                
                int courseIndex;
                if (!selectCourse(courses, courseIndex)) break;

                int studentIndex;
                if (!selectStudent(students, studentIndex)) break;
                
                courses[courseIndex-1].unenrollStudent(students[studentIndex-1]);
                break;
            };

            case 6: {
                if (!checkStudentsAndCoursesExist(students, courses)) break;
                
                int studentIndex;
                if (!selectStudent(students, studentIndex)) break;
                
                int courseIndex;
                if (!selectCourse(students[studentIndex - 1].getCourses(), courseIndex)) break;
                
                float grade;
                input("Ingrese la calificación (0 - 10):", &grade);
                
                if (grade < 0 || grade > 10) {
                    cout << "La calificación debe estar entre 0 y 10." << endl;
                    break;
                }
                
                students[studentIndex-1].setGrade(courses[courseIndex-1], grade);
                cout << "Calificación asignada correctamente." << endl;
                break;
            };
            case 7: {
                if (!checkCoursesExist(courses)) break;
                
                int courseIndex;
                if (!selectCourse(courses, courseIndex)) break;
                
                Course& selectedCourse = courses[courseIndex-1];
                cout << "\nEstado del curso '" << selectedCourse.getName() << "':" << endl;
                cout << "Está lleno: " << (selectedCourse.isFull() ? "Sí" : "No") << endl;
                cout << "Estudiantes inscriptos:" << endl;

                selectedCourse.showStudents();
                break;
            };
            case 8: {
                if (!checkStudentsExist(students)) break;
                
                int studentIndex;
                if (!selectStudent(students, studentIndex)) break;
                
                cout << "El promedio del estudiante '" << students[studentIndex-1].getName() << "' (ID: " << students[studentIndex-1].getID() << ")"
                     << " es: " << students[studentIndex-1].getAverage() << endl;
                break;
            };
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }
        
        if (option != 0) {
            pauseAndContinue();
        }
        
    } while (option != 0);
    
    return 0;
}