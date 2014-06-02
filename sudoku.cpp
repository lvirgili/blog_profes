#include <iostream>
#include <fstream>
using namespace std;

void ler_sudoku(int sudoku[][9], char nome[128]) {
    ifstream arquivo(nome, ifstream::in);
    for (unsigned i = 0; i < 9; i++) {
        for (unsigned j = 0; j < 9; j++) {
            arquivo >> sudoku[i][j];
        }
    }
}

void imprimir_sudoku(int sudoku[][9]) {
    for (unsigned i = 0; i < 9; i++) {
        for (unsigned j = 0; j < 9; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    char nome[128];
    int sudoku[9][9];
    cout << "Qual e o nome do arquivo? ";
    cin >> nome;
    ler_sudoku(sudoku, nome);
    imprimir_sudoku(sudoku);
    return 0;
}
