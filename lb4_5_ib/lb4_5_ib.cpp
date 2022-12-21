#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int N = 33;
const int M = 100;


int main()
{
    /*char string2[11] = "A nice cat";
    char key2[11] = "ABCDEFGHIJ";
    for (int x = 0; x < 10; x++)
    {
        string2[x] = string2[x] ^ key2[x];
        cout << string2[x];
    }
    cout << endl << "------------------\n";
    for (int i = 0; i < 10;i++)
    {
        string2[i] = string2[i] ^ key2[i];
        cout << string2[i];

    }
    cout << endl << "------------------\n";*/

    string pathOut = "C:\\Users\\Owl\\source\\repos\\files\\output.txt";
    string pathIn = "C:\\Users\\Owl\\source\\repos\\files\\input.txt";
    string pathResult = "C:\\Users\\Owl\\source\\repos\\files\\result.txt";
    string pathKey = "C:\\Users\\Owl\\source\\repos\\files\\keyN.txt";
    setlocale(LC_ALL, "Rus");

    //char key[N]{ 'А','Б','В','Г','Д','Е','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ','Ы','Ь','Э','Ю','Я' };
    //алфавит
    char key[N] = "";
    int l = 0;
    std::ifstream filek(pathIn, std::ifstream::binary);
    if (filek) {
        filek.seekg(0, filek.end);
        l = filek.tellg();
        filek.seekg(0, filek.beg);
        char* arr = new char[l];
        filek.read(arr, l);
        filek.close();
        std::cout.write(arr, l);
        for (int i = 0; i < l; i++) {
            key[i] = arr[i];
        }
        delete[] arr;
    }
    else { cout << "ERROR"; }
    cout << endl;


    //считывание
    char txt[M]{};
    int length = 0;
    //cout << "Txt from file: ";
    std::ifstream file(pathIn, std::ifstream::binary);
    if (file) {
        file.seekg(0, file.end);
        length = file.tellg();
        file.seekg(0, file.beg);
        char* arr = new char[length];
        file.read(arr, length);
        file.close();
        //std::cout.write(arr, length);
        for (int i = 0; i < length; i++) {
            txt[i] = arr[i];
        }
        delete[] arr;
    }
    else { cout << "ERROR"; }
    cout << endl;

    //перевод в верхний регистр
    for (int t = 0; t < length; t++)
    {
        txt[t] = toupper(txt[t]);
    }

    int counter = 0;
    cout << "First txt: "; //вывод

    for (int y = 0; y < length; y++)
    {
        cout << txt[y];
    }
    cout << endl;

    //шифрование
    char out[M]{};

    for (int i = 0;i < length;i++)
    {
        out[i] = (txt[i] ^ key[i]);
        cout<<"out[] = "<<out[i] << " txt = " << txt[i] << " key[i]" << key[i] << endl;
    }

    cout << "Cypher: ";
    for (int r = 0; r < length; r++)
    {
        cout << out[r];
    }

    std::ofstream outq;
    outq.open(pathOut);
    if (outq.is_open())
    {
        outq << out;
    }
    else { cout << "ERROR " << endl; }

    //считывание дл€ дешифрации
    cout<<endl << "text from out.txt:" << endl;
    char outD[M]{};
    int length2 = 0;
    ifstream file2(pathOut);
    if (file2) {
        file2.seekg(0, file2.end);
        length2 = file2.tellg();
        file2.seekg(0, file2.beg);
        char* arr2 = new char[length2];
        file2.read(arr2, length2);
        file2.close();
        for (int i = 0; i < length2; i++) {
            outD[i] = arr2[i];
            cout << outD[i];
        }
        delete[] arr2;
    }
    else { cout << "ERROR"; }

    //дешифрация

    char qout[M]{};

    for (int i = 0;i < length;i++)
    {
        qout[i] = out[i] ^ key[i];
    }

    cout << endl << "Decypher: ";
    for (int r = 0; r < length; r++)
    {
        cout << qout[r];
    }
    cout << endl << "Decypher toLower: ";
    for (int i = 0; i < length; i++)
    {

        qout[i] = tolower(qout[i]);
        cout << qout[i];
    }

    std::ofstream out2;
    out2.open(pathResult);

    if (out2.is_open())
    {
        out2 << qout;
    }
    else { cout << "ERROR " << endl; }
    cout << endl;
}