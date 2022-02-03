#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    system("chcp 1251>nul");
    ifstream myFile_Handler;
    string myLine;
//    char language;
//    cout << "Enter the language(en or ru): ";
//    cin >> language;
    myFile_Handler.open("C:\\git\\feeralbee_test\\input_txt_output_to_console\\cppstudio.txt");

    if (myFile_Handler.is_open())
    {
        /*switch (language)
        {
        case'ru':
            cout << "Файл открылся!" << endl;
        case 'en':
            cout << "File has opened!" << endl;
        }*/
        while (getline(myFile_Handler, myLine))
        {

            cout << myLine << endl;
        }
        myFile_Handler.close();
    }
    else
    {
       /* switch (language)
        {
        case'ru':
            cout << "Файл не открылся!" << endl;
        case 'en':*/
            cout << "File has not opened!" << endl;
        
    }
    return 0;
}








/*#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");
	char a;
	ifstream F;
	F.open("C:\\git\\feeralbee_test\\input_txt_output_to_console\\cppstudio.txt");
	if (F)
	{
		while (!F.eof())
		{
			F >> a;
			cout << a;
		}
		F.close();
	}
	else cout << "File hadn't found" << endl;
	return 0;
}
*/