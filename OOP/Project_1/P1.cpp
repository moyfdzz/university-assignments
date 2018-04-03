/*
Moisés Fernández Zárate A01197049
Proyecto - Convertir de archivos cpp a HTML
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Variables globales de los archivos
ifstream cpp; 
ofstream html; 

void beginHTML(string fileName)
{
	html << "<!DOCTYPE html>" << "<html>" << "<head>" << endl;
	html << "<title>" << "Documentación del archivo: " << fileName << ".cpp" << "</title>" << "</head>";
	html << "<body>" << endl;
}

void closeHTML()
{
	html << "</body>" << "</html>" << endl;
}

void getInformation(string tag, string &tagType, string &tagContent)
{
	tagType = tag.substr(0, tag.find(" "));
	tagContent = tag.substr(tag.find(" ") + 1);
}

void createHeader(int headerSize, string tagType, string tagContent)
{
	html << "<h" << headerSize << ">" << "<hr>" << "<br>" << tagType << tagContent << "<br>" << "</h";
	html << headerSize << ">"; 
}

void makeBold(string tagType, string tagContent)
{
	html << "<strong>" << tagType << "</strong>" << tagContent << "</br>";
}

void transformDocumentation(string tag, string tagType, string tagContent)
{
	if (tagType == "progName")
	{
		createHeader(2, "Programa: ", tagContent);
	}
	else if (tagType == "author")
	{
		makeBold("Autor: ", tagContent);
	}
	else if (tagType == "date")
	{
		makeBold("Fecha de elaboración: ", tagContent);
	}
	else if (tagType == "funcName")
	{
		createHeader(3, "Función: ", tagContent);
	}
	else if (tagType == "desc")
	{
		makeBold("Descripción: ", tagContent);
	}
	else if (tagType == "return")
	{
		makeBold("Valor de retorno: ", tagContent);
	}
	else if (tagType == "param")
	{
		makeBold("Parámetros: ", tagContent);
	}
}

int main()
{
	string fileName, tagType, tagContent, documentation, tag;

	cout << "¿Cuál es el nombre del archivo? (sin extensión)" << endl;
	cin >> fileName;

	cpp.open(fileName + ".cpp");
	html.open(fileName + ".html");

	beginHTML(fileName);

	while (getline(cpp, documentation))
	{
		if(documentation == "/**")
		{
			getline(cpp, documentation);
			while(documentation != "*/")
			{
				tag = documentation.substr(documentation.find("@") + 1);
				getInformation(tag, tagType, tagContent);
				transformDocumentation(tag, tagType, tagContent);
				getline(cpp, documentation);
			}
		}
	}

	closeHTML();
	cpp.close();
	html.close();

	return 0;
}