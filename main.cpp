#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>


using namespace std;
bool encontrado = false; 

char respuesta;
string usuario,contrasena;
int opcion; 

struct peliculas{
	int codigo;
	int codigoAux;
	string nombreAux;
	string nombrePelicula;
	string nombreDirector;
	string DirectorAux;
	string genero;
	string generoAux;
	char cantidad[10];
	int anio;
	int anioAux;
	
}pelis[10];

struct Alquiler
{
	char fecha[15];
    char cedula[30];
	char nombre[30];
	char telefono[15];
	int cantidadAlquilar;
}alqui[5];


void consultas()
{
	int contador = 0;
    ifstream lectura;
    lectura.open("peliculas.txt", ios::out | ios::in);
    if(lectura.is_open())
	{
    	lectura>>pelis[contador].codigo;
    	while(!lectura.eof())
		{
		system ("color 2");
        	lectura>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
	        cout<<"\n";
    	    cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
	        cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
    	    cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
	        cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    cout<<"Director de la pelicula: "<<pelis[contador].nombreDirector<<endl;
	        cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
			lectura>>pelis[contador].codigo;
    	}
    }else
	{
		/*decision por si no se puede abrir el documento de almacenaje de la peliculas*/
        cout<<"El archivo no se pudo abrir \n";
    }
    lectura.close();
	
	cout <<"\nPresione enter para volver al menu principal. . .\n"; /*mensaje de salida para volver al menu principal*/
	getch();
}

void insertarpeliculas(){
    /*Variables de la biblioteca fstream para el manejo de archivos*/
    ofstream escritura;
    ifstream consulta; 
	system ("color 6");
    int contador = 0;
	cout<<"BIENVENIDO AL SISTEMA DE ADMINISTRADOR";
	cout<<"\n\n";
	fflush(stdin);
	cout<<"Usuario (admin): "; /*ingreso del nombre de usuario del administrador, el usuario es admin*/
	cin>>usuario; 
	fflush(stdin);
	cout<<"\nContrasena (admin123): "; /*ingreso de la contraseña del administrador, la contraseña es admin123*/
	cin>>contrasena;
	
	if(usuario == "admin" && contrasena == "admin123")
	{
		cout<<"\nAcceso Permitido\n";
		cout<<"Oprima enter para continuar\n\n";
		getch();
		do
		{	
			system("cls"); 
			system ("color B"); /*cambio de la interfaz*/
			cout<<"[1] Ingresar Peliculas"<<endl;
			cout<<"\n[2] Consultas peliculas prestadas"<<endl;
			cout<<"\n[3] Eliminar cantidad de pelicula"<<endl;
			cout<<"\n[4] Multas"<<endl;
			cout<<"\n[5] Salir"<<endl;
			cout<<"\nElija una opcion: ";
			fflush(stdin);
			cin>>opcion;
		
			switch(opcion)
			{
				case 1:
				system("cls");
				contador = 0;
				do
				{
					system("cls");
					escritura.open("peliculas.txt", ios::out | ios::app);
    				consulta.open("peliculas.txt", ios::in); //solamente consulta o lee usando la variable sobre el archivo físico peliculas.txt
					
					if(escritura.is_open() && consulta.is_open() /*&& escritura2.is_open()*/) /*decicion para saber si el codigo ingresado ya existe*/
					{
						bool repetido = false; /*declaracion de variable*/
        				cout<<"Ingresa el codigo de la pelicula: ";
        				fflush(stdin);
        				cin>>pelis[contador].codigoAux; //lectura del codigo auxiliar que ira almacenado en el documento temporal creado
        				
						
						consulta>>pelis[contador].codigo;
						while(!consulta.eof()) /*recorre todo el archivo para saber si el codigo ingresado ya existe*/
						{
						consulta>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
							if(pelis[contador].codigoAux == pelis[contador].codigo)
							{
								cout<<"\nYa hay una pelicula con este codigo\n";
								repetido = true;
								
							}
							consulta>>pelis[contador].codigo;
						}
						
						if(repetido == false)
						{
							cout<<"Ingrese el nombre de la pelicula (En caso de que haya espaciado usar _): ";
							fflush(stdin);
							getline(cin,pelis[contador].nombrePelicula); /*lectura del nombre de la pelicula*/
							
							cout<<"Ingrese la cantidad de la pelicula: ";
							fflush(stdin);
							gets(pelis[contador].cantidad); /*lectura de la cantidad de la pelicula*/
							
							cout<<"Ingrese el anio de la pelicula: ";
							fflush(stdin);
							cin>>pelis[contador].anio; /*lectura del año de la pelicula*/
							
							cout<<"Ingrese el nombre del director de la pelicula (En caso de que haya espaciado usar _): ";
							fflush(stdin);
							getline(cin,pelis[contador].nombreDirector); /*lectura del nombre de autor*/
							
							cout<<"Ingrese el genero de la pelicula: ";
							fflush(stdin);
							getline(cin,pelis[contador].genero); /*lectura del genero de la pelicula*/
							
							/*Escribiendo los datos capturados por el usuario de archivo*/
							escritura<<pelis[contador].codigoAux<<" "<<pelis[contador].nombrePelicula<<" "<<pelis[contador].cantidad<<" "<<pelis[contador].anio<<" "<<pelis[contador].nombreDirector<<" "<<pelis[contador].genero<<endl;
							
							cout<<"\nPelicula agregada\n";
						}
						
						cout<<"Desea ingresar otra pelicula (s/n)?: ";
						fflush(stdin);
            			cin>>respuesta;
					
					}else /*decision si no se puede abrir el archivo*/
					{
						cout<<"El archivo no se pudo abrir \n"; /*mensaje de salida al no poder abrir el archivo*/
					}
				contador++;
			
				escritura.close();
				consulta.close();
				
				}while(respuesta =='S' or respuesta =='s');
				break; 
				
				case 2:
				{
					contador = 0;
   					ifstream lectura;
    				lectura.open("DatosAlquiler.txt", ios::out | ios::in);
    				if(lectura.is_open()){
    					lectura>>alqui[contador].fecha;
    					cout<<"\nLista de peliculas alquiladas:\n";
    					while(!lectura.eof()){ /*Hace el recorrido del documento DatosAlquiler.txt y muestra la informacion que este dentro de esta*/
							lectura>>alqui[contador].cedula>>alqui[contador].nombre>>alqui[contador].telefono>>pelis[contador].nombrePelicula>>alqui[contador].cantidadAlquilar;
        					cout<<"\n";
        					cout<<"Nombre: "<<pelis[contador].nombrePelicula<<endl;
        					cout<<"Cantidad: "<<alqui[contador].cantidadAlquilar<<endl;
        					cout<<"Alquilada por: "<<alqui[contador].nombre<<endl;
        					cout<<"Fecha: "<<alqui[contador].fecha<<endl;
        					cout<<"Cedula: "<<alqui[contador].cedula<<endl;
        					cout<<"Telefono: "<<alqui[contador].telefono<<endl;
        					lectura>>alqui[contador].fecha; /*llamada de la variable para seguir acumulando*/
    					}
    				}else{
        				cout<<"El archivo no se pudo abrir \n";
    				}
    				lectura.close(); /*se cierra la variable que hace la lectura del documento DatosAlquiler.txt*/
					contador++;
					cout<<"\nPresione enter para continuar\n";
					getch();
				break;
				}
		
				case 3:
				{	
				
					ofstream fechaDatos, aux;
					ifstream Imprimir, archivo1, lectura;
					int contador = 0, x, resta;
	
					do
   	 				{
    					system("cls");
    					cout<<"\nLista de peliculas para alquilar:\n";
    					Imprimir.open("peliculas.txt", ios::out | ios::in);
    					if(Imprimir.is_open())
						{
    						Imprimir>>pelis[contador].codigo;
	    					while(!Imprimir.eof())
							{
			        			Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
    			    			cout<<"\n";
			        			cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    			    			cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        						cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
		        				Imprimir>>pelis[contador].codigo;
    						}
    					}else
						{	
	        				cout<<"El archivo no se pudo abrir \n"; /*mensaje de salida al no poder abrir el documento*/
	    				}
    					Imprimir.close(); /*cierre del documento*/
    					
    					
    					
						archivo1.open("peliculas.txt", ios::out | ios::in);/*apertura del documento*/
    					cout<<"\nIngrese el codigo de la pelicula a la cual eliminara x cantidad: ";
    					
						encontrado = false;
						
    					if(archivo1.is_open())
						{
	    					fflush(stdin);
    	    				cin>>pelis[contador].codigoAux;
        					
	        				archivo1>>pelis[contador].codigo;
    	    				while(!archivo1.eof())
							{
        	    				archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero; //recorrido
	        					
								
    	    					if(pelis[contador].codigoAux == pelis[contador].codigo){/*comparar cada registro para ver si se encontró*/
		        	    			cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
    		    					cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
	    		    				x = atoi(pelis[contador].cantidad);
		    		    			
	        		    			encontrado = true; //variable logica
    	        					cout<<"\nCuantas desea eliminar?: ";
        	    					fflush(stdin);
	    							cin>>alqui[contador].cantidadAlquilar;
    								if(alqui[contador].cantidadAlquilar < x)
    								{
	    								/*El proceso no se puso aqui porque se cree que hay una interferencia*/
									}else
									{
										cout<<"\nNo hay suficientes peliculas disponibles";
										cout<<"\nPresione enter para continuar\n";
										getch();
									}
    	    					}
								
    	    					archivo1>>pelis[contador].codigo;
        					}
	        				
							if (encontrado == false)
							{
    	        				cout<<"\nNo hay registros con el codigo: "<<pelis[contador].codigoAux<<"\n";
	        				}
	    				
						}else
						{
	        				cout<<"\nAun no se pudo abrir el archivo..."; /*mensaje de salida*/
	    				}
						archivo1.close(); /*cierre del documento*/
						
						
    					encontrado = false; /*variable logica*/
    					if(alqui[contador].cantidadAlquilar < x)
    					{
    						aux.open("auxiliar.txt", ios::out); /*creacion del documento*/
    						lectura.open("peliculas.txt", ios::in); /*lectura del documento peliculas.txt*/
							
    						if (aux.is_open() && lectura.is_open())
							{
    		    				lectura>>pelis[contador].codigo;
        						while (!lectura.eof())
								{
    	            				lectura>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
        	        				if (pelis[contador].codigoAux == pelis[contador].codigo)
									{
	                    				encontrado = true;
										resta = x - alqui[contador].cantidadAlquilar;
										
            	        				aux<<pelis[contador].codigo<<" "<<pelis[contador].nombrePelicula<<" "<<resta<<" "<<pelis[contador].anio<<" "<<pelis[contador].nombreDirector<<" "<<pelis[contador].genero<<endl; /*guardado en el aux*/
            	        
										cout<<"\nFinalizando pedido. . .\n";
										cout<<"\nPresione enter para continuar\n";
	               					}else
									{
        	            				aux<<pelis[contador].codigo<<" "<<pelis[contador].nombrePelicula<<" "<<pelis[contador].cantidad<<" "<<pelis[contador].anio<<" "<<pelis[contador].nombreDirector<<" "<<pelis[contador].genero<<endl;
            	    				}
	                				lectura>>pelis[contador].codigo; /*llamado de la variable*/
    	        				}
	    					}else
							{
		        			cout<<"\nEl archivo no se pudo abrir\n"; /*mensaje de salida*/
		    				}
						
    						if (encontrado == false)
							{
	    	    				cout<<"\nNo hay ninguna pelicula con el codigo: "<<pelis[contador].codigoAux<<"\n"; /*mensaje de salida*/
		    				}
							
    						aux.close();
    						lectura.close();
	    					remove ("peliculas.txt"); /*eliminacion del documento*/
    						rename("auxiliar.txt", "peliculas.txt");
						}
	    				
						contador++;
    					cout<<"\nDesea alquilar otra pelicula (s/n)?: ";
						fflush(stdin);
        				cin>>respuesta;
        				
					}while(respuesta =='S' or respuesta =='s');	
				break;
				}
				
				case 4:
				{
					ifstream archivo1, lectura;
					int dias,Vmulta;
					contador = 0;
					
					do
    				{
    					system("cls");
						lectura.open("DatosAlquiler.txt", ios::out | ios::in);
    					if(lectura.is_open()){
    						lectura>>alqui[contador].fecha;
    						cout<<"\nLista de peliculas alquiladas:\n";
    						while(!lectura.eof()){ /*hace el recorrido del documento DatosAlquiler.txt y muestra la informacion que este dentro de ella*/
								lectura>>alqui[contador].cedula>>alqui[contador].nombre>>alqui[contador].telefono>>pelis[contador].nombrePelicula>>alqui[contador].cantidadAlquilar;
        						cout<<"\n";
	        					cout<<"Nombre: "<<pelis[contador].nombrePelicula<<endl;
    	    					cout<<"Cantidad: "<<alqui[contador].cantidadAlquilar<<endl;
        						cout<<"Alquilada por: "<<alqui[contador].nombre<<endl;
        						cout<<"Fecha: "<<alqui[contador].fecha<<endl;
        						cout<<"Cedula: "<<alqui[contador].cedula<<endl; 
        						cout<<"Telefono: "<<alqui[contador].telefono<<endl;
	        					lectura>>alqui[contador].fecha;
    						}
    					}else{
        					cout<<"El archivo no se pudo abrir \n"; /*decision por si el documeno no se puede abrir*/
    					}
    					lectura.close(); /*se cierra la variable que hace la lectura del documento DatosAlquiler.txt*/
    					
						archivo1.open("DatosAlquiler.txt", ios::out | ios::in);
						encontrado=false;
						if(archivo1.is_open())
						{
							cout<<"\nIngrese el nombre de la pelicula que desea hacer la multa: ";
							fflush(stdin);
							cin>>pelis[contador].nombreAux; /*lectura del nombre a buscar*/
							
							archivo1>>pelis[contador].nombrePelicula;
							
							while(!archivo1.eof()){
								archivo1>>alqui[contador].cedula>>alqui[contador].nombre>>alqui[contador].telefono>>pelis[contador].nombrePelicula>>alqui[contador].cantidadAlquilar;				
								
								if(pelis[contador].nombreAux == pelis[contador].nombrePelicula)
								{
									cout<<"\nCuantos dias han pasado desde el alquiler?: ";
									fflush(stdin);
									cin>>dias; /*lectura de los dias ingresados*/
									if(dias > 10) /*condicion*/
									{
										Vmulta= dias * 20;
										cout<<"\nSe debe aplicar una multa de: "<<Vmulta<<" Lps"; /*mensaje de salida*/
									}else
									{
										if(dias == 10)
										{
											cout<<"\nAun esta a tiempo de entrega"; /*mensaje de salida*/
										}else
										{
											cout<<"\nAun esta a tiempo de entrega"; /*mensaje de salida*/
										}
									}
									encontrado=true;
								}
								archivo1>>pelis[contador].nombrePelicula; /*llamado de la varible y acumulacion de ella*/
							}
							
							if(encontrado==false)
							{
								cout<<"\nNo hay peliculas con ese nombre\n"; /*mensaje de salida*/
							}
		
						}else
						{
							cout<<"\nAun no se pudo abrir el archivo"; /*mensaje de salida*/
						}
						
						archivo1.close(); /*cierre del documento*/
						cout<<"\nDesea agregar otra multa s/n?: ";
						fflush(stdin);
						cin>>respuesta;
						contador++;
					}while(respuesta =='S' or respuesta =='s');	
					break;
				}
					
				
			}/*se cierra el switch*/
		}while(opcion != 5);/*se cierra el do principal*/
  	}else
	{
		/*mensaje de salida con interaccion del usuario*/
  		cout<<"\nAcceso denegado\n";
		cout<<"Oprima enter para continuar\n\n"; 
		getch();
	}
}/*se cierra el void*/

/*funcion de busqueda por las caracteristicas de las peliculas*/
void buscar()
{
	int n;
	int contador;
    ifstream lectura, archivo1, archivo2;

	do{
		system("cls");
		system ("color 3"); /*cambio de la interfaz*/
		cout<<"Ingrese segun el numero, lo que desea hacer: "<<endl;
		cout<<"\n[1] Consultar por codigo"<<endl;
		cout<<"\n[2] Consultar por nombre"<<endl;
		cout<<"\n[3] Consultar por anio"<<endl;
		cout<<"\n[4] Consultar por director"<<endl;
		cout<<"\n[5] Consultar por genero"<<endl;
		cout<<"\n[6] Salir\n"<<endl;
		cout<<"\nElija una opcion: "; 
		fflush(stdin);
		cin>>n;
		
		switch(n)
		{
		case 1:
		{
			ifstream Imprimir;
			do{
			
			system("cls");
			contador = 0;
			archivo1.open("peliculas.txt", ios::out | ios::in);
			encontrado = false; //variable logica
			
			cout<<"\nLista de peliculas:\n";
    		Imprimir.open("peliculas.txt", ios::out | ios::in);
    		if(Imprimir.is_open())
			{

    			Imprimir>>pelis[contador].codigo;
	    		while(!Imprimir.eof()) /*recorrido del documento*/
				{
		        	Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
    		    	cout<<"\n";
		        	cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    		    	cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        			cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        			cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    		cout<<"Director de la pelicula: "<<pelis[contador].nombreDirector<<endl;
	        		cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
		        	Imprimir>>pelis[contador].codigo;
		        	
    			}
    		}else
			{	
		        cout<<"El archivo no se pudo abrir \n"; /*mensaje de salida*/
		    }
    		Imprimir.close(); /*cierre del documento*/
			
			
    		if(archivo1.is_open())
			{
				cout<<"\nIngrese el codigo de la pelicula que desea buscar: ";
				fflush(stdin);
        		cin>>pelis[contador].codigoAux; /*lectura del codigo a buscar*/
        		
        		archivo1>>pelis[contador].codigo; /*llamado de la variable*/
        		
        		while(!archivo1.eof()) /*recorrido del documento*/
				{
	            	archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
        			//comparar cada registro para ver si es encontrado				
        			if(pelis[contador].codigoAux == pelis[contador].codigo)
					{
            			cout<<"\nCodigo de la pelicula: "<<pelis[contador].codigo<<endl;
        				cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        				cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        				cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
        				cout<<"Director de la pelicula: "<<pelis[contador].nombreDirector<<endl;
        				cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
        				
            			encontrado = true;
        			}
        			archivo1>>pelis[contador].codigo; /*llamado de la variable y su acumulacion*/
        		}
        		if (encontrado == false)
				{
            		cout<<"\nNo hay registros con el codigo: "<<pelis[contador].codigoAux<<"\n"; /*mensaje de salida*/
        		}
    		}else
			{
        		cout<<"\nAun no se pudo abrir el archivo..."; /*mensaje de salida*/
    		}
			
			archivo1.close();
			cout<<"\nDesea buscar otra pelicula (s/n)?: ";
			fflush(stdin);
            cin>>respuesta; /*lectura de la respuesta del usuario*/
			
			contador++;	
			}while(respuesta =='S' or respuesta =='s');
			
		break;
		}
		case 2:
		{
			ifstream Imprimir;
			do
			{
				system("cls");
				contador = 0;
				archivo1.open("peliculas.txt", ios::out | ios::in); /*aperturas del documento peliculas.txt*/
				encontrado = false;
				
				cout<<"\nLista de peliculas:\n";
    			Imprimir.open("peliculas.txt", ios::out | ios::in);
	    		if(Imprimir.is_open())
				{
	    			/*Leyendo y mostrando c/ campo del aarchivo de forma secuencial*/
    				Imprimir>>pelis[contador].codigo;
		    		while(!Imprimir.eof()) /*recorrido del documento*/
					{
			        	Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
    			    	cout<<"\n";
		        		cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    		    		cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        				cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        				cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    			cout<<"Director de la pelicula: "<<pelis[contador].nombreDirector<<endl;
	        			cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
		        		Imprimir>>pelis[contador].codigo; /*llamado de la variable para su acumulacion*/
	    			}
	    		}else
				{	
			        cout<<"El archivo no se pudo abrir \n"; /*mensaje de salida*/
		    	}
	    		Imprimir.close(); /*cierre del documento*/
				
				
    			if(archivo1.is_open())
				{
					cout<<"\nIngrese el nombre de la pelicula que desea buscar: ";
					fflush(stdin);
        			getline(cin,pelis[contador].nombreAux); /*lectura de la pelicula a buscar*/
        			
        			archivo1>>pelis[contador].nombrePelicula;
        			while(!archivo1.eof())
					{
	            		archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
						
        				if(pelis[contador].nombreAux == pelis[contador].nombrePelicula) /*comparacion y busqueda en el registro*/
						{
	                        cout<<"\n"<<endl;  
	        				cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
    	    				cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        					cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
        					cout<<"Director de la pelicula: "<<pelis[contador].nombreDirector<<endl;
        					cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
        					
            				encontrado = true;
        				}
						
        				archivo1>>pelis[contador].nombrePelicula;
        				
        			}
        			if (encontrado == false)
					{
	            		cout<<"\nNo hay registros con el nombre: "<<pelis[contador].nombreAux<<"\n"; /*mensaje de salida*/
    	    		}
    			
				}else
				{
	        		cout<<"\nAun no se pudo abrir el archivo..."; /*mensaje de salida*/
    			}
			
				archivo1.close(); /*cierre del documento*/
				cout<<"\nDesea buscar otra pelicula (s/n)?: ";
				fflush(stdin);
            	cin>>respuesta; /*lectura de la respuesta seleccionada por el usuario*/
				contador++;	
			}while(respuesta =='S' or respuesta =='s');	
		break;
		}
		case 3:
		{
			
			ifstream Imprimir; /*variable de lectura declaracion*/
			do{
			
			system("cls");
			contador = 0;
			archivo1.open("peliculas.txt", ios::out | ios::in);
			encontrado = false;
			
			cout<<"\nLista de peliculas:\n";
    		Imprimir.open("peliculas.txt", ios::out | ios::in);
	    	if(Imprimir.is_open())
			{
   				Imprimir>>pelis[contador].codigo;
		    	while(!Imprimir.eof()) /*recorrido del documento peliculas.txt*/
				{
		        	Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
   			    	cout<<"\n";
		        	cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    		    	cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        			cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        			cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    		cout<<"Director de la pelicula: "<<pelis[contador].nombreDirector<<endl;
	        		cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
		        	Imprimir>>pelis[contador].codigo; /*llamado de la variable para su acumulacion*/
    			}
	    	}else
			{	
		        cout<<"El archivo no se pudo abrir \n"; /*mensaje de salida*/
	    	}
    		Imprimir.close(); /*cierre del documento*/
			
			
    		if(archivo1.is_open()) /*si el documento se abre*/
			{
				cout<<"\nIngrese el anio de la pelicula que desea buscar: ";
				fflush(stdin);
        		cin>>pelis[contador].anioAux; /*lectura del año a buscar*/
        		
							        
        		archivo1>>pelis[contador].anio; /*llamado de la variable*/
        		
        		while(!archivo1.eof()) /*recorrido del documento peliculas.txt*/
				{
	            	archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
        			/*comparar cada registro para ver si es encontrado*/
        			if(pelis[contador].anioAux == pelis[contador].anio)
					{
                        cout<<"\n";
        				cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        				cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        				cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
        				cout<<"Director de la pelicula: "<<pelis[contador].nombreDirector<<endl;
        				cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
        				
            			encontrado = true;
        			}
					
        			archivo1>>pelis[contador].anio;
        			
        		}
        		if (encontrado == false)
				{
            		cout<<"\nNo hay registros con el anio: "<<pelis[contador].anioAux<<"\n"; /*mensaje de salida*/
        		}
    		}else
			{
        		cout<<"\nAun no se pudo abrir el archivo..."; /*mensaje de salida*/
    		}
			
			archivo1.close(); /*cierre del documento*/
			cout<<"\nDesea buscar otra pelicula (s/n)?: ";
			fflush(stdin);
            cin>>respuesta; /*lectura de la respuesta del usuario*/
			
			contador++;	
			}while(respuesta =='S' or respuesta =='s');
			break;
			}
			case 4:
			{
				ifstream Imprimir; /*declaracion de la variable de lectura*/
				do
				{
					system("cls");
					contador = 0;
					archivo1.open("peliculas.txt", ios::out | ios::in); /*apertura del documento*/
					encontrado = false;
					
					
					cout<<"\nLista de peliculas:\n";
    				Imprimir.open("peliculas.txt", ios::out | ios::in);
			    	if(Imprimir.is_open())
					{
   						Imprimir>>pelis[contador].codigo;
			    		while(!Imprimir.eof()) /*recorrido del documento peliculas.txt*/
						{
				        	Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
   					    	cout<<"\n";
							cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    		    			cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        					cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        					cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    				cout<<"Director de la pelicula: "<<pelis[contador].nombreDirector<<endl;
	        				cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
		        			Imprimir>>pelis[contador].codigo; /*llamado de la variable y su acumulacion*/
    					}
			    	}else
					{	
			    	    cout<<"El archivo no se pudo abrir \n"; /*mensaje de salida*/
	    			}
		    		Imprimir.close(); /*cierre del documento*/
					
					
    				if(archivo1.is_open())
					{
						cout<<"\nIngrese el director que desea buscar: ";
						fflush(stdin);
        				cin>>pelis[contador].DirectorAux; /*lectura del director a buscar*/
        				
        				archivo1>>pelis[contador].nombreDirector; /*llamado de la variable*/
        				while(!archivo1.eof())/*mientras se recorra el documento*/
						{
	            			archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
        					/*comparar cada registro para ver si es encontrado*/
        					if(pelis[contador].DirectorAux == pelis[contador].nombreDirector)
							{
                        		cout<<"\n";
	        					cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
    	    					cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        						cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
        						cout<<"Director de la pelicula: "<<pelis[contador].nombreDirector<<endl;
        						cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
        						
            					encontrado = true;
        					}
							
        					archivo1>>pelis[contador].nombreDirector;
        					
        				}
        				if (encontrado == false)
						{
            				cout<<"\nNo hay registros con el autor: "<<pelis[contador].DirectorAux<<"\n"; /*mensaje de salida*/
        				}
    					
					}else
					{
        				cout<<"\nAun no se pudo abrir el archivo..."; /*mensaje de salida*/
    				}
					
					archivo1.close(); /*cierre del documento*/
					cout<<"\nDesea buscar otra pelicula (s/n)?: ";
					fflush(stdin);
           			cin>>respuesta; /*lectura de la respuesta del usuario*/
					contador++;	
				}while(respuesta =='S' or respuesta =='s');
			break;
			}
			case 5:
			{
				ifstream Imprimir; /*declaracion de la variable de lectura*/
				do
				{
					system("cls");
					contador = 0;
					archivo1.open("peliculas.txt", ios::out | ios::in); /*apertura del documento*/
					encontrado = false;
					
					
					cout<<"\nLista de peliculas:\n";
    				Imprimir.open("peliculas.txt", ios::out | ios::in);
			    	if(Imprimir.is_open())
					{
	   					/*Leyendo y mostrando cada campo del archivo de forma secuencial*/
   						Imprimir>>pelis[contador].codigo;
			    		while(!Imprimir.eof()) /*mientras se pueda recorrer el documento*/
						{
				        	Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
   					    	cout<<"\n";
							cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    		    			cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        					cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        					cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    				cout<<"Director de la pelicula: "<<pelis[contador].nombreDirector<<endl;
	        				cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
		        			Imprimir>>pelis[contador].codigo; /*llamado de la variable y de su almacenaje*/
    					}
			    	}else
					{	
			    	    cout<<"El archivo no se pudo abrir \n"; /*mensaje de salida*/
	    			}
		    		Imprimir.close(); /*cierre del documento*/
				
				
    				if(archivo1.is_open())
					{
						cout<<"\nIngrese el genero que desea buscar: ";
						fflush(stdin);
        				cin>>pelis[contador].generoAux; /*lectura del genero a buscar*/
		        		
									        
        				archivo1>>pelis[contador].genero; /*llamado de la variable*/
	        			
    	    			while(!archivo1.eof()) /*mientras se pueda leer el documento*/
						{
			            	archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
    		    			/*comparar cada registro para ver si es encontrado*/
	        				if(pelis[contador].generoAux == pelis[contador].genero)
							{
    		                    cout<<"\n"; 
        						cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        						cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
	        					cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    					cout<<"Director de la pelicula: "<<pelis[contador].nombreDirector<<endl;
        						cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
		        				
    		        			encontrado = true;
	        				}

    		    			archivo1>>pelis[contador].genero;
        					
	        			}
    	    			if (encontrado == false)
						{
    	    	    		cout<<"\nNo hay registros con el genero: "<<pelis[contador].generoAux<<"\n"; /**mensaje de salida*/
        				}
	    			}else
					{
    	    			cout<<"\nAun no se pudo abrir el archivo..."; /*mensaje de salida*/
	    			}
					
					archivo1.close();
					cout<<"\nDesea buscar otra pelicula (s/n)?: ";
					fflush(stdin);
    	        	cin>>respuesta; /*lectura de la respuesta del usuario*/
					
					contador++;	
				}while(respuesta =='S' or respuesta =='s');
			break;
			}
		}
	}while(n != 6);	
}

/*funcion para el alquiler de las peliculas*/
void modificar(){
	/*declaracion de variables*/
	ofstream fechaDatos, aux;
	ifstream Imprimir, archivo1, lectura;
	int contador = 0, x, resta;
	
	do
    {
		system ("color D");    	
		system("cls");
		fechaDatos.open("DatosAlquiler.txt", ios::out | ios::app); /*apertura del documento DatosAlquiler.txt*/
	
		cout<<"Ingrese la fecha actual dd/mm/aa: ";
		fflush(stdin);
		gets(alqui[contador].fecha); /*lectura de la fecha*/
		
		cout<<"Ingrese su cedula: ";
		fflush(stdin);
		gets(alqui[contador].cedula); /*lectura de la cedula*/
		
		cout<<"Ingrese su nombre (En caso de haber espacio entre las palabras usar _): ";
		fflush(stdin);
		gets(alqui[contador].nombre); /*lectura del nombre*/
		
		cout<<"Ingrese su telefono: ";
		fflush(stdin);
		gets(alqui[contador].telefono); /*lectura del numero*/
	    
    	/*mensaje de salida con interaccion del usuario*/
    	cout<<"\nDatos agregados exitosamente\n";
    	cout<<"\nPresione enter para continuar\n";
    	getch();
    
		
    	system("cls");
    	cout<<"\nLista de peliculas para alquilar:\n";
    	Imprimir.open("peliculas.txt", ios::out | ios::in);
    	if(Imprimir.is_open())
		{
    		Imprimir>>pelis[contador].codigo;
	    	while(!Imprimir.eof()) /*mientras se pueda leer*/
			{
		        Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
    		    cout<<"\n";
		        cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    		    cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        		cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
		        Imprimir>>pelis[contador].codigo; /*llamado de la variable y se alamacenaje*/
    		}
    	}else
		{	
	        cout<<"El archivo no se pudo abrir \n"; /*mensaje de salida*/
	    }
    	Imprimir.close(); /*cierre del documento*/
    
    
    
		archivo1.open("peliculas.txt", ios::out | ios::in); /*apertura del documento peliculas.txt*/
    	cout<<"\nIngrese el codigo de la pelicula que desea alquilar: "; 
    	
		encontrado = false;
		
    	if(archivo1.is_open()) /*si se abre el documento*/
		{
	    	fflush(stdin);
    	    cin>>pelis[contador].codigoAux; /*lectura del codigo a buscar*/
        	
	        archivo1>>pelis[contador].codigo;/*llamado de la variable*/
    	    while(!archivo1.eof()) /*mientras se pueda leer el documento*/
			{
        	    archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
	        	/*comparar cada registro para ver si es encontrada*/
    	    	if(pelis[contador].codigoAux == pelis[contador].codigo){
	        	    cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
    	    		cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
	    	    	x = atoi(pelis[contador].cantidad); /*conversion de char a entero*/
    	    		
	        	    encontrado = true;
    	        	cout<<"\nCuantas desea alquilar?: ";
        	    	fflush(stdin);
	    			cin>>alqui[contador].cantidadAlquilar;/*lectura de la cantidad de peliculas a alquilar*/
    				if(alqui[contador].cantidadAlquilar < x) /*si la cantidad a alquilar es menor a la de la resta*/
    				{
    					/*guardar datos*/
	    				fechaDatos<<alqui[contador].fecha<<" "<<alqui[contador].cedula<<" "<<alqui[contador].nombre<<" "<<alqui[contador].telefono<<" "<<pelis[contador].nombrePelicula<<" "<<alqui[contador].cantidadAlquilar<<endl;
						fechaDatos.close(); /*cierre del documento*/
					}else
					{
						/*mensajes de salida con interaccion del usuario*/
						cout<<"\nNo hay suficientes peliculas disponibles";
						cout<<"\nPresione enter para continuar\n";
						getch();
					}
    	    	}
			
    	    	archivo1>>pelis[contador].codigo; /*llamado de la variable*/
        	}
	        if (encontrado == false)
			{
    	        cout<<"\nNo hay registros con el codigo: "<<pelis[contador].codigoAux<<"\n"; /*mensaje de salida*/
	        }
	    }else
		{
	        cout<<"\nAun no se pudo abrir el archivo..."; /*mensaje de salida*/
	    }
		archivo1.close(); /*cierre del documento*/
		
		
    	encontrado = false;
    	if(alqui[contador].cantidadAlquilar < x) /*mientras la cantidad sea menor a la resta*/
    	{
    		aux.open("auxiliar.txt", ios::out); /*apertura del documento*/
    		lectura.open("peliculas.txt", ios::in); /*lectura del documento*/
			
    		if (aux.is_open() && lectura.is_open()) /*apertura de los dos documentos*/
			{
    		    lectura>>pelis[contador].codigo;/*llamado de la variable*/
        		while (!lectura.eof()) /*mientras se pueda hacer el recorrido del documento*/
				{
    	            lectura>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreDirector>>pelis[contador].genero;
        	        if (pelis[contador].codigoAux == pelis[contador].codigo) /*comparacion en los registros del documento*/
					{
	                    encontrado = true; /*variable logica*/
						resta = x - alqui[contador].cantidadAlquilar;
						//guardado en aux
            	        aux<<pelis[contador].codigo<<" "<<pelis[contador].nombrePelicula<<" "<<resta<<" "<<pelis[contador].anio<<" "<<pelis[contador].nombreDirector<<" "<<pelis[contador].genero<<endl;
            	        /*mensaje de salida y su interaccion del usuario*/
						cout<<"\nFinalizando pedido. . .\n";
						cout<<"\nTiene 10 dias para entregar la pelicula alquilada\n";
	                }else
					{
        	            aux<<pelis[contador].codigo<<" "<<pelis[contador].nombrePelicula<<" "<<pelis[contador].cantidad<<" "<<pelis[contador].anio<<" "<<pelis[contador].nombreDirector<<" "<<pelis[contador].genero<<endl;
            	    }
	                lectura>>pelis[contador].codigo;/*llamado de la variable*/
    	        }
	    	}else
			{
		        cout<<"\nEl archivo no se pudo abrir\n"; /*mensaje de salida*/
		    }
		
    		if (encontrado == false)
			{
    	    	cout<<"\nNo hay ninguna pelicula con el codigo: "<<pelis[contador].codigoAux<<"\n"; /*mensaje de salida*/
	    	}
	
    		aux.close(); /*cierre del documento*/
    		lectura.close(); /*cierre del documento*/
	    	remove ("peliculas.txt"); /*eliminacion del documento*/
    		rename("auxiliar.txt", "peliculas.txt"); /*renombracion del docuemento*/
		}
	    
	    
	    contador++;
    	cout<<"\nDesea alquilar otra pelicula (s/n)?: ";
		fflush(stdin);
        cin>>respuesta; /*lectura de la respuesta del documento*/
			
	}while(respuesta =='S' or respuesta =='s');
}



/*funcion principal*/
int main()
	{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	
	int x;
	int logo[25][80] =
{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,1,0,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
	
	for(int i = 0; i<25; i++)
	{
		for(int j = 0; j<80; j++)
		{
			if(logo[i][j] == 1)cout<<char(219);
			else cout<<" ";
		}
		cout<<endl;
	}
	{
		system ("color B0");
		cout<<"\nCARGANDO: ";
		char x=219;
 		cout<<x;
		cout<<"";
 		for (int i=0;i<=35;i++)
			{
			cout<<x;
			Sleep(100);
		}
		cout<<endl; 
	}

	system ("cls");
	
    system ("color C"); /*cambio de la interfaz*/
    int n; /*declaracion de la variable*/
    system("cls"); /*limpieza*/
	cout<<"Bienvenido, antes de comenzar tenga encuenta las siguientes indicaciones:\n\nSiempre que vaya a llenar un campo ingrese la primera letra en mayuscula.\n\nPresione enter para continuar\n";
	getch();
    do{
    
	system("cls");/*limpieza*/
    system ("color C"); /*cambio de la interfaz*/
	    /*menu del usuario*/
	    cout<<"*******************************************"<<endl;
  		cout<<"Ingrese el numero segun lo que desea hacer: \n\n";
		cout<<"[1] Lista de peliculas"<<endl;
		cout<<"\n[2] Prestamo/alquiler de peliculas"<<endl;
		cout<<"\n[3] Buscar"<<endl;
		cout<<"\n[4] Opciones de administrador"<<endl;
		cout<<"\n[5] Salir\n\n"<<endl;
    	
    	cout<<"Elija una opcion: ";
    	fflush(stdin);
    	cin>>n; /*lectura de la opcion seleccionada del usuario*/
    	switch (n){
			case 1:
    			system("cls");
    			consultas(); /*funcion de inventario de las peliculas*/
   			break;
			
			case 2:
    			system("cls");
    			modificar(); /*funcion de alquiler de la pelicula*/
    			
    		break;
			
			case 3:
				system("cls");
    			buscar(); /*funcion de la busqueda en diferenteas aspectos*/
    		break;
			
			case 4:
				system("cls");
    			insertarpeliculas(); /*funcion de insertar peliculas*/
    		break;
			
			case 5:
				cout<<"\nSaliendo...\n";
				getch();
			break;
			
			default:
    			cout<<"Opcion equivocada\n";
    		break;
    	}
		/*fin switch*/
	}while (n != 5);

    system("cls"); /*limpieza*/
}
