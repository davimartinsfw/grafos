#include <iostream>
using namespace std;

#define MAX_LINES 5
#define MAX_COLUMNS 5

// Função para criar matriz
void matrizMatriz(int matriz[MAX_LINES][MAX_COLUMNS]) {
    // O loop for é utilizado para percorrer a matriz
    for(int l = 0; l < MAX_LINES; l++) {
        for(int c = 0; c < MAX_COLUMNS; c++) {
            matriz[l][c] = -1;  // Posição vazia inicializa com -1
        }
    }
}

void inserirMatriz(int matriz[MAX_LINES][MAX_COLUMNS], int lines, int columns, int valor) {
    // Testar se a posição na matriz existe
    if(lines >= 0 && lines < MAX_LINES && columns >= 0 && columns < MAX_COLUMNS) {
        matriz[lines][columns] = valor;
    } else {
        cout << "Matriz nao existe" << endl;
    }  
}

void buscMatriz(int matriz[MAX_LINES][MAX_COLUMNS], int valor) {
    for(int l = 0; l < MAX_LINES; l++) {
        for(int c = 0; c < MAX_COLUMNS; c++) {
            if(matriz[l][c] == valor) {
                cout << "Valor encontrado" << endl;
                return;
            }
        }
    }
    cout << "Valor nao encontrado" << endl;
}

// Função para remover um valor na matriz
void removMatriz(int matriz[MAX_LINES][MAX_COLUMNS], int lines, int columns, int valor) {
    // Testar se a posição na matriz existe
    if(lines >= 0 && lines < MAX_LINES && columns >= 0 && columns < MAX_COLUMNS) {
        // Verificar se o valor que vai ser removido existe na matriz
        if(matriz[lines][columns] == valor) {
            matriz[lines][columns] = -1; // Substitui o valor por -1
            cout << "Valor removido" << endl;
        } else {
            cout << "Valor nao removido" << endl;
        }
    }
}

// Função para imprimir a matriz
void mostraMatriz(int matriz[MAX_LINES][MAX_COLUMNS]) {
    for(int l = 0; l < MAX_LINES; l++) {
        for(int c = 0; c < MAX_COLUMNS; c++) {
            if(matriz[l][c] == -1) {
                cout << " _ ";
            } else {
                cout << " " << matriz[l][c] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int lines, columns;
    int op;
    int valor;

    int matriz[MAX_LINES][MAX_COLUMNS];
    matrizMatriz(matriz);
    cout << endl;
    
    do {
        cout << "Escolha uma opcao: " << endl;
        cout << "1- Inserir valor" << endl;
        cout << "2- Remover valor" << endl;
        cout << "3- Buscar valor" << endl;
        cout << "4- Mostrar matriz" << endl;
        cout << "0- Sair" << endl;
        cin >> op;

        switch(op) {
            case 1:
                cout << "Digite a linha, coluna e o valor: ";  
                cin >> lines >> columns >> valor; 
                inserirMatriz(matriz, lines, columns, valor);
                break;
            case 2:
                cout << "Digite a linha, coluna e o valor: ";  
                cin >> lines >> columns >> valor; 
                removMatriz(matriz, lines, columns, valor);
                break;
            case 3:
                cout << "Digite o valor a ser procurado: ";
                cin >> valor;
                buscMatriz(matriz, valor);
                break;
            case 4:
                mostraMatriz(matriz);
                cout << endl;
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida" << endl;
        }
    } while (op != 0);

    return 0;
}
