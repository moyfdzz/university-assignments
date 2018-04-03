#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#include "EjemploVideo.h"

Materia materias[5];
Tema temas[10];
Autor autores[10];
EjemploVideo eVideos[20];
int cantidadTemasG = 0, cantidadAutoresG = 0, cantidadMateriasG = 0, cantidadEVideosG = 0;

void cargarDatosMaterias()
{
    string nombreArchivo, extensionArchivo;
    cout << "Ingrese el nombre del archivo de las materias" << endl;
    cin >> nombreArchivo;

    extensionArchivo = nombreArchivo + ".txt";

    ifstream listaMaterias;
    listaMaterias.open(extensionArchivo);

    int cveMateria;
    string nombreMateria;

    while(listaMaterias >> cveMateria && getline(listaMaterias, nombreMateria))
    {
        materias[cantidadMateriasG].setIdMateria(cveMateria);
        materias[cantidadMateriasG].setNombreMateria(nombreMateria);
        cantidadMateriasG++;
    }

    listaMaterias.close();
}

void cargarDatosTemas()
{
    string nombreArchivo, extensionArchivo;
    cout << "Ingrese el nombre del archivo de los temas" << endl;
    cin >> nombreArchivo;

    extensionArchivo = nombreArchivo + ".txt";

    ifstream listaTemas;
    listaTemas.open(extensionArchivo);

    int idTema, idMateria;
    string nombreTema;

    while(listaTemas >> idTema >> idMateria && getline(listaTemas, nombreTema))
    {
        temas[cantidadTemasG].setIdTema(idTema);
        temas[cantidadTemasG].setIdMateria(idMateria);
        temas[cantidadTemasG].setNombreTema(nombreTema);
        cantidadTemasG++;
    }

    listaTemas.close();
}

void cargarDatosAutores()
{
    string nombreArchivo, extensionArchivo;
    cout << "Ingrese el nombre del archivo de los autores" << endl;
    cin >> nombreArchivo;

    extensionArchivo = nombreArchivo + ".txt";

    ifstream listaAutores;
    listaAutores.open(extensionArchivo);

    int idAutor;
    string nombreAutor;

    while(listaAutores >> idAutor && getline(listaAutores, nombreAutor))
    {
        autores[cantidadAutoresG].setIdAutor(idAutor);
        autores[cantidadAutoresG].setNombreAutor(nombreAutor);
        cantidadAutoresG++;
    }

    listaAutores.close();
}

void checarIdAutor(int numAutores, bool &idAutorExiste, int idAutor)
{
    for (int counter2 = 0; counter2 < cantidadAutoresG; ++counter2)
    {
        if (autores[counter2].getIdAutor() == idAutor)
        {
            idAutorExiste = true;
            break;
        }
        else
        {
            idAutorExiste = false;
        }

    }
}

void checarIdTema(int idTema, bool &idTemaExiste)
{
    for(int counter = 0; counter < cantidadTemasG; counter++)
    {
        if(idTema != temas[counter].getIdTema())
        {
            idTemaExiste = false;
        }
        else
        {
            idTemaExiste = true;
            break;
        }
    }
}

void checarIdMateria(int idMateria, bool &idMateriaExiste)
{
    for(int counter = 0; counter < cantidadTemasG; counter++)
    {
        if(idMateria != materias[counter].getIdMateria())
        {
            idMateriaExiste = false;
        }
        else
        {
            idMateriaExiste = true;
            break;
        }
    }
}

void cargarDatosEVideos()
{
    string nombreArchivo, extensionArchivo;
    cout << "Ingrese el nombre del archivo de los ejemplo videos" << endl;
    cin >> nombreArchivo;

    extensionArchivo = nombreArchivo + ".txt";

    ifstream listaEVideos;
    listaEVideos.open(extensionArchivo);

    int idVideo, idTema, dia, mes, anio, numAutores, idAutor;
    Fecha fechaElaboracion;
    string nombreEVideo;
    bool idTemaExiste = true, idAutorExiste = true;

    while(listaEVideos >> idVideo >> nombreEVideo >> idTema >> dia >> mes >> anio >> numAutores)
    {

        cout << "Agregando video" << endl;
        int posAutores[numAutores];

        for (int counter = 0; counter < numAutores; ++counter)
        {

            listaEVideos >> idAutor;
            checarIdAutor(numAutores, idAutorExiste, idAutor);

            if(!idAutorExiste)
            {
                break;
            }

            posAutores[counter] = idAutor;
        }

        checarIdTema(idTema, idTemaExiste);

        cout << idAutorExiste << idTemaExiste << endl;

        if (idAutorExiste && idTemaExiste)
        {
            fechaElaboracion.setFecha(dia, mes, anio);
            eVideos[cantidadEVideosG].setIdVideo(idVideo);
            eVideos[cantidadEVideosG].setNombreEjemploVideo(nombreEVideo);
            eVideos[cantidadEVideosG].setIdTema(idTema);
            eVideos[cantidadEVideosG].setFechaElaboracion(fechaElaboracion);

            for (int counter = 0; counter < numAutores; ++counter)
            {
                if (!eVideos[cantidadEVideosG].agregaAutor(posAutores[counter]))
                {
                    cout << "El id del autor del video número " << posAutores[counter] << " es inválido." << endl;
                }
            }

            cout << eVideos[cantidadEVideosG].getNombreEjemploVideo() << endl;
            cantidadEVideosG++;
            cout << "Sumando a cantidad videos" << endl;

        }
        else
        {
            cout << "El video " << nombreEVideo << " tiene el o los id(s) del autor o del tema mal por ";
            cout << "lo que no fue contado." << endl;
        }

        cout << endl << endl;
    }

    listaEVideos.close();
}

void mostrarMaterias()
{
    cout << endl << "Materias" << endl;
    cout << endl << "ID Materia   Nombre Materia" << endl;
    for(int counter = 0; counter < cantidadMateriasG; counter++)
    {
        cout << "   " << materias[counter].getIdMateria();
        cout << "      " << materias[counter].getNombreMateria() << endl;
    }

    cout << endl;
}

void mostrarTemas()
{
    cout << "Temas" << endl;
    cout << endl << "ID Tema   ID Materia   Nombre Tema" << endl;
    for(int counter = 0; counter < cantidadTemasG; counter++)
    {
        cout << "  " << temas[counter].getIdTema();
        cout << "        " << temas[counter].getIdMateria() << " ";
        cout << "    " << temas[counter].getNombreTema() << endl;
    }

    cout << endl;
}

void mostrarAutores()
{
    cout << "Autores" << endl;
    cout << endl << "ID Autor   Nombre Autor" << endl;
    for(int counter = 0; counter < cantidadAutoresG; counter++)
    {
        cout << "   " << autores[counter].getIdAutor() << " ";
        cout << "    " << autores[counter].getNombreAutor() << endl;
    }

    cout << endl;
}

void checarIdVideo(bool &idVideoExiste, int idVideo)
{
    for (int counter = 0; counter < cantidadEVideosG; ++counter)
    {
        if (idVideo == eVideos[counter].getIdVideo())
        {
            cout << "Este id se repite: " << idVideo << endl;
            idVideoExiste = false;
            break;
        }
        else
        {
            idVideoExiste = true;
        }
    }
}

void checarCantAutores(bool &cantAutoresPosible, int numAutoresUsuario)
{
    if (numAutoresUsuario < 1 || numAutoresUsuario > 10)
    {
        cantAutoresPosible = false;
    }
    else
    {
        cantAutoresPosible = true;
    }
}

void agregarEVideos()
{
    int idVideo, idTema, dia, mes, anio, numAutoresUsuario, idAutor;
    Fecha fechaElaboracion;
    string nombreEVideo;
    bool idTemaExiste = true, idAutorExiste = true, idVideoExiste = true, cantAutoresPosible = true;

    cout << "Ingrese el id del video" << endl;
    cin >> idVideo;

    checarIdVideo(idVideoExiste, idVideo);

    while(!idVideoExiste)
    {
        cout << "El id de video existe. Por favor ingrese uno diferente." << endl;
        cin >> idVideo;
        checarIdVideo(idVideoExiste, idVideo);
    }
    cin.ignore();

    eVideos[cantidadEVideosG].setIdVideo(idVideo);

    cout << "Ingrese el nombre del video" << endl;
    getline(cin, nombreEVideo);

    eVideos[cantidadEVideosG].setNombreEjemploVideo(nombreEVideo);

    cout << "Ingrese el id del tema" << endl;
    cin >> idTema;

    checarIdTema(idTema, idTemaExiste);

    while(!idTemaExiste)
    {
        cout << "El id del tema no es válido. Vuelva a ingresarlo" << endl;
        cin >> idTema;

        checarIdTema(idTema, idTemaExiste);
    }

    eVideos[cantidadEVideosG].setIdTema(idTema);

    cout << "Ingrese el día en el que el video fue elaborado" << endl;
    cin >> dia;

    cout << "Ingrese el mes en el que el video fue elaborado (número)" << endl;
    cin >> mes;

    cout << "Ingrese el año en el que el video fue elaborado" << endl;
    cin >> anio;

    fechaElaboracion.setFecha(dia, mes, anio);

    eVideos[cantidadEVideosG].setFechaElaboracion(fechaElaboracion);

    cout << "Ingrese la cantidad de autores del video" << endl;
    cin >> numAutoresUsuario;
    checarCantAutores(cantAutoresPosible, numAutoresUsuario);

    while(!cantAutoresPosible)
    {
        cout << "La cantidad de autores debe ser entre 1 y 10. Por favor vuelva a ingresarla" << endl;
        cin >> numAutoresUsuario;

        checarCantAutores(cantAutoresPosible, numAutoresUsuario);
    }

    for (int counter = 0; counter < numAutoresUsuario; counter++)
    {
        cout << "Introduzca el id del autor número " << counter + 1 << endl;


        do
        {
            cin >> idAutor;
            checarIdAutor(numAutoresUsuario, idAutorExiste, idAutor);

            if (!idAutorExiste)
            {
                cout << "El id del autor no existe. Por favor vuelva a ingresarlo" << endl;

            }
            else
            {
                idAutorExiste = eVideos[cantidadEVideosG].agregaAutor(idAutor);

                if(!idAutorExiste)
                {
                    cout << "El id del autor ya ha sido ingresado. Por favor introduzca otro" << endl;

                }
                else
                {
                    cout << "Autor agregado cantidad: " << eVideos[cantidadEVideosG].getCantidadAutores() << endl;
                }
            }
        }while(!idAutorExiste);
    }
    cantidadEVideosG++;
}

void buscarPorTema()
{
    int idTema;
    bool idTemaExiste = true;
    cout << "¿Cuál es el id del tema?" << endl;
    cin >> idTema;

    checarIdTema(idTema, idTemaExiste);

    while(!idTemaExiste)
    {
        cout << "El id del tema que ingresó es inválido. Por favor vuelva a ingresarlo" << endl;
        cin >> idTema;
        checarIdTema(idTema, idTemaExiste);
    }

    if(idTemaExiste)
    {
        cout << "Los datos de los videos con el id del tema " << idTema << " son los siguientes:" << endl;

        for(int counter = 0; counter < cantidadEVideosG; counter++)
        {
            if(idTema == eVideos[counter].getIdTema())
            {
                cout << "ID del video: " << eVideos[counter].getIdVideo() << endl;
                cout << "Nombre del video: " << eVideos[counter].getNombreEjemploVideo() << endl;
                cout << "Tema del video: ";

                for(int counter2 = 0; counter2 < cantidadEVideosG; counter2++)
                {
                    if(idTema == eVideos[counter].getIdTema())
                    {
                        cout << temas[counter2].getNombreTema() << endl;
                        break;
                    }
                }

                cout << "Fecha de elaboración: ";
                cout << eVideos[counter].getFechaElaboracion().getDd() << ".";
                cout << eVideos[counter].getFechaElaboracion().getMm() << ".";
                cout << eVideos[counter].getFechaElaboracion().getAa();

                cout << endl << "Autor(es):" << endl;

                for(int counter2 = 0; counter2 < eVideos[counter].getCantidadAutores(); counter2++)
                {
                    for(int counter3 = 0; counter3 < cantidadAutoresG; counter3++)
                    {
                        if(eVideos[counter].getListaAutores(counter2) == autores[counter3].getIdAutor())
                        {
                            cout << "  - " << autores[counter3].getNombreAutor() << endl;
                        }
                    }
                }
                cout << endl;
            }
        }
    }
}

void buscarPorMateria()
{
    int idMateria;
    bool idMateriaExiste = true;
    cout << "Ingrese el id de la materia" << endl;
    cin >> idMateria;

    checarIdMateria(idMateria, idMateriaExiste);

    while(!idMateriaExiste)
    {
        cout << "El id de la materia que ingresó es inválido. Por favor vuelva a ingresarlo" << endl;
        cin >> idMateria;
        checarIdMateria(idMateria, idMateriaExiste);
    }

    if(idMateriaExiste)
    {
        cout << "Los datos de los videos con el id de la materia " << idMateria << " son los siguientes:" << endl;

        for(int counter = 0; counter < cantidadTemasG; counter++)
        {
            if(idMateria == temas[counter].getIdMateria())
            {
                for (int counter2 = 0; counter2 < cantidadEVideosG; ++counter2)
                {
                    if (temas[counter].getIdTema() == eVideos[counter2].getIdTema())
                    {
                        cout << "ID del video: " << eVideos[counter2].getIdVideo() << endl;
                        cout << "Nombre del video: " << eVideos[counter2].getNombreEjemploVideo() << endl;
                        cout << "ID del tema: " << eVideos[counter2].getIdTema() << endl;
                        cout << "Fecha de elaboración: ";
                        cout << eVideos[counter2].getFechaElaboracion().getDd() << ".";
                        cout << eVideos[counter2].getFechaElaboracion().getMm() << ".";
                        cout << eVideos[counter2].getFechaElaboracion().getAa();

                        cout << endl << "Autor(es):" << endl;

                        for(int counter3 = 0; counter3 < eVideos[counter].getCantidadAutores(); counter3++)
                        {
                            for(int counter4 = 0; counter4 < cantidadAutoresG; counter4++)
                            {
                                if(eVideos[counter2].getListaAutores(counter3) == autores[counter4].getIdAutor())
                                {
                                    cout << "  - " << autores[counter4].getNombreAutor() << endl;
                                }
                            }
                        }
                        cout << endl;
                    }
                }


            }
        }
    }
}

void consultarVideos()
{
    int counterTemporal, dia, mes, anio;

    cout << endl << "Videos" << endl << endl;

    for (int counter = 0; counter < cantidadEVideosG; ++counter)
    {
        cout << "Id del video: " << eVideos[counter].getIdVideo() << endl;
        cout << "Nombre del video: " << eVideos[counter].getNombreEjemploVideo() << endl;
        cout << "Tema: ";

        for (int counter2 = 0; counter2 < cantidadTemasG; ++counter2)
        {
            if (temas[counter2].getIdTema() == eVideos[counter].getIdTema())
            {
                cout << temas[counter2].getNombreTema() << endl;
                counterTemporal = counter2;
                break;
            }
        }

        cout << "Materia: ";

        for (int counter2 = 0; counter2 < cantidadMateriasG; ++counter2)
        {
            if (materias[counter2].getIdMateria() == temas[counterTemporal].getIdMateria())
            {
                cout << materias[counter2].getNombreMateria() << endl;
                break;
            }
        }

        dia = eVideos[counter].getFechaElaboracion().getDd();
        mes = eVideos[counter].getFechaElaboracion().getMm();
        anio = eVideos[counter].getFechaElaboracion().getAa();

        cout << "Fecha de Elaboracion: " << dia << "." << mes << "." << anio << endl;

        cout << "Autor(es): " << endl;

        for (int iCounter2 = 0; iCounter2 < eVideos[counter].getCantidadAutores(); ++iCounter2)
        {
            for (int iCounter3 = 0; iCounter3 < cantidadAutoresG; ++iCounter3)
            {
                if (eVideos[counter].getListaAutores(iCounter2) == autores[iCounter3].getIdAutor())
                {
                    cout << "  - " << autores[iCounter3].getNombreAutor() << endl;

                }
            }
        }
        cout << endl;
    }
}

void buscarPorAutor()
{
    int idAutor;
    bool idAutorExiste = false;

    cout << "Introduce el id del autor" << endl;
    cin >> idAutor;
    checarIdAutor(cantidadAutoresG, idAutorExiste, idAutor);

    while(!idAutorExiste)
    {
        cout << "El id del autor es inválido. Por favor introdzque uno correcto" << endl;
        cin >> idAutor;
        checarIdAutor(cantidadAutoresG, idAutorExiste, idAutor);
    }

    cout << endl << "Videos" << endl;

    for (int iCounter = 0; iCounter < cantidadEVideosG; ++iCounter)
    {
        for (int iCounter2 = 0; iCounter2 < eVideos[iCounter].getCantidadAutores(); ++iCounter2)
        {
            if (eVideos[iCounter].getListaAutores(iCounter2) == idAutor)
            {
                cout << "Id del video: " << eVideos[iCounter].getIdVideo() << endl;
                cout << "Nombre del video: " << eVideos[iCounter].getNombreEjemploVideo() << endl;
                break;
            }
        }

        cout << endl;
    }
}

void menu(char &opcion)
{
    do
    {
        cout << endl << "M E N U " << endl;
        cout << "a. consultar información de materias, temas y autores" << endl;
        cout << "b. dar de alta videos de ejemplo" << endl;
        cout << "c. consultar la lista de videos por tema" << endl;
        cout << "d. consultar la lista de videos por materia" << endl;
        cout << "e. consultar lista de videos" << endl;
        cout << "f. consultar videos por autor" << endl;
        cout << "g. terminar" << endl;
        cout << "Opcion -> ";
        cin >> opcion;

        switch (opcion) {
            case 'a':
                mostrarMaterias();
                mostrarTemas();
                mostrarAutores();

                break;

            case 'b':
                agregarEVideos();

                break;
            case 'c':
                buscarPorTema();

                break;
            case 'd':
                buscarPorMateria();

                break;
            case 'e':
                consultarVideos();

                break;
            case 'f':
                buscarPorAutor();

                break;
        }

    } while (opcion != 'g');
}

//meter los ifstreams a cada función de cargar datos
int main()
{
    char opcion;

    cargarDatosMaterias();
    cargarDatosTemas();
    cargarDatosAutores();
    cargarDatosEVideos();

    menu(opcion);

    cantidadEVideosG++;

    return 0;
}