#ifndef MATERIA_H
#define MATERIA_H
#include "Horario.h"
#include <string>

class Materia
{
private:
    /**
     * Representa los horarios de la mateira. Una materia solo puede tener 2 horarios
     */
    Horario horarios[2];
    /**
     * Representa el nombre de la mateira
     */
    std::string nombre;
    /**
     * Representa cuantas horas catedra tiene la materia
     */
    int horasCatedra;

public:
    /**
     * Constructor completo.
     * @param nombre Nombre de la materia
     * @param horassCatedra Numero de horas catedra de la materia
     * @param horario1 Primero horario de la materia
     * @param horario2 Segundo Horario de la materia
     */
    Materia(std::string nombre, int horasCatedra, Horario horario1, Horario horario2);
    /**
     * Constructor para crear una materia con un solo horario. El segundo horario se mone como UNDEF
     * @param nombre Nombre de la materia
     * @param horassCatedra Numero de horas catedra de la materia
     * @param horario1 Primero horario de la materia
     */
    Materia(std::string nombre, int horasCatedra, Horario horario1);
    /**
     * Move Constructor
     */
    Materia(Materia &&materia);
    /**
     * Constructor de copia
     */
    Materia(const Materia &materia);
    /**
     * Establece los horarios. Los mismo deben tener dias de la semana distintos.
     */
    void setHorario(Horario horario1, Horario horario2);
    /**
     * Establece solo el primer horario de la materia
     */
    void setHorario(Horario horario1);
    /**
     * Establece el nombre de la materia. El mismo no debe ser vacío
     */
    void setNombre(std::string nombre);
    /**
     * Establece la cantidad de horas catedras de la materia la valor pasado como parametro. Debe pasar un entero mayor a cero
     */
    void setHorasCatedra(int horasCatedra);
    /**
     * Devuelve los horarios de la materia
     * @return Puntero al vector dedimensión 2 de horarios. SI la materia solo posee n horario, el seundo elemento del vector tendra diaSemana = Horario::UNDEF
     */
    Horario *getHorarios();
    /**
     * Devuelve el nombre de la materia
     */
    std::string getNombre();
    /**
     * Devuelve la cantidad de horas catedra de la materia
     */
    int getHorasCatedra();
    /**
     * Detecta si los horarios de la materia se superponen con los horarios de la materia pasada como parametro
     * @param materia Materia pasada por referencia
     * @return Devuelve true si las materias se superponen y false si no lo hacen
     */
    bool detectarSuperposicion(Materia &materia);
    /**
     * Crea una representación legible para e humano de los datos de la materia
     * @return String con los datos de la materia
    */
    std::string mostrarMateria();
};

#endif