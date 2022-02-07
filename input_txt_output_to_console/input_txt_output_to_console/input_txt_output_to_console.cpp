#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    system("chcp 1251>nul");
    ifstream myFile_Handler;
    string myLine;
    char language;
    cout << "Enter the language(english(enter e) or russian(enter r) : ";
    cin >> language;
    myFile_Handler.open("C:\\git\\feeralbee_test\\input_txt_output_to_console\\Pushkin.txt");

    if (myFile_Handler.is_open())
    {
        switch (language)
        {
        case 'r':
            cout << "Файл открылся!" << endl;
            cout << endl;
            break;
        case 'e':
            cout << "File has opened!" << endl;
            cout << endl;
            break;
        }
        while (getline(myFile_Handler, myLine))
        {
            cout << myLine << endl;
        }
        myFile_Handler.close();
    }
    else
    {
        switch (language)
        {
        case'r':
            cout << "Файл не открылся!" << endl;
        case 'e':
            cout << "File has not opened!" << endl;
        }
    }
    return 0;
}
