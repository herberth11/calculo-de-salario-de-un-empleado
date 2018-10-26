/*codigo fuente: programa de control de datos de un empleado
desarrollado por: Herberth Ovidio Jurado Maradiaga
carnet: JM18006*/
#include <iostream>
#include <windows.h>
#include <stdlib.h>

 using namespace std;
 
 //estructura de datos
 struct empleados{
 	//tipos de datos simples
 	char codigo[7];//arreglo para los datos del empleado
 	char nombres[50];
 	int edad;
 	float salbase;
 	float salliquido;
 	float isss;
 	float afp;
 	float renta;
 	float totalprestamos;
 	char departamento[60];
 	char puesto[60];
 	float sobreporsb;
 };
 //esta estructura la creamos para pedir elnombre de la sucursal, y el numero
 struct sucursal{
 	int numsucursal;
 	char nombsucursal[60];
 };
 
 //declaracion de funciones
float calisss(float sal, float tope);
 //crear las funciones para el calculo del isss, afp, renta
float calafp(float sal);

float calrenta(float sal);

float prestamos(float sal);

float salliq(float sal, float isss, float afp, float renta, float pres);
 
int main() {
	int con;
	int n;//aqui se almacenara el numero de empleados que posee la empresa
	int cp;//aqui se almacenaran la cantidad de prestamos
	int contador;
	float totpres;
	int pres;
	sucursal s;//esta es una variable para almacenar la sucursar a la que prestenece los datos ingresados del empleado
	
	cout << "                        BIENVENIDO AL SISTEMA" << endl;//le damos la bienvenida al usuario
	do
	{
		cout << "numero de sucursal: " << endl;//pedimos el numero de la sucursal
	    cin >> s.numsucursal;
	    while (cin.fail()){//validamos el ingreso de solo datos numericos
	    	system("cls");
	    	cin.clear();
	    	cin.ignore(1000,'\n');
	    	cout << "Error de datos, intente de nuevo" << endl;
		}
	}while(s.numsucursal <= 0);//como las sucursales no pueden o no deben tener numeros
	//negativos validamos que los numeros sean siempre positivos
	cout << "nombre de la sucursal" << endl;//pedimos el nombre
	cin >> s.nombsucursal;
	cout << "cuantos empleados tiene?" << endl;//le pedimos la cantidad de empleados que posee la empresa
	cin >> n;
	
	empleados e[n];//aqui declaramos la variable e de tipo empleados que es la estructura que creamos
	//de esta forma se implementan las estructuras
	
	for (int i=0; i<n; i++){//mediante este for le pediremos al usuario los datos de los empleados en base a la
	//cantidad de empleados que ingreso que posee
		cout << "codigo: " << endl;//le pedimos el codigo del empleado
		cin >> e[i].codigo;
		
		cout << "nombre: " << endl;//nombre del empleado
		cin >> e[i].nombres;
		do
		{
			cout << "edad: " << endl;//edad
		    cin >> e[i].edad;
		    while (cin.fail()){
		    	cin.clear();
		    	cin.ignore(1000, '\n');
                cout << "edad invalida, intentelo de nuevo" << endl;
			}
		}while (e[i].edad < 18);//volvemos a validar
		
		cout << "departamento: " << endl;//pedimos el nombre del departamento
		cin >> e[i].departamento;
		
		do
		{
			cout << "puesto: " << endl;//puesto de trabajo, en erste caso seria el numero de puesto
		    cin >> e[i].puesto;
		    while(cin.fail()){
		    	cin.clear();
		    	cin.ignore(1000, '\n');
		    	cout << "puesto invalido, ingrese datos numericos" << endl;
			}
		}while(e[i].puesto<=0);
		do
		{
			cout << "salario base: " << endl;//el salario base o salario nominal
		    cin >> e[i].salbase;
		    while (cin.fail()){
		    	cin.clear();
		    	cin.ignore(1000, '\n');
		    	cout <<"salario invalido, intente de nuevo" << endl;
			}
		}while (e[i].salbase<300);//se condiciona que se repita el ciclo cuando sea menor a 300
		//por que es el salario minimo del pais
		
			do
	        {
		        cout << "cantidad de prestamos." << endl;
	            cin >> cp;
	            while(cin.fail()){
	         	cin.clear();
	        	cin.ignore(1000, '\n');
	        	cout << "error al ingresar datos\n intentelo de nuevo" << endl;
		        }
	        }while(cp<0);
	        con = 0;
	        
	         while (con < cp){
	         	cout << "monto a descontar" << endl;
	         	cin>>pres;
	         	totpres=totpres+pres;
	         	
	         	if (e[i].salbase*0.2>totpres){
	         		e[i].totalprestamos=totpres;
				 }
				 else
				 {
				 	/*si el total de prestamos no es igual al o menos al 20% del salario base debemos de calcular
					 a cuanto equivale el 20% del salario base y encontra y luego restarlo del total de prestamos
					 para luego restarcelo al saario base*/
					 /*crearemos variables para calcular el porcentaje del salario base luego crearemos otra para 
					 calcular lo que sobrepasa del 20% y finalmente le restaremos lo que sobrepasa del 20% para encotrar el
					 monto total a descontar que hemos almacenado en la variable e[i]totalprestamos*/
					 float porsb;
					 porsb=e[i].salbase*0.2;
					 e[i].sobreporsb=totpres-porsb;
					 e[i].totalprestamos=totpres-e[i].sobreporsb;
				 }
				 con++;
			 }
		e[i].isss=calisss(e[i].salbase,1000);//le damos el valor al isss 
		e[i].afp=calafp(e[i].salbase);//le damos el valos al afp y asi a las siguientes
		e[i].renta = calrenta(e[i].salbase);
		e[i].salliquido=salliq(e[i].salbase, e[i].isss, e[i].afp, e[i].renta, e[i].totalprestamos);
		
	}
	
	
	system("cls");
	for (int i=0; i<n; i++){//aqui imprimimos los valores ingresados en el for anterior
        cout << "numero de sucursal: " << s.numsucursal << endl;
        
        cout << "nombre de la sucursal: " << s.nombsucursal << endl;
        
		cout << "codigo: " << e[i].codigo<< endl;
		
		cout << "nombre: " << e[i].nombres<< endl;
		
		cout << "edad: " << e[i].edad<< endl;
		
		cout << "departamento: " << e[i].departamento << endl;
		
		cout << "puesto: " << e[i].puesto << endl;
		
		cout << "salario base: " << e[i].salbase << endl;
		
		cout << "isss: " << e[i].isss << endl;
		
		cout << "afp: " << e[i].afp << endl;
		
		cout << "renta: " << e[i].renta << endl;
		
		cout << "total descuentos de prestamos: " << e[i].totalprestamos<< endl;
		
		cout << "presatamo restantes de pago: " << e[i].sobreporsb << endl;
		
		cout << "salario liquido: " << e[i].salliquido << endl;
		/*cabe destacar que al valor del salario liquido que se imprime en pantalla no se le
		an aplicado la resta de los prestamos debido al problema que se ha explicado anteriormente*/
	}
	
	return 0;
}


//implementacion de funciones
float calisss(float sal, float tope){
 	
 	float isss=0;/*declare la variable isss de tipo flotante debido aque el
	 isss no siempre sera un entero, cabe destacar que el isss siempre sera positivo
	 por lo que deberia ser de tipo entero y luego convertirlo a flotante para
	 poder presentarlo con decimales, pero para no hacer tan extensa la funcion lo declarare de
	 una ve de tipo flotante*/
 	if (sal >= 1000){ /*mil es el tope del isss es decir, que si el empleado
	 gana mil o mas el nonto fijo a descontar del isss es de 30 dolares*/
 		isss=30;
	 }
	 else
	 {/*si el empleado gana menos de mil entonces se le aplica el 3% al
	 salario nominal ese sera el valor equivalente al isss*/
	 	isss=sal*0.03;
	 }
	 return isss;
 }
 
 float calafp(float sal){
 	/*el afp actualmente equivale al 7.25% que paga el empleado por lo
	 que el valor del afp se calcula multiplicando el valor del salario nominal
	 por el porcentaje de afp y ese sera el valor a descontar*/
	 float afp;/*delcararemos la variable afp de tipo flotante por la misma razon que declaramos
	 la variable isss de tipo flotante en la funcion calisss*/
	 /*para calcular el afp necesitaremos el salario base razon por la cual la funcion recibe
	 los datos de la bariable sal representa el valor del salario*/
	 /*el afp como antes lo mencione es igual al 7.25% por los que es afp sera igual a multiplicar el
	 valor almacenado el sal por el 7.25%*/
	 afp = sal * 0.0725;
	 return afp;
 }
 
 float calrenta(float sal){
    /*la renta se calcula mediente una table proporcinado por el ministerio de hacienda
	la cual se presenta a continuacion.
	a los que ganan de        a                         aplicar
	$0.01--------------------$472.00---------------------sin renta
	$472.01------------------$895.24---------------------10% sobre lo que sobrepasa de $472.00 mas cuota fija de $17.67
	$895.25------------------$2038.10--------------------20% sobre lo que sobrepasa de $895.24 mas cuota fija de $60.00
	$2038.11-----------------mas-------------------------30% sobre lo que sobrepasa de $2038.10 mas cuota fija de $253.37*/
	
	float renta;
    if (sal >=0.01 && sal <=472.00){
    	cout << "no se aplica renta" << endl;
    	renta=0;
	}
	else if (sal >=472.01 && sal <=895.24){
		renta = ((sal - 472.00) * 0.1)+17.67;
	}
	else if (sal >=895.25 && sal <=2038.10){
		renta = ((sal - 895.24) * 0.2)+60;
	}
	else if(sal >= 2038.11){
		renta = ((sal - 2038.10) * 0.2)+253.37;
	}
	return renta;
 }
 
 float salliq(float sal, float isss, float afp, float renta, float pres){
 	/*el salrio liquido lo calcularemos restando al salario nominal el total de
	 la suma de todas las dedcciones*/
 	float salliquido;
 	salliquido = sal - (isss + afp + renta + pres);
 	
 	return salliquido;
}
