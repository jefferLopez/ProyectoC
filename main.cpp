#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#define archivo_csv "DatosIniciales.csv"
using namespace std;

int main()
{

    short int maxSize = 80;
    short int maxVector = 2;
    short int maxEleVector = 3;

    ifstream archivo(archivo_csv);
    string linea;
    char delimiter = ';';
    vector<vector<vector<float>>> data_vectores;
    vector<vector<float>> vectores;
    vector<float> vector;

    while (getline(archivo, linea))
    {
        if (data_vectores.size() < maxSize)
        {
            stringstream stream(linea);
            string x, y, z;

            getline(stream, x, delimiter);
            getline(stream, y, delimiter);
            getline(stream, z, delimiter);

            float x_float = stof(x);
            float y_float = stof(y);
            float z_float = stof(z);

            vector = {x_float, y_float, z_float};
            vectores.push_back(vector);

            if (vectores.size() == maxVector)
            {
                data_vectores.push_back(vectores);
                vectores.clear();
            }

            vector.clear();
        }
    }

    cout << "=======================" << endl;

    for (int i = 0; i < data_vectores.size(); i++)
    {
        cout << "vector:" << i + 1 << endl;
        for (int j = 0; j < data_vectores[i].size(); j++)
        {
            for (int k = 0; k < data_vectores[i][j].size(); k++)
            {
                cout << "valor: " << data_vectores[i][j][k];
                cout << endl;
            }
        }
    }

    archivo.close();
    system("PAUSE");
    return 0;
}