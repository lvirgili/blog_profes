#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

void ler_sudoku(int sudoku[][9], char nome[128], vector< pair<int, int> >& vazios) {
    ifstream arquivo(nome, ifstream::in);
    for (unsigned i = 0; i < 9; i++) {
        for (unsigned j = 0; j < 9; j++) {
            arquivo >> sudoku[i][j];
            if (sudoku[i][j] == 0) {
                vazios.push_back(make_pair(i, j));
            }
        }
    }
}

void imprimir_sudoku(int sudoku[][9]) {
    for (unsigned i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            for (unsigned j = 0; j < 9; j++) {
                cout << "===";
            }
            cout << endl;
        }
        for (unsigned j = 0; j < 9; j++) {
            if (j == 0) {
                cout << "| ";
            }
            if (j > 0 && j % 3 == 0) {
                cout << " | ";
            }
            cout << sudoku[i][j] << ' ';
            if (j == 8) {
                cout << "|\n";
            }
        }
    }
    for (unsigned i = 0; i < 9; ++i) {
        cout << "===";
    }
    cout << endl;
}

bool conflito_linha(int sudoku[][9], int i, int j) {
    // agora vamos olhar!
    for (int coluna = 0; coluna < 9; coluna++) {
        if (coluna != j && sudoku[i][coluna] == sudoku[i][j]) {
            // se entrarmos nesse if nos achamos um erro :(
            return true;
        }
    }
    // se a gente chegou aqui e pq nao tem erro!
    return false;
}

bool conflito_coluna(int sudoku[][9], int i, int j) {
    // agora vamos olhar!
    for (int linha = 0; linha < 9; linha++) {
        if (linha != i && sudoku[linha][j] == sudoku[i][j]) {
            // se entrarmos nesse if nos achamos um erro :(
            return true;
        }
    }
    // se a gente chegou aqui e pq nao tem erro!
    return false;
}

bool conflito_subquadrado(int sudoku[][9], int i, int j) {
    // Vamos achar o primeiro elemento do quadrado!
    int linha_primeiro = (i / 3) * 3;
    int coluna_primeiro = (j / 3) * 3;

    // agora so precisamos olha os 9 elementos do quadrado!
    for (int linha = linha_primeiro; linha < (linha_primeiro + 3); linha++) {
        for (int coluna = coluna_primeiro; coluna < (coluna_primeiro + 3); coluna++) {
            if (linha == i && coluna == j) {
                continue;
            } else {
                if (sudoku[i][j] == sudoku[linha][coluna]) {
                // achamos conflito :(
                return true;
                }
            }
        }
    }
    // sem conflitos!
    return false;
}

bool conflito(int sudoku[][9], int i, int j) {
    return (conflito_linha(sudoku, i, j) ||
            conflito_coluna(sudoku, i, j) ||
            conflito_subquadrado(sudoku, i, j));
}

void resolve(int sudoku[][9], vector< pair<int, int> >& vazios) {
    unsigned it = 0;
    // enquanto nao conseguirmos preencher o ultimo cara
    while (it < vazios.size()) {
        int i = vazios[it].first;
        int j = vazios[it].second;
        // Estamos agora no cara ij
        if (sudoku[i][j] == 9) {
            sudoku[i][j] = 0;
            --it;
            continue;
        }
        sudoku[i][j]++;
        if (conflito(sudoku, i, j) == false) {
            ++it;
        }
    }
}


int main() {
    char nome[128];
    int sudoku[9][9];
    vector< pair<int, int> > vazios;
    cout << "Qual e o nome do arquivo? ";
    cin >> nome;
    ler_sudoku(sudoku, nome, vazios);
    resolve(sudoku, vazios);
    imprimir_sudoku(sudoku);
    return 0;
}
