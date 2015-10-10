#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

void crear_matriz(int **&Matriz,int fil,int col){
	Matriz = new int*[fil];					
	for(int i=0 ; i<fil ;i++)
		Matriz[i] = new int[col];
	
	for(int i = 0 ;i < fil; i++){		
		for(int j = 0; j < col; j++){
			cout <<"Matriz["<<i<<"]["<<j<<"]= ";
			cin>>*(*(Matriz+i)+j);
		}
		cout <<endl;
	}
}

void print_matriz(int **&Matriz,int fil,int col)	{
	for(int i=0;i<fil;i++){
		for(int j=0;j<col;j++){
		
			cout<<*(*(Matriz+i)+j)<<" ";
		}
		cout<<endl;
	}
}
void productMatrix(int **&Matriz1, int **&Matriz2,int fil,int col,int fil2,int col2)
{
    if (col == fil2)
	{							
    	int **matriz_prod;
		matriz_prod = new int*[fil];			
		for(int i=0 ; i<fil ;i++)
			matriz_prod[i] = new int[col2];	
		

		for (int cc=0; cc<col2; cc++)
		{		
			for (int i = 0; i < fil; i++)
			{
				// C[i][j] = 0;
				 	*(*(matriz_prod+i)+cc)=0;
				for (int j = 0; j < col; j++)
				{
					
					*(*(matriz_prod+i)+cc) += *(*(Matriz1+i)+j) * *(*(Matriz2+j)+cc);		//Esto es lo mismo q la linea anterior
				}
			}    
		
			print_matriz(matriz_prod,fil,col2);
		}
	}

	else
	{
			cout << "No se puede multiplicar ....  " << endl;
	}
    
	       
}
int main()
{
	int fil,col,**M1,fil2,col2,**M2;
	cout<<"Num. Filas de la matriz 1er Matriz : "; cin>>fil;
	cout<<"Num. Columnas de la 1er matriz : "; cin>>col;
	crear_matriz(M1,fil,col);

	
	cout<<"Num. Filas de la matriz 2da Matriz : "; cin>>fil2;
	cout<<"Num. Columnas de la 2da matriz : "; cin>>col2;
	crear_matriz(M2,fil2,col2);

	
	productMatrix(M1,M2,fil,col,fil2,col2);
	
	
/*// Elimino cada vector de la matriz					
	for(int i=0 ; i<fil ;i++)
			delete[]	Matriz[i] ;
			
	// Elimino el vector principal		
	delete[] Matriz;	*/
	 
    
 
	return 0;
}
