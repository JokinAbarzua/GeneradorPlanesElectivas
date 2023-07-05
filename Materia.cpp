#include "Materia.h"
#include "Horario.h"
#include <string>
#include <stdexcept>

Materia::Materia(std::string nombre, int horasCatedra, Horario horario1, Horario horario2)
{
    this->setHorario(horario1, horario2);
    this->setHorasCatedra(horasCatedra);
    this->setNombre(nombre);
}
Materia::Materia(std::string nombre, int horasCatedra, Horario horario1)
{
    this->setHorario(horario1);
    this->setHorasCatedra(horasCatedra);
    this->setNombre(nombre);
}
Materia::Materia(Materia &&materia)
{
    this->horarios[0] = std::move(materia.horarios[0]);
    this->horarios[1] = std::move(materia.horarios[1]);
    this->nombre = std::move(materia.nombre);
    this->horasCatedra = materia.horasCatedra;
}
Materia::Materia(const Materia &materia)
{
    this->horarios[0] = materia.horarios[0];
    this->horarios[1] = materia.horarios[1];
    this->nombre = materia.nombre;
    this->horasCatedra = materia.horasCatedra;
}
void Materia::setHorario(Horario horario1, Horario horario2)
{
    if (horario1.getDiaSemana() == horario2.getDiaSemana())
    {
        throw std::runtime_error("Los 2 horarios deben ser de dias distintos");
    }
    else
    {
        this->horarios[0] = horario1;
        this->horarios[1] = horario2;
    }
}
void Materia::setHorario(Horario horario1)
{
    this->horarios[0] = horario1;
}
void Materia::setNombre(std::string nombre)
{
    if (nombre == "")
    {
        throw std::runtime_error("No puede ser nombre vacío");
    }
    else
    {
        this->nombre = nombre;
    }
}
void Materia::setHorasCatedra(int horasCatedra)
{
    if (horasCatedra <= 0)
    {
        throw std::runtime_error("Cantidad de horas catedra de la materia " + this->nombre + " invalida");
    }
    else
    {
        this->horasCatedra = horasCatedra;
    }
}

Horario *Materia::getHorarios()
{
    return this->horarios;
}
std::string Materia::getNombre()
{
    return this->nombre;
}
int Materia::getHorasCatedra()
{
    return this->horasCatedra;
}

bool Materia::detectarSuperposicion(Materia &materia)
{
    Horario *horariosMateria = materia.getHorarios();
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (horariosMateria[j].getDiaSemana() == Horario::UNDEF || this->horarios[i].getDiaSemana() == Horario::UNDEF)
            {
                continue;
            }
            if (this->horarios[i].getDiaSemana() != horariosMateria[j].getDiaSemana() || horariosMateria[j].getHoraFin() < this->horarios[i].getHoraInicio() + 15 || horariosMateria[j].getHoraInicio() + 15 > this->horarios[i].getHoraFin())
            {
                continue;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

std::string Materia::mostrarMateria()
{
    std::string horario1 = this->horarios[0].mostrarHorario();
    std::string horario2 = this->horarios[1].getDiaSemana() == Horario::UNDEF ? "" : horarios[1].mostrarHorario();
    return this->nombre + " " + horario1 + " " + horario2;
}