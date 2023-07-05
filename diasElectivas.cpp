#include <iostream>
#include <string>
#include <vector>
#include "Horario.h"
#include "Materia.h"
using namespace std;

vector <vector<Materia>> calcularElectivas(vector <Materia> materias, int horas){
    vector<vector<Materia>> plan;
    vector<int> pila;
    pila.push_back(0);
    int auxHoras = horas - materias[0].getHorasCatedra();
    int indexMateria = 1;
    while (!pila.empty()){
        if(auxHoras <= 0){
            vector<Materia> subPlan;
            for(int i = 0; i<pila.size(); i++){
                subPlan.push_back(materias[pila[i]]);
            }
            plan.push_back(subPlan);
            auxHoras += materias[pila.back()].getHorasCatedra();
            pila.pop_back();
        }
        if(indexMateria >= materias.size()){            
            indexMateria = pila.back() + 1;
            auxHoras += materias[pila.back()].getHorasCatedra();
            pila.pop_back();
            if(pila.empty() && indexMateria < materias.size()){                
                pila.push_back(indexMateria);
                auxHoras -= materias[indexMateria].getHorasCatedra();
                indexMateria++;
            }
            continue;
        }
        bool superposicionHoraria = false;
        for(int i = 0; i<pila.size(); i++){
            if(materias[pila[i]].detectarSuperposicion(materias[indexMateria])){
                superposicionHoraria = true;
            }
        }
        if(!superposicionHoraria){
            pila.push_back(indexMateria);
            auxHoras -= materias[indexMateria].getHorasCatedra();
        }


        indexMateria++;
    }   
    
    return plan;
}   

int main(int argc, char * argv[]){

    vector<Materia> materias;


    Horario horario1(Horario::MIERCOLES,19*60,22*60);
    Horario horario2(Horario::VIERNES,19*60,22*60);    
    materias.push_back(Materia ("Redes Neuronales",8,horario1,horario2));

    Horario horario3(Horario::MIERCOLES,14*60+30,19*60);    
    materias.push_back( Materia ("Ev. e innovacion de tecnologias desde la perspectiva CTS",6,horario3));

    Horario horario4(Horario::LUNES,16*60 + 45,19*60);
    Horario horario5(Horario::JUEVES,16*60 + 45,19*60);        
    materias.push_back(Materia ("Gobierno Digital",6,horario4,horario5));
    
    Horario horario6(Horario::JUEVES,19*60,22*60);        
    materias.push_back(Materia ("Adm de servicios en Linux",8,horario1,horario6));

    Horario horario7(Horario::LUNES,19*60,23*60+30);
    materias.push_back(Materia ("Taller de Auditoria",6,horario7));
    
    Horario horario8(Horario::VIERNES,15*60 + 15,21*60+15);
    materias.push_back(Materia("Aprendizaje de Maquinas" ,8,horario8));

    Horario horario9(Horario::LUNES,19*60,22*60);
    materias.push_back(Materia("Arquitectura de microservicios" ,8,horario9,horario6));

    Horario horario10(Horario::MIERCOLES,17*60 + 30,20*60 + 30);
    materias.push_back(Materia("Bases de Datos Avanzadas" ,8,horario10,horario2));

    Horario horario11(Horario::MARTES,14*60 + 30,19*60);
    Horario horario12(Horario::VIERNES,17*60 + 30,19*60);
    materias.push_back(Materia("Informatica Industrial" ,8,horario11,horario5));

    Horario horario13(Horario::LUNES,21*60 + 15,22*60 + 45);
    materias.push_back(Materia("Desarrollo de Sw dirigido por modelos" ,6,horario13,horario2));

    Horario horario14(Horario::MARTES,19*60,21*60 + 15);
    Horario horario15(Horario::VIERNES,19*60,21*60 + 15);
    materias.push_back(Materia("Diseño de UX" ,6,horario14,horario15));

    Horario horario16(Horario::MARTES,19*60,22*60);
    materias.push_back(Materia("Administracion de Proyectos" ,8,horario9,horario5));


    vector <vector<Materia>> inscripciones = calcularElectivas(materias,24);
    for(int j = 0; j<inscripciones.size(); j++){
        cout << "Plan " << j + 1 << endl;
        for(int i = 0; i<inscripciones[j].size(); i++){
            cout << "\t"<<inscripciones[j][i].mostrarMateria() << endl;
        }
    }
        
    
    
    if(materias[1].detectarSuperposicion(materias[2])){
        cout << "true";
    }else{
        cout << "false";
    }
    
    
    
    
    

}