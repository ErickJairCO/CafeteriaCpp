#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fstream>
using namespace std;
void factura();
int main ();

struct supermercado
{

int cant;
double precio;
string nombre_p;
}

super[10];
char name[75];
ofstream entrada;
ofstream entrada1;
ifstream entrada2("ProductosSuperFeo.txt");

float totalv = 0;
double totalar = 0;
double total = 0, isv = 0;
char resp;
int j=0;
int resp2=1;
int conj=0;
void registrar()
{

float totalv = 0;
double totalar = 0;
double total = 0, isv = 0;
string nomb;
int cod;

int i=0;
int j=0;

int cant1=0;
int cant11=0;
cout << "Ingrese cuantos articulos desea comprar(que no exceda de 10 articulos): ";
cin >> resp2;
if (resp2>=11)
{
system("cls");
cout << "Error, cantidad excedida de articulos\nGracias por preferirnos";
main();
}
else
{

for(i=0; i<=resp2;i++)
{
do
{
cout << "Ingrese el codigo de articulo: " << endl;
cin>>cod;

switch(cod)
{

case 1: super[i].nombre_p="Cafe Mexicano";
entrada << "Nombre producto: " <<super[i].nombre_p ;
super[i].precio=25;

do{

cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;

if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;

}while(super[i].cant>resp2);

entrada << "cantidad " << super[i].cant << endl;
entrada1 << super[i].cant << " ";

break;
case 2: super[i].nombre_p="Cafe Colombiano";
entrada << "Nombre producto: " <<super[i].nombre_p;
super[i].precio=28;
do{

cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;

if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;

}while(super[i].cant>resp2);

break;
case 3: super[i].nombre_p="Cafe Descafeinado";
entrada << "Nombre producto: " <<super[i].nombre_p;
super[i].precio=26;
do{

cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;

if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;

}while(super[i].cant>resp2);
break;
case 4: super[i].nombre_p="Crepa ";
entrada << "Nombre producto: " <<super[i].nombre_p;
super[i].precio=30;
do{

cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;

if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;

}while(super[i].cant>resp2);
break;
case 5: super[i].nombre_p="Pastel Imposible";
entrada << "Nombre producto: " <<super[i].nombre_p;
super[i].precio=35;
do{

cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;

if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;

}while(super[i].cant>resp2);
break;
case 6: super[i].nombre_p="Pastel de Zanahoria";
entrada << "Nombre producto: " <<super[i].nombre_p;
super[i].precio=30;
do{

cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;

if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;

}while(super[i].cant>resp2);
break;
case 7: super[i].nombre_p="Pastel de Vainilla";

entrada << "Nombre producto: " <<super[i].nombre_p;
super[i].precio=25;
do{

cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;

if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;

}while(super[i].cant>resp2);
break;
case 8: super[i].nombre_p="Pastel de Chocolate";
entrada << "Nombre producto: " <<super[i].nombre_p;
super[i].precio=35;
do{

cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;

if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;

}while(super[i].cant>resp2);
break;
case 9: super[i].nombre_p="Pastel Mil hojas";
entrada << "Nombre producto: " <<super[i].nombre_p;
super[i].precio=25;
do{

cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;

if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;

}while(super[i].cant>resp2);
break;

case 10: super[i].nombre_p="Pieza de pan";
entrada << "Nombre producto: " <<super[i].nombre_p;
super[i].precio=8;
do{

cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;


if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;

}while(super[i].cant>resp2);
break;
default:cout<<"Solo existen articulos del 1-10"<<endl;
break;
}
}while(cod>10);

conj++;
j=super[i].cant+j;
if(j>=resp2)
{
i=11;

factura();
}
}
}
}

void factura()
{

float totalv = 0;
double totalar = 0;
double total = 0, isv = 0;

system("cls");
cout << "\t------------------Stark Coffe---------------\t" << endl;
cout << "\t-------------------Factura---------------------------------\t" << endl;
cout << "Nombre: " << name << endl;

cout << "Cant/Arti " << "\t " << "Nom/Art" << " \t " << " Precio " << endl;

for(int i=0; i<=conj-1;i++)

{

cout << super[i].cant << " \t " << super[i].nombre_p << " \t " << super[i].precio << endl;
totalv = totalv + (super[i].precio * super[i].cant);
totalar = totalar + super[i].cant;
isv = isv + totalv*0.15;
total = totalv + isv;
}

entrada << "Total " << total << " " << endl;
entrada1 << total << " ";
entrada << "**************************" << endl;
cout << "---------------------------------------------------" << endl;
cout << "Subtotal: " << totalv << endl;
cout << "Impuesto: " << isv << endl;
cout << "Total de articulos vendidos: " << totalar << endl;
cout << "Total: " << total << endl;

system("PAUSE");
entrada.close();
do
{
system("cls");
cout<<"Desea ingresa otra compra "<<endl;
cin>>resp;
resp=toupper(resp);
if(resp=='S')
{

resp2=0;
j=0;
conj=0;
main();
}
}while(resp=='S');
}

int main()
{

entrada.open("ProductosSuper.txt", ios::out | ios::app);
entrada1.open("ProductosSuperFeo.txt", ios::out | ios::app);
if ((entrada.fail()) && (entrada1.fail()))
{
cout << "ERROR AL ABRIR EL ARCHIVO" << "\n";
}
else
{
cout << "\t\t\t\t Bienvenido al cafe Stark Coffee \n" << endl;
cout << "Para finalizar ingrese 0" << endl;
cout << "Ingrese nombre: " << endl;
cin >> name;
entrada << " Nombre factura: " << name << " ";
entrada1 << name << " ";
registrar();

return 0;
}
}
