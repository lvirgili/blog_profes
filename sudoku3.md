# Sudoku Adventures, Part III

## No passado
Nas nossas duas \'ultimas n\~ao muito emocionante aventuras n\'os
vimos como vamos resolver o sudoku e como faz\'iamos para ler um
arquivo de sudoku.

Agora vamos finalmente resolver o sudoku!

[http://i.imgur.com/JkOzKst.gif]

## Achando "conflitos"
Se voc\^e se lembra de como vamos resolver o sudoku (se voc\^e n\~ao
lembrar, leia aqui \'o!), n\'os vamos, basicamente, chutar os
n\'umeros! Ent\~ao precisamos de um jeito para ver se o n\'umero que a
gente chutou pode ficar no quadrado onde a gente o colocou ou n\~ao.

Para isso, n\'os precisamos ver se n\~ao h\'a o mesmo n\'umero na
linha, na coluna ou no "sub-quadrado" do n\'umero que a gente colocou.

Vamos fazer isso por partes. Primeiro vamos checar a linha. Cada
elemento da tabela que representa o sudoku tem dois \'indices, i e j,
certo? O \'indice i \'e a linha e o j \'e a coluna. Logo, a linha da
posi\c c\~ao ij \'e a linha i! Vamos fazer uma fun\c c\~ao que olha
todos os elementos da linha i e comparamos com o n\'umero que a gente
chutou para o elemento ij. Se algum for igual, n\'os vamos retornar
true, ou seja, que achamos um conflito!

~~~ {.cpp .numberLines}
bool conflito_linha(int sudoku[][9], int i, int j) {
    int valor = sudoku[i][j]; // numero que chutamos para o ij
    // agora vamos olhar!
    for (int coluna = 0; coluna < 9; coluna++) {
        if (coluna != j && sudoku[i][coluna] == valor) {
            // se entrarmos nesse if nos achamos um erro :(
            return true;
        }
    }
    // se a gente chegou aqui e pq nao tem erro!
    return false;
}

Nessa fun\c c\~ao, n\'os olhamos todos os elementos da linha i, usando
a vari\'avel coluna para marcar cada um. S\'o temos que ter cuidado
para n\~ao olhar a coluna j, j\'a que sempre ter\'iamos um conflito!

Agora vamos fazer o mesmo para checar se h\'a um conflito na mesma
coluna de ij. Como j \'e a coluna, basta olharmos todas as linhas!

~~~ {.cpp .numberLines}
bool conflito_coluna(int sudoku[][9], int i, int j) {
    int valor = sudoku[i][j]; // numero que chutamos para o ij
    // agora vamos olhar!
    for (int linha = 0; linha < 9; linha++) {
        if (linha != i && sudoku[linha][j] == valor) {
            // se entrarmos nesse if nos achamos um erro :(
            return true;
        }
    }
    // se a gente chegou aqui e pq nao tem erro!
    return false;
}
~~~

Agora precisamos olhar o subquadrado! Isso \'e um pouco mais chato,
j\'a que dependendo da posi\c c\~ao ij do elemento, o subquadrado
varia!

O jeito que eu acho mais f\'acil para olhar o subquadrado \'e assim:
n\'os identificamos cada um deles pela posi\c c\~ao do primeiro
elemento da primeira linha de cada um: (0,0) para o primeiro, (0,3)
para o segundo da primeira linha, (0,6) para o terceiro e depois (3,0)
para o primeiro da segunda linha ate chegarmos no quadrado (6,6).

Como fazemos para identificar esse elemento? \'E simples! N\'os
, primeiro, dividimos i e j por 3. Depois, n\'os multiplicamos por 3!

[http://i.imgur.com/ElCPi.gif]

Voc\^e tem que lembrar que em C++ divis\~ao funciona como a divis\~ao
da quarta s\'erie: 7 dividido por 3 d\'a 2 e sobra 1, certo? Logo, 7
dividido por 2 vezes 3 d\'a 6! Fazendo isso a gente sempre acha o
quadrado certo!

[http://i.imgur.com/GTdVD4o.gif]

O que n\'os vamos fazer ent\~ao \'e, dada nossa posi\c c\~ao ij,
encontrar qual o primeiro elemento do subquadrado que o ij
est\'a. Depois, n\'os olhamos os 9 elementos desse subquadrado (com
cuidado para ignorar o ij!) e vemos se achamos o erro.

~~~ {.cpp .numberLines}
bool conflito_subquadrado(int sudoku[][9], int i, int j) {
    int valor = sudoku[i][j];
    // Vamos achar o primeiro elemento do quadrado!
    int linha_primeiro = (i / 3) * 3;
    int coluna_primeiro = (j / 3) * 3;

    // agora so precisamos olha os 9 elementos do quadrado!
    for (int linha = linha_primeiro; linha <= (linha_primeiro + 3); linha++) {
        for (int coluna = coluna_primeiro; coluna <= (coluna_primeiro + 3); coluna++) {
            if (!(linha == i && coluna == j) && sudoku[linha][coluna] == valor) {
                // achamos conflito :(
                return true;
            }
        }
    }
    // sem conflitos!
    return false;
}
~~~

Agora s\'o precisamos juntar essas 3 fun\c c\~oes de verificar para
ver se o n\'umero que chutamos pode ficar no lugar que a gente colocou
ele ou n\~ao! Como um conflito (dentre os 3 poss\'iveis) j\'a ferra
tudo, podemos simplesmente ver se algum deles retornou verdadeiro:

~~~ {.cpp .numberLines}
bool conflito(int sudoku[][9], int i, int j) {
    return conflito_linha(sudoku, i, j) ||
        conflito_coluna(sudoku, i, j) ||
        conflito_subquadrado(sudoku, i, j);
}
~~~

Pronto!

[http://i.imgur.com/CWgMf.gif]

## Mudando um pouco nossa leitura
N\'os precisamos mudar um pouco a fun\c c\~ao que l\^e nosso sudoku,
porque precisamos guardar uma lista das posi\c c\~oes ij da tabela que
n\~ao s\~ao fixas, ou seja, que devemos preencher.

Para isso, vamos usar um vector do C++. Ela vai guardar pares,
tamb\'em do C++, que v\~ao ter dois n\'umeros, o i e o j (eu n\~ao vou
usar listas porqu\^e n\~ao quero usar iteradores XD).

A \'unica coisa que precisamos mudar na nossa fun\c c\~ao de leitura
\'e que, toda vez que acharmos um 0, que representa um buraco, n\'os
guardamos o par ij na nossa lista de vazios.

~~~ {.cpp .numberLines}
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
~~~

Como eu disse, a \'unica diferen\c ca \'e que quando lemos um 0 na
posi\c c\~ao ij n\'os colocamos na nossa lista de vazios o par ij.

## Resolvendo o sudoku!
Agora n\'os temos tudo que precisamos, finalmente, para resolver o
sudoku!

[http://i.imgur.com/n1CuNzn.gif]

Para resolver a gente vai fazer assim: n\'os pegamos o primeiro par ij
na nossa lista de vazios e colocamos o n\'umero 1 nele. Depois
checamos se aconteceu algum conflito: se estiver tudo bem n\'os
pegamos o pr\'oximo cara da lista e colocamos 2 e assim por diante. Se
n\'os tivermos um conflito, n\'os somamos 1 no cara ij. Caso n\'os
sejamos muito azarados, algum par ij n\~ao vai poder ser preenchido
com nenhum n\'umero at\'e 9. Mas n\~ao se desespere! Basta n\'os
voltarmos para o cara anterior e aumentarmos ele de um! N\'os
repetimos isso at\'e conseguirmos colocar algum n\'umero no \'ultimo
cara da lista de vazios!

Finalmente, nossa fun\c c\~ao resolve!

~~~ {.cpp .numberLines}
void resolve(int sudoku[][9], vector< pair<int, int> >& vazios) {
    unsigned it = 0;
    // enquanto nao conseguirmos preencher o ultimo cara
    while (it < vazios.size()) {
        int i = vazios[it].first;
        int j = vazios[it].second;
        // Estamos agora no cara ij
        // se ele for 9 ja era!
        if (sudoku[i][j] == 9) {
            sudoku[i][j] = 0;
            --it;
            continue;
        }
        sudoku[i][j]++;
        if (conflito(sudoku, i, j) == false) {
            // se nao der conflito maravilha! proximo!
            ++it;
        }
    }
}
~~~

S\'o falta escrevermos nossa fun\c c\~ao main:

~~~ {.cpp .numberLines}
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
~~~

E pronto! Espero que voc\^e tenha gostado e aprendido que, \`as vezes,
a solu\c c\~ao mais porca \'e o suficiente!

[http://media.giphy.com/media/c8YC8htf5YQg0/giphy.gif]
