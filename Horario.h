#ifndef HORARIO_H
#define HORARIO_H
#include <string>
class Horario{
    public:
    /**
     *  Enum que representa los dias de la semana de LUNES a SABADO o UNDEF para un dia vacío
    */
        enum DiaSemana{ LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, UNDEF};
    private:
        DiaSemana diaSemana;
        int horaInicio;
        int horaFin;

    public:
        /**
         * Constructor completo
         * @param diaSemana Del tipo enum DiaSemana, puede ser Lunes, Martes.... Sabado o UNDEF para un dia vacío
         * @param horaInicio Representa los minutos desde las 00hs en el que inicia el horario y se debe pasar como minutos dejando el calculo necesario al que haa uso de la clase. Por ejemplo 17:30hs = 17 * 60 + 30
         * @param horaFin Representa los minutos desde las 00hs en el que finaliza el horario y se debe pasar como minutos dejando el calculo necesario al que haa uso de la clase. Por ejemplo 22:30hs = 22 * 60 + 30
        */
        Horario(DiaSemana diaSemana, int horaInicio,int horaFin);
        /**
         * Contructor de Copia
         * @param horario Objeto horario a ser copiado
        */
        Horario(Horario &horario);
        /**
         * Constructor vacío. Establece el diaSemana como UNDEF y los horarios en 0
        */
        Horario();        
        int getHoraInicio();
        int getHoraFin();
        DiaSemana getDiaSemana();
        /**
         * Crea una representación legible para el humano del horario en formato DIA de hh:mm a hh:mm
         * @return string con la representacion del horario
        */
        std::string mostrarHorario();
};

#endif