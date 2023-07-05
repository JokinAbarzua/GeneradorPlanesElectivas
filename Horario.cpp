#include "Horario.h"
#include <stdexcept>

Horario::Horario(Horario::DiaSemana diaSemana, int horaInicio, int horaFin)
{
    this->diaSemana = diaSemana;
    if (horaInicio >= 24 * 60 || horaFin >= 24 * 60)
    {
        throw std::runtime_error("Error: Los horarios ingresados no corresponden a un valor valido");
    }
    if (horaInicio >= horaFin)
    {
        throw std::runtime_error("Error: La hora de inicio no puede ser mayor que la hora de fin");
    }
    this->horaInicio = horaInicio;
    this->horaFin = horaFin;
}
Horario::Horario(Horario &horario)
{
    this->diaSemana = horario.getDiaSemana();
    this->horaInicio = horario.getHoraInicio();
    this->horaFin = horario.getHoraFin();
}
Horario::Horario()
{
    this->horaInicio = 0;
    this->horaFin = 0;
    this->diaSemana = UNDEF;
}
int Horario::getHoraInicio()
{
    return this->horaInicio;
};
int Horario::getHoraFin()
{
    return this->horaFin;
};
Horario::DiaSemana Horario::getDiaSemana()
{
    return this->diaSemana;
}
std::string Horario::mostrarHorario()
{
    std::string dia;
    switch (this->diaSemana)
    {
    case LUNES:
        dia = "LUNES";
        break;
    case MARTES:
        dia = "MARTES";
        break;
    case MIERCOLES:
        dia = "MIERCOLES";
        break;
    case JUEVES:
        dia = "JUEVES";
        break;
    case VIERNES:
        dia = "VIERNES";
        break;
    default:
        dia = "UNDEF";
        break;
    }
    if (dia == "UNDEF")
    {
        return dia;
    }
    else
    {
        dia = dia + " de " + std::to_string(this->horaInicio / 60) + ":" 
        + std::to_string(this->horaInicio % 60) + " a " + std::to_string(this->horaFin / 60) 
        + ":" + std::to_string(this->horaFin % 60);
        return dia;
    }
}
