#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void deleteMatrix(int**, int);
int** createMatrix(int);
void printMatrix(int**, int);
bool PrimeNum(int);
int menu();
int posX(int);
int posY(int);
void llenar(int** , int);

int main(int argc, char const *argv[]) {
  bool salir = true;
  string player;
  cout<<"  HUMAN VS MACHINE"<<endl;
  cout<<"---------------------"<<endl;
  cout<<"Ingrese nombre de jugador: "<<endl;
  cin>>player;

  while(salir){
    switch (menu()) {
      case 1:{
        createMatrix(3);
        int** mat = createMatrix(3);
        llenar(mat, 3);
        printMatrix(mat, 3);
        break;
      }
      case 2:{
        break;
      }
      case 3:{
        break;
      }
      case 4:{
        salir = false;
        break;
      }
    }

  }
  return 0;
}

int** createMatrix(int size){
  int** matrix = new int* [size];

  for (int i = 0; i < size; i++) {
    matrix[i] = new int[size];
  }

  return matrix;
}

void printMatrix(int** matrix, int size){
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout<<"["<<matrix[i][j]<<"]";
    }
    cout<<endl;
  }
}

void deleteMatrix(int** matrix, int size){
  for (int i = 0; i < size; i++) {
    delete[] matrix[i];
    matrix[i] = NULL;
  }
  delete[] matrix;
}

bool PrimeNum(int num){
  bool prime = false;
  int cont = 0;

  for (int i = 0; i < num; i++) {
    if (num%i==0) {
      cont++;
    }
  }

  if (cont==2) {
    prime = true;
  }
  return prime;
}

int menu(){
  cout<<"1- Fácil   (Matriz de 2X2)"<<endl;
  cout<<"2- Medio   (Matriz de 3X3)"<<endl;
  cout<<"3- Difícil (Matriz de 4X4)"<<endl;
  cout<<"4- Salir "<<endl;
  cout<<endl;
  cout<<"Ingrese una opción"<<endl;
  int op=0;
  cin>>op;
  return op;
}

//Funcion para validar que la posicion de x este dentro de la matriz
int posX(int size){
  int x;
  cout<<"Ingrese posicion en X"<<endl;
  cin>>x;
  while(x>size||x<0){
    cout<<"Posicion inexistente, intente de nuevo"<<endl;
    cin>>x;
  }
  return x;
}

//Funcion para validar que la posicion de Y este dentro de la matriz
int posY(int size){
  int y;
  cout<<"Ingrese posicion en Y"<<endl;
  cin>>y;
  while(y>size||y<0){
    cout<<"Posicion inexistente, intente de nuevo"<<endl;
    cin>>y;
  }
  return y;
}

void llenar(int** mat, int size){
  int cont = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      mat[i][j] = cont;
      cont++;
    }
  }
}
