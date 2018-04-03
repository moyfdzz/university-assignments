#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string rowResults;
	ifstream results("resultados.txt");
	ofstream averages("promedios.txt");

	while (getline(results, rowResults))
	{
		double average = 0;
		int numbers = 0;
		
		for (int counter = 0; counter < rowResults.length(); counter++)
		{
			if(rowResults[counter] != ' ')
			{
				average += rowResults[counter] - 48;
				numbers++;
			}
		}
		average /= numbers;
		averages << average << endl;
	}

	results.close();
	averages.close();
}