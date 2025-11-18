//Desarrolla un sistema de gestión académica para la UNI que permita administrar la información de estudiantes, cursos y sus calificaciones.
//El sistema debe utilizar estructuras en C++ para organizar los datos de manera eficiente. Su implementación debe:
//Aplicar conceptos de estructuras en C++,implementar arreglos de estructuras, usar anidamiento de estructuras, trabajar con punteros a estructuras,
//pasar estructuras como parametros de funciones e implementar funciones miembro en estructuras.
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Notas {
    float EP;  // Examen Parcial (30%)
    float EF;  // Examen Final (50%)
    float PP;  // Promedio de Prácticas (20%)
    
    // Función para calcular promedio final
    float calcularPromedio() {
        return EP * 0.3 + EF * 0.5 + PP * 0.2;
    }
    
    // Función para determinar estado
    string obtenerEstado() {
        float prom = calcularPromedio();
        if (prom >= 10.5) return "Aprobado";
        else return "Desaprobado";
    }
};
struct Curso {
    string codigo;
    string nombre;
    int creditos;
    string profesor;
    Notas notas;  // Estructura anidada
    
    void mostrarInformacion() {
        // Implementar: mostrar información del curso
    }
};
struct Estudiante {
    string codigo;
    string nombre;
    string carrera;
    int ciclo;
    Curso cursos[6];  // Máximo 6 cursos por estudiante
    int cantidadCursos;
    
    void mostrarDatos() {
        // Implementar: mostrar datos del estudiante
    }
};
// Prototipos de funciones a implementar

//gestion de estudiantes
void registrarEstudiante(Estudiante estudiantes[],int &cantidad);
//gestion de cursos por estudiante
void matricularCurso(Estudiante &estudiante);
void ingresarNotas(Estudiante &estudiante);
void mostrarCursosEstudiante(const Estudiante &estudiante);
//calculos academicos
float calcularPromedioPonderado(const Estudiante &estudiante);
int calcularTotalCreditos(const Estudiante &estudiante);
void generarBoleta(const Estudiante &estudiante);
//reportes del sistema
void mostrarMejorPromedio(const Estudiante estudiantes[],int cantidad);
void estudiantesAprobadosCurso(const Estudiante estudiantes[],int cantidad,string codigoCurso);
void reporteGeneral(const Estudiante estudiantes[],int cantidad);


int main(){
    Estudiante estudiantes[100];
    Estudiante* ptrEstudiantes;
    ptrEstudiantes= estudiantes;
    int cantidadEstudiantes = 0;
    int opcion;
    for(int i = 0; i < 100; i++){
        estudiantes[i].cantidadCursos = 0;
    }
    do{
        cout << "Sistema de Gestion Academica - UNI" << endl;
        cout << "1. Registrar Estudiante" << endl;
        cout << "2. Matricular curso a estudiante" << endl;
        cout << "3. Ingresar notas de curso" << endl;
        cout << "4. Mostrar informacion de estudiante" << endl;
        cout << "5. Generar boleta de notas" << endl;
        cout << "6. Mostrar mejor promedio" << endl;
        cout << "7. Estudiantes aprobados por curso" << endl;
        cout << "8. Reporte general" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione una opcion: ";
        
        
        cin >> opcion;
        
        switch (opcion)
        {
        case 1:
            registrarEstudiante(estudiantes, cantidadEstudiantes);
            cantidadEstudiantes++;
            break;
        case 2:
            {string codigoEstudiante;
            string nombreEstudiante;     
            cout<<"=== MATRICULAR CURSO ==="<<endl;
            cout<<"Estudiante: ";
            getline(cin, codigoEstudiante);
            cin.ignore();
            getline(cin, nombreEstudiante);
            for(int i = 0; i < cantidadEstudiantes; i++){
                if(ptrEstudiantes->codigo == codigoEstudiante && ptrEstudiantes->nombre == nombreEstudiante){
                    matricularCurso(ptrEstudiantes[i]);
                    break;
                }
                ptrEstudiantes++;
            }
            }
            break;
        case 3:
            {string codigoEstudiante;
            string nombreEstudiante;
            cout<<"Nombre Estudiante: ";
            getline(cin, codigoEstudiante);
            cin.ignore();
            getline(cin, nombreEstudiante);
            for(int i = 0; i < cantidadEstudiantes; i++){
                if(ptrEstudiantes->codigo == codigoEstudiante && ptrEstudiantes->nombre == nombreEstudiante){
                    ingresarNotas(ptrEstudiantes[i]);
                    break;
                }
                ptrEstudiantes++;
            }
            }
            break;
        case 4:
            {string codigoEstudiante;
            string nombreEstudiante;
            cout<<"Nombre Estudiante: ";
            getline(cin, codigoEstudiante);
            cin.ignore();
            getline(cin, nombreEstudiante);
            for(int i = 0; i < cantidadEstudiantes; i++){
                if(ptrEstudiantes->codigo == codigoEstudiante && ptrEstudiantes->nombre == nombreEstudiante){
                    mostrarCursosEstudiante(ptrEstudiantes[i]);
                    break;
                }
                ptrEstudiantes++;
            }
            }
            
            break;
        case 5:
             {string codigoEstudiante;
            string nombreEstudiante;
            cout<<"Nombre Estudiante: ";
            getline(cin, codigoEstudiante);
            cin.ignore();
            getline(cin, nombreEstudiante);
            for(int i = 0; i < cantidadEstudiantes; i++){
                if(ptrEstudiantes->codigo == codigoEstudiante && ptrEstudiantes->nombre == nombreEstudiante){
                    generarBoleta(ptrEstudiantes[i]);
                    break;
                }
                ptrEstudiantes++;
            }
            }
            
            break;
        case 6:
            mostrarMejorPromedio(estudiantes, cantidadEstudiantes);
            break;
        case 7:
            cout<<"Codigo del curso: ";
            {
                string codigoCurso;
                getline(cin, codigoCurso);
                cin.ignore();
                estudiantesAprobadosCurso(estudiantes, cantidadEstudiantes, codigoCurso);
            }
            break;
        case 8:
            reporteGeneral(estudiantes, cantidadEstudiantes);
            break;
        case 9:
            cout<<"Saliendo del sistema..."<<endl;
            break;
        default:
            break;
        }
           
    }while(opcion != 9);

    return 0;
}

void registrarEstudiante(Estudiante estudiantes[],int &cantidad){
    cout<<"=== REGISTRAR ESTUDIANTE ==="<<endl;
    cout<<"Codigo: ";
    getline(cin, estudiantes[cantidad].codigo);
    cin.ignore();
    cout<<"Nombre: ";
    getline(cin, estudiantes[cantidad].nombre);
    cin.ignore();
    cout<<"Carrera: ";
    getline(cin, estudiantes[cantidad].carrera);
    cin.ignore();
    cout<<"Ciclo: ";
    cin>>estudiantes[cantidad].ciclo;
}

void matricularCurso(Estudiante &estudiante){
    if(estudiante.cantidadCursos >= 6){
        cout<<"El estudiante ya tiene el maximo de cursos matriculados."<<endl;
        return;
    }else{
    Curso &curso = estudiante.cursos[estudiante.cantidadCursos];
    cout<<"Codigo curso: ";
    getline(cin, curso.codigo);
    cin.ignore();
    cout<<"Nombre: ";
    getline(cin, curso.nombre);
    cin.ignore();
    cout<<"Creditos: ";
    cin>>curso.creditos;
    cout<<"Profesor: ";
    getline(cin, curso.profesor);
    estudiante.cantidadCursos++;
    } 
}
void ingresarNotas(Estudiante &estudiante) {
    string codigoCurso;
    string nombreCurso;
    cout<<"Curso: ";
    getline(cin, codigoCurso);
    cin.ignore();
    getline(cin, nombreCurso);
    for(int i = 0; i < estudiante.cantidadCursos; i++){
        if(estudiante.cursos[i].codigo == codigoCurso && estudiante.cursos[i].nombre == nombreCurso){
            cout<<"=== INGRESAR NOTAS ==="<<endl;
            cout<<"Examen Parcial: ";
            cin>>estudiante.cursos[i].notas.EP;
            cout<<"Examen Final: ";
            cin>>estudiante.cursos[i].notas.EF;
            cout<<"Promedio de Practicas: ";
            cin>>estudiante.cursos[i].notas.PP;
            return;
        }
    }
    
}
void mostrarCursosEstudiante(const Estudiante &estudiante){
     cout<<"Estudiante: "<<estudiante.nombre<<endl;
     cout<<"Cursos Matriculados: "<<endl;
     for(int i=0;i<estudiante.cantidadCursos;i++){
        cout<<estudiante.cursos[i].codigo<<" - "<<estudiante.cursos[i].nombre<<endl;
     }
}
void generarBoleta(const Estudiante &estudiante){
    Notas notas = estudiante.cursos->notas;
    cout<<"=== BOLETA DE NOTAS ==="<<endl;
    cout<<"Estudiante: "<<estudiante.nombre<<" ("<<estudiante.codigo<<")"<<endl;
    cout<<"Carrera: "<<estudiante.carrera<<" - Ciclo: "<<estudiante.ciclo<<endl;
    cout<<setw(6)<<std::left<<"Codigo"<<" "<<setw(30)<<std::left<<"Curso"<<" "<<setw(8)<<std::left<<"Creditos"<<" "<<setw(2)<<std::left<<"EP"<<" "<<setw(2)<<std::left<<"EF"<<" "<<setw(2)<<std::left<<"PP"<<" "<<setw(8)<<std::left<<"Promedio"<<" "<<setw(10)<<"Estado"<<endl;
    for(int i=0;i<estudiante.cantidadCursos;i++){
       cout<<setw(6)<<std::left<<estudiante.cursos[i].codigo<<" "<<setw(30)<<std::left<<estudiante.cursos[i].nombre<<" "<<setw(8)<<std::left<<estudiante.cursos[i].creditos<<" "<<setw(2)<<std::left<<estudiante.cursos[i].notas.EP<<" "<<setw(2)<<std::left<<estudiante.cursos[i].notas.EF<<" "<<setw(2)<<std::left<<estudiante.cursos[i].notas.PP<<" "<<setw(8)<<std::left<<notas.calcularPromedio()<<" "<<setw(10)<<std::left<<notas.obtenerEstado();
    }
        
}
int calcularTotalCreditos(const Estudiante &estudiante){
    int totalCreditos = 0;
    for(int i = 0; i < estudiante.cantidadCursos; i++){
        totalCreditos += estudiante.cursos[i].creditos;
    }
    return totalCreditos;
}
float calcularPromedioPonderado(const Estudiante &estudiante){
    float sumaPromedios = 0.0;
    Notas notas= estudiante.cursos->notas;
    for(int i = 0; i < estudiante.cantidadCursos; i++){
        sumaPromedios += notas.calcularPromedio();
        notas = estudiante.cursos[i+1].notas;
    }
    return sumaPromedios / estudiante.cantidadCursos;
}
void mostrarMejorPromedio(const Estudiante estudiantes[],int cantidad){
   float mejorPromedio = 0.0;
   string nombreMejorEstudiante;
   for(int i = 0; i < cantidad; i++){
       float promedioEstudiante = calcularPromedioPonderado(estudiantes[i]);
       if(promedioEstudiante > mejorPromedio){
           mejorPromedio = promedioEstudiante;
           nombreMejorEstudiante = estudiantes[i].nombre;
       }
   }
   cout<<"Alumno: "<<nombreMejorEstudiante<<" con promedio "<<mejorPromedio<<endl;
}
void estudiantesAprobadosCurso(const Estudiante estudiantes[],int cantidad,string codigoCurso){
    cout<<"=== ESTUDIANTES APROBADOS EN CURSO "<<codigoCurso<<" ==="<<endl;
    for(int i = 0; i < cantidad; i++){
        for(int j = 0; j < estudiantes[i].cantidadCursos; j++){
            if(estudiantes[i].cursos[j].codigo == codigoCurso){
                Notas notas = estudiantes[i].cursos[j].notas;
                if(notas.obtenerEstado() == "Aprobado"){
                    cout<<"Estudiante: "<<estudiantes[i].nombre<<" ("<<estudiantes[i].codigo<<") - Promedio: "<<notas.calcularPromedio()<<endl;
                }
            }
        }
    }

}
void reporteGeneral(const Estudiante estudiantes[],int cantidad){
    cout<<"=== REPORTE GENERAL DE ESTUDIANTES ==="<<endl;
    for(int i = 0; i < cantidad; i++){
        cout<<"Estudiante: "<<estudiantes[i].nombre<<" ("<<estudiantes[i].codigo<<")"<<endl;
        cout<<"Carrera: "<<estudiantes[i].carrera<<" - Ciclo: "<<estudiantes[i].ciclo<<endl;
        cout<<"Cursos Matriculados: "<<estudiantes[i].cantidadCursos<<endl;
        cout<<"Total Creditos: "<<calcularTotalCreditos(estudiantes[i])<<endl;
        cout<<"Promedio Ponderado: "<<calcularPromedioPonderado(estudiantes[i])<<endl;
    }
}