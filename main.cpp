#include <iostream>
#include <dos.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <cstring>
#include <fstream>
#include <conio.h>
/*
Eduardo Rodriguez Marin
Codificador de cadenas a Morse
Computacion Tolerante a Fallos
Universidad de Guadalajara
*/

using namespace std;
string morse(char);
void playMusic(string);
void playImage(string);

/*Representa un punto*/
void dot()
{
    Beep(400, 300);
    cout << '.';
}
/*Representa un guin medio*/
void dash()
{
    Beep(500, 600);
    cout << '-';
    Sleep(1);
}

/*Representa a un punto en la pantalla*/
void dotImg(){
system("color F0");
cout<<'.';
Sleep(300);
system("color 0F");
Sleep(100);
}

/*Representa a un guion en la pantalla*/
void dashImg(){
system("color F0");
cout<<'-';
Sleep(600);
system("color 0F");
Sleep(100);
}

/*Reproduce la cadena codificada en la pantalla*/
void playImage(string cadenaMorse){
    int tam = cadenaMorse.length();
    for(int i = 0; i < tam; i++){
        if(cadenaMorse[i] == '.'){
            dotImg();
        }
        if(cadenaMorse[i] == '-'){
            dashImg();
        }
        if(cadenaMorse[i] == ' ') {
            Sleep(1000);
            cout << " ";
        }
    }
}

/*Reproduce la cadena codificada en sonido*/
void playMusic(string cadenaMorse){
    int tam = cadenaMorse.length();
    for(int i = 0; i < tam; i++){
        if(cadenaMorse[i] == '.'){
            dot();
        }
        if(cadenaMorse[i] == '-'){
            dash();
        }
        if(cadenaMorse[i] == ' ') {
            Sleep(1000);
            cout << " ";
        }
    }
}

/*Menu de la aplicacion*/
void principal(){
    string cadena = "";
    cin.sync();
    cout<< "Escribe la linea para traducir"<< endl;
    getline(cin, cadena, '\n');

    int tamCadena = cadena.length();
    string cadenaMorse;
    ofstream entrada;
    entrada.open("mensaje.txt");

    for(int i=0; i<tamCadena; i++) cadenaMorse += morse(cadena[i])+ " ";

    entrada << cadena << '\n' << cadenaMorse;
    entrada.close();

    //Elige la opcion que quiera
    int opc = 0;
    cout<<"Selecciona la opcion con la que deseas mostrar el resultado"<<endl;
    cout<<"1.- Reproduccion de sonido"<<endl;
    cout<<"2.- Reproduccion en pantalla"<<endl;
    cin>>opc;
    if(cin.fail())
        {
            cout<<"Opcion incorrecta"<<endl;
            cin.clear();
            cin.ignore(10, '\n');
            opc = 0;
        }
    switch(opc){
    case 1:
        cout << "Cadena resultante"<< endl;
        playMusic(cadenaMorse);
        break;
    case 2:
        cout << "Cadena resultante"<< endl;
        playImage(cadenaMorse);
        break;
    default:
        break;
    }
}

/*Diccionario Morse A-Z 0-9*/
string morse(char letra)
{
    switch(toupper(letra))
    {
        case 'A':
            return ".-";
            break;
        case'B':
            return "-...";
            break;
        case 'C':
            return "-.-.";
            break;
        case 'D':
            return "-..";
            break;
        case 'E':
            return ".";
            break;
        case'F':
            return "..-.";
            break;
        case 'G':
            return "--.";
            break;
        case 'H':
            return "....";
            break;
        case 'I':
            return "..";
            break;
        case'J':
            return ".---";
        case 'K':
            return "-.-";
            break;
        case 'L':
            return ".-..";
            break;
        case 'M':
            return "--";
            break;
        case 'O':
            return "---";
            break;
        case 'P':
            return ".--.";
            break;
        case 'Q':
            return "--.-";
            break;
        case'R':
            return ".-.";
            break;
        case 'S':
            return "...";
            break;
        case 'T':
            dash();
            return "-";
            break;
        case 'U':
            return "..-";
            break;
        case'V':
            return "...-";
            break;
        case 'W':
            return ".--";
            break;
        case 'X':
            return "-..-";
            break;
        case 'Y':
            return "-..-";
            break;
        case'Z':
            return "---.";
            break;

        case'0':
            return "-----";
            break;
        case'1':
            return ".----";
            break;
        case'2':
            return "..---";
            break;
        case'3':
            return "...--";
            break;
        case'4':
            return "....-";
            break;
        case'5':
            return ".....";
            break;
        case'6':
            return "-....";
            break;
        case'7':
            return "--...";
            break;
        case'8':
            return "---..";
            break;
        case'9':
            return "----.";
            break;
        case ' ':
            return " ";
            break;

        default:
            cout<<"Elemento no reconocido"<< endl;
    }
    return "";
}

int main()
{
    int opc = 0;
    principal();

    do{
    cout<<endl<<"Deseas salir del programa? Si -> 1 No->2"<<endl;
    cin >> opc;
    if(cin.fail())
        {
            cin.clear();
            cin.ignore(10, '\n');
        }
    else{
    switch(opc){
    case 1:
        break;
    case 2:
        principal();
        break;
    default:
        cout<<"Debe seleccionar una opcion correcta"<<endl;
        break;
        }
    }
    }while(opc != 1);
    return 0;
}
