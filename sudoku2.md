# Sudoku Adventures, Part II

## Um pedido de perd\~ao

Pe\c co desculpas por ter ficado tanto tempo sem continuar nossa saga
pela resolu\c c\~ao do sudoku. Andei muito ocupado.

Uma imagem vale mais do que mil palavras:

[http://25.media.tumblr.com/2c2413303481d2e0d59543377bde2fdb/tumblr_mgoiw6Vnir1qhffcio4_250.gif]

## *In the beginning, there was the IO*

### Um arquivo sudoku

Vamos come\c car falando como representaremos um sudoku no
computador. N\'os vamos usar um arquivo de texto com 9 linhas e 9
colunas, cada uma representando uma das 81 posi\c c\~oes de um
sudoku.

H\'a duas possibilidades para cada posi\c c\~ao: ser um n\'umero de 1
a 9 ou ser um 0. Se ela for 0, n\'os temos que preencher aquela posi\c
c\~ao para resolver o jogo. Caso contr\'ario, se o n\'umero
n\~ao for 0, aquela posi\c c\~ao \'e dada e n\'os n\~ao vamos mexer
nela.

Por exemplo,
[neste link](http://www.websudoku.com/?level=1&set_id=3440913915),
temos um sudoku que eu achei no google. A representa\c c\~ao dele no
nosso arquivo de texto "sudoku.txt" \'e a seguinte:

~~~
4 0 6 0 0 9 8 0 3
0 2 0 0 0 6 0 0 5
9 0 5 0 1 0 0 0 0
0 7 1 0 3 5 0 0 0
2 9 0 0 0 0 0 1 8
0 0 0 1 9 0 6 3 0
0 0 0 0 5 0 9 0 2
8 0 4 4 0 0 0 5 0
1 0 2 9 0 0 4 0 6
~~~

Bem simples, certo? Eu s\'o coloquei zeros nos lugares vazios!

[http://i.imgur.com/KTG1E.gif]

## Guardando um sudoku no nosso programa

Um sudoku \'e, se voc\^e lembra da escola, uma matriz! Matriz \'e um
nome chique para tabela (OK, uma matriz \'e mais que uma tabela, mas
para n\'os \'e uma tabela). Logo, n\'os s\'o precisamos fazer uma
~~matriz~~, err, tabela.

Em C++, \'e muito simples fazer uma tabela que guarda n\'umeros:

~~~ {.cpp}
int tabela[lin][col];
~~~

Isso faz a vari\'avel sudoku ser uma tabela com "lin" linhas e "col"
colunas. Um sudoku cl\'assico sempre tem 9 linhas e 9 colunas, logo:

~~~ {.cpp}
int sudoku[9][9];
~~~

F\'acil, certo? Ent\~ao, vamos ao que interessa!

[http://i.imgur.com/WIQHEa1.gif]

## Lendo um arquivo txt com um sudoku

Ler um arquivo em C++ \'e f\'acil. N\~ao acho que os detalhes sejam
relevantes para resolver o sudoku, ent\~ao s\'o vou
colocar o peda\c co do programa que faz isso aqui:

~~~ {.cpp .numberLines}
void ler_sudoku(int sudoku[][9], char nome[128]) {
    ifstream arquivo(nome, ifstream::in);
    for (unsigned i = 0; i < 9; i++) {
        for (unsigned j = 0; j < 9; j++) {
            arquivo >> sudoku[i][j];
        }
    }
}
~~~

Essa fun\c c\~ao vai ler na matriz sudoku o jogo representado no
arquivo chamado nome. Agora j\'a sabemos ler um sudoku!

Mas calma, seria bom tamb\'em conserguirmos ver nosso sudoku resolvido
depois de todo esse esfor\c co!

~~~ {.cpp .numberLines}
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
~~~

As duas fun\c c\~oes fazem basicamente a mesma coisa: elas andam por
cada elemento da tabela da seguinte forma: para cada linha, n\'os
olhamos todas as colunas. Se for a fun\c c\~ao de ler, n\'os lemos os
elementos na tabela. Se for a de imprimir, n\'os imprimimos o
elemento. O \'unico detalhe \'e que a fun\c c\~ao de imprimir tem os
detalhes para a impress\~ao ficar bonitinha. :)

## Por enquanto \'e s\'o

Como eu disse, ando muito ocupado, ent\~ao por hoje \'e s\'o.

[http://i.imgur.com/TghktaI.gif]

Da pr\'oxima vez, n\'os vamos terminar, pelo menos!

Por enquanto, voc\^e pode copiar e colar o c\'odigo que l\^e e imprime
e brincar com ele! O c\'odigo
[est\'a aqui](https://github.com/lvirgili/blog_profes/blob/master/sudoku.cpp).

At\'e!

[http://i2.kym-cdn.com/photos/images/original/000/121/082/129186356702112200.jpg]
