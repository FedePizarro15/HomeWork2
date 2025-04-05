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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, *variable);
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

bool checkCoursesExist(const vector<shared_ptr<Course>>& courses) {
    if (courses.empty()) {
        cout << "No hay cursos registrados." << endl;
        return false;
    }
    return true;
};

bool checkStudentsExist(const vector<shared_ptr<Student>>& students) {
    if (students.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return false;
    }
    return true;
};

shared_ptr<Course> selectCourse(const vector<shared_ptr<Course>>& courses) {
    cout << "Seleccione un curso (1 - " << courses.size() << "):" << endl;

    for (size_t i = 0; i < courses.size(); i++) {
        cout << i + 1 << ". " << *courses[i] << endl;
    }

    int option;
    input("Ingrese una opción:", &option);
                
    if (option < 1 || option > static_cast<int>(courses.size())) {
        cout << "Opción inválida." << endl;
        return nullptr;
    }

    return courses[option - 1];
};

shared_ptr<Student> selectStudent(const vector<shared_ptr<Student>>& students) {
    cout << "Seleccione un estudiante (1 - " << students.size() << "):" << endl;

    for (size_t i = 0; i < students.size(); i++) {
        cout << i + 1 << ". " << *students[i] << "." << endl;
    }

    int option;
    input("Ingrese una opción:", &option);
                
    if (option < 1 || option > static_cast<int>(students.size())) {
        cout << "Opción inválida." << endl;
        return nullptr;
    }

    return students[option - 1];
};

int main() {
    vector<shared_ptr<Course>> courses;
    vector<shared_ptr<Student>> students;

    unsigned int nextStudentID = 1000;
    
    int option = 0;
    
    do {
        system("clear");
        
        cout << "======== SISTEMA DE GESTIÓN ACADÉMICA ========" << endl;
        cout << "1. Crear Curso" << endl;
        cout << "2. Crear Estudiante" << endl;
        cout << "3. Listar Estudiantes de un Curso" << endl;
        cout << "4. Inscribir Estudiante en Curso" << endl;
        cout << "5. Desinscribir Estudiante de Curso" << endl;
        cout << "6. Asignar Calificación" << endl;
        cout << "7. Estado de Curso" << endl;
        cout << "8. Promedio de Estudiante" << endl;
        cout << "9. Copiar Curso" << endl;
        cout << "10. Verificar inscripción de estudiante en curso" << endl;
        cout << "0. Salir" << endl;
        cout << "=============================================" << endl;
        cout << "Ingrese una opción: ";
        cin >> option;
        cout << endl;
        
        switch (option) {
            case 1: {
                string name;
                input("Ingrese el nombre del curso:", &name);

                shared_ptr<Course> newCourse = make_shared<Course>(name);

                courses.push_back(newCourse);
                cout << "Curso " << *newCourse << " creado exitosamente." << endl;
                break;
            };
            case 2: {
                string name;
                input("Ingrese el nombre del estudiante:", &name);

                shared_ptr<Student> newStudent = make_shared<Student>(name, nextStudentID++);

                students.push_back(newStudent);
                cout << "Estudiante " << *newStudent << " creado exitosamente." << endl;
                break;
            };
            case 3: {
                if (!checkCoursesExist(courses)) break;
                
                shared_ptr<Course> selectedCourse = selectCourse(courses);
                if(!selectedCourse) break;

                if (selectedCourse->getStudentsCount() == 0) {
                    cout << "No hay estudiantes inscriptos en este curso." << endl;
                    break;
                }
                
                cout << "\nEstudiantes en el curso " << *selectedCourse << ":" << endl;

                selectedCourse->showStudents();
                break;
            };
            case 4: {
                if (!(checkStudentsExist(students) || checkCoursesExist(courses))) break;
                
                shared_ptr<Course> selectedCourse = selectCourse(courses);
                if(!selectedCourse) break;
                
                shared_ptr<Student> selectedStudent = selectStudent(students);
                if (!selectedStudent) break;
                
                selectedCourse->enrollStudent(selectedStudent, selectedCourse);
                break;
            };
            case 5: {
                if (!(checkStudentsExist(students) || checkCoursesExist(courses))) break;
                
                shared_ptr<Course> selectedCourse = selectCourse(courses);
                if(!selectedCourse) break;

                shared_ptr<Student> selectedStudent = selectStudent(students);
                if (!selectedStudent) break;
                
                selectedCourse->unenrollStudent(selectedStudent, selectedCourse);
                break;
            };

            case 6: {
                if (!(checkStudentsExist(students) || checkCoursesExist(courses))) break;
                
                shared_ptr<Student> selectedStudent = selectStudent(students);
                if (!selectedStudent) break;
                
                shared_ptr<Course> selectedCourse = selectCourse(courses);
                if(!selectedCourse) break;
                
                float grade;
                input("Ingrese la calificación (0 - 10):", &grade);
                
                if (grade < 0 || grade > 10) {
                    cout << "La calificación debe estar entre 0 y 10." << endl;
                    break;
                }
                
                if (!selectedStudent->setGrade(selectedCourse, grade)) break;
                
                cout << "Calificación asignada correctamente." << endl;
                break;
            };
            case 7: {
                if (!checkCoursesExist(courses)) break;
                
                shared_ptr<Course> selectedCourse = selectCourse(courses);
                if(!selectedCourse) break;

                cout << "Estado del curso " << *selectedCourse << ":" << endl << endl;

                if (selectedCourse->isFull()) {
                    cout << "El curso está lleno." << endl << endl;
                } else {
                    cout << "El curso no está lleno." << endl << endl;
                }

                cout << selectedCourse->getStudentsCount() << " estudiantes inscriptos (" << 20 - selectedCourse->getStudentsCount() << " cupos disponibles)" << endl;
                
                break;
            };
            case 8: {
                if (!checkStudentsExist(students)) break;
                
                shared_ptr<Student> selectedStudent = selectStudent(students);
                if (!selectedStudent) break;
                
                cout << "El promedio del estudiante " << *selectedStudent << " es: " << selectedStudent->getAverage() << endl;
                break;
            };
            case 9: {
                if (!checkCoursesExist(courses)) break;
                
                shared_ptr<Course> selectedCourse = selectCourse(courses);
                if(!selectedCourse) break;

                string nameNewCourse;
                input("Ingrese el nombre del nuevo curso:", &nameNewCourse);

                shared_ptr<Course> newCourse = make_shared<Course>(*selectedCourse, nameNewCourse);

                courses.push_back(newCourse);

                cout << "Inscribiendo estudiantes del curso original al nuevo curso..." << endl;
                
                for (const auto& student : selectedCourse->getEnrolledStudents()) {
                    student->courseInscribe(newCourse);
                }

                cout << "Curso " << *newCourse << " creado exitosamente." << endl;
                break;
            };
            case 10: {
                if (!(checkStudentsExist(students) || checkCoursesExist(courses))) break;
                
                shared_ptr<Student> selectedStudent = selectStudent(students);
                if (!selectedStudent) break;
                
                shared_ptr<Course> selectedCourse = selectCourse(courses);
                if(!selectedCourse) break;
                
                if (selectedCourse->isStudentEnrolled(selectedStudent) >= 0) {
                    cout << "El estudiante " << *selectedStudent << " está inscripto en el curso " 
                         << *selectedCourse << "." << endl;
                } else {
                    cout << "El estudiante " << *selectedStudent << " no está inscripto en el curso " 
                         << *selectedCourse << "." << endl;
                }
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