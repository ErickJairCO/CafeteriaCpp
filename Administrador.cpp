#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>

using namespace std;

struct datosInventario{
	int numCodigo;
	string nomProducto;
	int cantidad;
	double precio;
};

void pausa();
void agregarArchivo (ofstream &pa);
void eliminarProducto (ifstream &pa);
void visualizarInventario(ifstream &paR);
void modificarProducto(ifstream &pa);
void menorCantidad(ifstream &pa);
void actualizarCantidad(ifstream &pa);

 

int main()
{

    bool bandera=false;
    char tecla;
    ofstream escribir;
    ifstream leer;
 

    do

    {

        system("cls");
        cin.clear();
        cout << "\t\t\t\t\t---------->>Administrador<<----------" << endl;
        cout << "\t\t\t--------------------------------------------------------------" << endl << endl;
        cout << "\t1 .- Agregar nuevo producto" << endl;
        cout << "\t2 .- Eliminiar producto" << endl;
        cout << "\t3 .- Consulta de inventario" << endl;
        cout << "\t4 .- Mostrar cantidad de productos" << endl;
        cout << "\t5 .- Modificar el nombre del producto" << endl;
        cout << "\t6 .- Actualizar cantidad"<< endl;
        cout << "\t7 .- Salir" << endl;
        cout << "Elije una opcion: ";


        cin >> tecla;
		switch(tecla){

			case '1':
				system("cls");
				agregarArchivo(escribir);
				pausa();
				break;

 
			case '2':
				system("cls");
				eliminarProducto(leer);
				pausa();
				break;

 
			case '3':
				system("cls");
				visualizarInventario(leer);
				pausa();
				break;

 

			case '4':
				system("cls");
				menorCantidad(leer);
				pausa();
				break;
				
				
			case '5':
				system("cls");
				modificarProducto(leer);
				pausa();
				break;
				
			case '6':
				system ("cls");
				actualizarCantidad(leer);
				pausa();
				break;
				
			case '7':
				bandera=true;
				//exit(1);
				break;

 

			default:
				system("cls");
				cout << "Opcion no valida.\a\n";
				pausa();
				break;
		}

    }while(bandera!=true);

    return 0;
}//fin de la funcion menu

 

void pausa()

{
    cout << "Pulsa una tecla para continuar...";
    getwchar();
    getwchar();

} //fin de la funcion pausa


bool verifica (int codigo){
	
	ifstream leer ("Inventario.txt", ios::in );//trabajar en la lectura
	struct datosInventario inventario = { 0, "", 0, 0.0};
	
	leer>>inventario.nomProducto;
	while( !leer.eof()){
		
		leer>>inventario.cantidad;
		leer>>inventario.precio;
		leer>>inventario.numCodigo;
		if (inventario.numCodigo == codigo){
			leer.close();
			return false;
		}
		
		leer>>inventario.nomProducto;
	}
	
	leer.close();
	
	return true;
}

void agregarArchivo (ofstream &pa){
	
	system("cls");
	string producto;
	
	
	struct datosInventario inventario = {0, "", 0, 0.0};
	//inventario.nomProducto = producto;
	
	
	pa.open("Inventario.txt", ios::out | ios::app); // app para actulizar un archivo existente, y out abrir y escrbir un archivo
	
	cout<<"Numero de codigo: ";
	cin>>inventario.numCodigo;
	cout<<endl;
	
	cout<<"Nombre del producto: ";
	//getline(cin, producto);
	cin>>inventario.nomProducto;
	cout<<endl;
	
	cout<<"Cantidad disponible: ";
	cin>>inventario.cantidad;
	cout<<endl;
	
	cout<<"Precio por unidad: ";
	cin>>inventario.precio;
	cout<<endl;
	
	if (verifica(inventario.numCodigo)){
		pa<<inventario.nomProducto<<" "<<inventario.cantidad<<" "<<inventario.precio<<" "<<inventario.numCodigo<<endl;
	}
	else{
		cout<<"Hay un producto con ese mismo numero de codigo registrado en el inventario, vuelva a intentarlo"<<endl;
	}

	pa.close();
	
}


void menorCantidad(ifstream &pa){
	
	struct datosInventario inventario = { 0, "", 0, 0.0};
	
	int cant;
	
	pa.open("Inventario.txt", ios::in);
	
	if(pa.is_open()){
		pa>>inventario.nomProducto;
		while(!pa.eof()){
			pa>>inventario.cantidad;
			pa>>inventario.precio;
			pa>>inventario.numCodigo;
			if(inventario.cantidad <= 20){
				cout<<"Estos son los productos con numero de ID: " <<inventario.numCodigo<<" que cuentan con menor cantidad de stock ";
				cout<<inventario.nomProducto<<endl;
				cout<<"Cantidad disponible "<<inventario.cantidad<<endl;
				cout<<endl;
			}
			else{
				cout<<""<<endl;
			}
			
			pa>>inventario.nomProducto;
		}
		
		pa.close();
	}
	
	system ("pause");
	
}


void modificarProducto(ifstream &pa){
	
	struct datosInventario inventario = { 0, "", 0, 0.0};
	
	int opcion;
	int codigo;
	string nombre;
	int cant;
	double pre;
	
	pa.open("Inventario.txt", ios::in);         //in leer el archivo
	ofstream sub("sub.txt", ios::out);
	
	if(pa.is_open()){
		cout<<"Ingrese el ID del producto a modificar ";
		cin>>codigo;
		pa>>inventario.nomProducto;
		while(!pa.eof()){
		pa>>inventario.cantidad;
		pa>>inventario.precio;
		pa>>inventario.numCodigo;
					
			if(inventario.numCodigo == codigo){
				cout<<"Ingrese el nombre a cambiar ";
				cin>>nombre;
				sub<<nombre<<" "<<inventario.cantidad<<" "<<inventario.precio<<" "<<inventario.numCodigo<<endl;
						
			}
			else{
				sub<<inventario.nomProducto<<" "<<inventario.cantidad<<" "<<inventario.precio<<" "<<inventario.numCodigo<<endl;
						
			}
					
			pa>>inventario.nomProducto;
		}
				
		pa.close();
		sub.close();
				
	}
	else{
		cout<<"ERROr 0001"<<endl;
		
	}
	
	remove("Inventario.txt");
	rename("sub.txt", "Inventario.txt");
	
}


void eliminarProducto(ifstream &pa){
		struct datosInventario inventario = { 0, "", 0, 0.0};
			
	int numCodigo2;
	string nomProducto2;
	int cantidad2;
	double precio2;
	
	pa.open("Inventario.txt", ios::in);         //in leer el archivo
	ofstream sub("sub.txt", ios::out);
	if (pa.is_open()){
		cout<<"Ingrese el ID del producto a eliminar ";
		cin>>numCodigo2;
		cout<<endl;
		pa>>inventario.nomProducto;
			while(!pa.eof()){ //Lee hasta el final del archivo
			pa>>inventario.cantidad;
			pa>>inventario.precio;
			pa>>inventario.numCodigo;
			if (inventario.numCodigo == numCodigo2){
				cout<<"Se ha eliminado correctamente el producto :D"<<endl;
			}else{
				sub<<inventario.nomProducto<<" "<<inventario.cantidad<<" "<<inventario.precio<<" "<<inventario.numCodigo<<endl;	
				}
			pa>>inventario.nomProducto;
	
			}
		
		pa.close();
		sub.close();	
	} else{
		cout<< "ERROr 0002" ;
	}
	
	remove("Inventario.txt");
	rename("sub.txt", "Inventario.txt");	
}


void actualizarCantidad(ifstream &pa){
	
	struct datosInventario inventario = { 0, "", 0, 0.0};
	
	int id;
	int cant;
	int variable;
	
	
	pa.open("Inventario.txt", ios::in);
	ofstream sub("sub.txt", ios::out);
	
	system("cls");
	
	cout<<"Ingrese el ID del producto que desea modificar: ";
	cin>>id;
	cout<<endl;
	
	if(pa.is_open()){
		pa>>inventario.nomProducto;
		while(!pa.eof()){
			pa>>inventario.cantidad;
			pa>>inventario.precio;
			pa>>inventario.numCodigo;
			if(inventario.numCodigo == id){
				
				cout<<"Ingrese la cantidad que desea agregar ( + ) o descontar ( - ) al stock ";
				cin>>variable;
				cout<<endl;
				cant = variable+inventario.cantidad;
				cout<<"Nueva cantidad "<<cant<<endl; 
				sub<<inventario.nomProducto<<" "<<cant<<" "<<inventario.precio<<" "<<inventario.numCodigo<<endl;				
				
			}
			else{
				sub<<inventario.nomProducto<<" "<<inventario.cantidad<<" "<<inventario.precio<<" "<<inventario.numCodigo<<endl;
			}
			
			pa>>inventario.nomProducto;
		}
		
		pa.close();
		sub.close();
	}
	remove("Inventario.txt");
	rename("sub.txt", "Inventario.txt");
	
	system ("pause");
	
}


void visualizarInventario(ifstream &paR){
	
	struct datosInventario inventario = { 0, "", 0, 0.0};
	
	paR.open("Inventario.txt", ios::in);//Abrir el archivo para lectura
	paR>>inventario.nomProducto;
	
	if(paR.is_open()){
		while(!paR.eof()){ //Que se ejecute hasta que llegue al final del archivo
			paR>>inventario.cantidad;
			paR>>inventario.precio;
			paR>>inventario.numCodigo;
			cout<<"Nombre del producto.... "<<inventario.nomProducto<<endl;
			cout<<"Codigo.... "<<inventario.numCodigo<<endl;
			cout<<"Cantidad disponible.... "<<inventario.cantidad<<endl;
			cout<<"Precio por unidad.... $"<<inventario.precio<<endl;
			cout<<endl;
			
			paR>>inventario.nomProducto;
		}/* fin de la funcion while */
	
	paR.close();
	
	}
	else{
		cout<<"ERROr 0003"<<endl;
	}
	
	system ("pause");
}



