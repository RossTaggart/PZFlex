#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <iterator>

using namespace std;

//method which reads the .bat file and stores it
//in floats
float** readFile(string filename, int rows, int columns)
{
	//opens file stream
	fstream file;
	file.open(filename.c_str(), ios::in);
	if (!file.is_open())
	{
		return 0;
	}

	//creates floats
	float** floats = new float*[columns + 1];
	for (int i = 0; i < columns; i++)
	{
		floats[i] = new float[rows + 1];
	}

	//adds each found element in the file to the flaots;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			file >> floats[j][i];
		}
	}
	file.close();
	return floats;
}

//method which takes the vectors containing the floats and writes them to a text file
void writeFile(vector<float> amplitudes, vector<float> phases)
{
	ofstream out("output.txt");
	auto i = amplitudes.begin();
	auto j = phases.begin();

	for (auto i = amplitudes.begin(); i != amplitudes.end(); i++)
	{
		out << *i << "\t" << *j << "\n";
		j++;
	}
	out.close();
	cout << "\nFile written successfully.";

}

//method to calculate the amplitude of the complex number
float calcAmplitude(float f1, float f2)
{
	return sqrt(pow(f1, 2.0) + pow(f2, 2.0));
}

//method to calculate the phase of the complex number
float calcPhase(float f1, float f2)
{
	return (atan2(f2, f1) * 180 / 3.14159265);
}

//main method
int main()
{
	int rows = 128;
	int columns = 2;
	float** floatsFromInput;
	float f1 = 0.0f;
	float f2 = 0.0f;
	float** floatsForOutput;
	vector<float> amplitudes;
	vector<float> phases;

	//calls the readfile method
	if (!(floatsFromInput = readFile("inputc.dat", rows, columns)))
	{
		return 0;
	}

	int i;
	int j;

	for (i=0; i < rows; i++)
	{
		for (j=0; j < columns; j++)
		{
			//outputs data to screen...shows file has been read
			cout << floatsFromInput[j][i] << "\t";
		}
		
		//pulls the floats
		f1 = floatsFromInput[j-2][i];
		f2 = floatsFromInput[j-1][i];
		cout << "\n";
		
		//calculates the amplitude and phase of each complex number
		float amplitude = calcAmplitude(f1, f2);
		float phase = calcPhase(f1, f2);

		//adds them to the relevant vectors
		amplitudes.push_back(amplitude);
		phases.push_back(phase);
	}

	//calls the writeFile method
	writeFile(amplitudes, phases);
	int in;
	cin >> in;
}