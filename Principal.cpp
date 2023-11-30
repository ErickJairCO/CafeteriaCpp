#include <stdio.h>
#include<stdlib.h>
#include <iostream>
#include <conio.h>

using namespace std;


void pausa();

int main (void){
	int menu;
	bool bandera = false;
	
do{

	system("cls");
	printf("\t\t\t\t\t-------->Bienvenido a Stark Coffe<--------\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf("\tQue desea realizar...?\n");
	printf("\t\t [1] Mostrar el menu\n");
	printf("\t\t [2] Comprar producto y Factura\n");
	printf("? ");
	scanf("%d",&menu);
	
	switch (menu){
	
	case 1:
	system("cls");
	system("Menu");
	break; 
	
	case 2:
	system("cls");
	system("CompraFactura");
	break;
	
	case 1448:
		system("cls");
		system("Administrador");
	break;
	
	case 2223:
		system("cls");
		cout<<"Gracias por usar nuestro sistema, vuelva pronto. :D"<<endl;
		bandera = true;
	break;
	
	default: 
	printf("no es opcion");
    
	}
	system("PAUSE");
	
  }while(bandera != true);
}

void pausa(){
    cout << "Pulsa una tecla para continuar...";
    getwchar();
    getwchar();

}
