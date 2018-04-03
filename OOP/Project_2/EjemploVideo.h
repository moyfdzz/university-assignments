//
// Created by Moises Fernandez on 3/2/18.
//

#ifndef PROYECTO2_EJEMPLOVIDEO_H
#define PROYECTO2_EJEMPLOVIDEO_H


#include "Fecha.h"
#include "Tema.h"
#include "Materia.h"
#include "Autor.h"

class EjemploVideo
{
public:
    EjemploVideo();

    int getIdVideo() { return idVideo; }
    int getIdTema() { return idTema; }
    int getCantidadAutores() { return cantidadAutores; }
    string getNombreEjemploVideo() { return nombreEjemploVideo; }
    Fecha getFechaElaboracion() { return fechaElaboracion; }

    int getListaAutores(int indiceLista) { return listaAutores[indiceLista]; }

    void setIdVideo(int idVid) { idVideo = idVid; }
    void setIdTema(int idTema) { this->idTema = idTema; }
    void setNombreEjemploVideo(string nomEVid) { nombreEjemploVideo = nomEVid; }
    void setFechaElaboracion(Fecha fechaElab) { fechaElaboracion = fechaElab; }

    bool agregaAutor(int idAut);

private:
    int idVideo, idTema, cantidadAutores, listaAutores[10];
    string nombreEjemploVideo;
    Fecha fechaElaboracion;
};

EjemploVideo::EjemploVideo()
{
    idVideo = 0;
    idTema = 0;
    cantidadAutores = 0;
    nombreEjemploVideo = "No asignado";
    fechaElaboracion.setFecha(1, 1, 2000);
}

bool EjemploVideo::agregaAutor(int idAut)
{
    if(cantidadAutores < 10)
    {
        for(int counter = 0; counter < cantidadAutores; counter++)
        {
            if(idAut == listaAutores[counter])
            {
                return false;
            }
        }
            listaAutores[cantidadAutores] = idAut;
            cantidadAutores++;
            return true;
    }
    else
    {
        return false;
    }

}

#endif //PROYECTO2_EJEMPLOVIDEO_H
