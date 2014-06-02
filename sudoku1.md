# Sudoku Adventures, Part I

## *All work and no play makes Jack a dull boy*

Come\c car a aprender a programar \'e chato. \'E como aprender uma
nova l\'ingua: no come\c co, n\~ao sabemos nem o vocabul\'ario
simples, quem dir\'a falar uma frase completa.

Com programa\c c\~ao \'e a a mesma coisa, infelizmente. No come\c co,
temos dificuldade em dizer para o computador realizar tarefas simples
como s\'o imprimir algo na tela ou fazer uma conta! Tanto \'e que os
alunos usualmente ficam com uma cara mais ou menos assim:

[http://i.imgur.com/p2T29QE.gif]

Mas com uma quantidade impressionantemente pequena de palavras e
"estruturas gramaticais" \'e poss\'ivel fazer, bom, tudo! Afinal o
computador \'e muito burro, lembra?

[http://i.imgur.com/cmHUC.gif]

Assim, depois de umas 4 ou 5 aulas j\'a podemos fazer coisas legais
como um programa que resolve um sudoku!

## Itiner\'ario

Como tudo que \'e interessante de se resolver, n\~ao podemos resolver
o sudoku sem pensar um pouco. Por isso, vou dividir nossa "viagem" nos
seguintes passos:

	1. Entender o que \'e "resolver um sudoku";
	2. Pensar em uma solu\c c\~ao para o problema;
	3. Dividir a solu\c c\~ao de um sudoku em problemas menores;
	4. Converter esses problemas em fun\c c\~oes e testarmos uma por uma; e
	5. Juntar nossas fun\c c\~oes e resolver o problema!

Basicamente, resolver um problema usando programa\c c\~ao sempre
envolve esses passos: primeiro, temos que entender o problema que
vamos resolver, depois o quebramos em problemas menores, os quais
resolvemos um por um, para termos certeza que fizemos tudo certo.  No
fim, juntamos tudo e puff!, temos nossa solu\c c\~ao para o problema
original!

[http://i.imgur.com/Mk76H.gif]

## Sudoku

### O problema

Um jogo de sudoku \'e bem simples: temos uma tabela com 9 linhas e 9
colunas, que \'e dividida em 9 subtabelas de 3 linhas e 3
colunas. Nessa tabela, temos alguns n\'umeros colocados para n\'os, e
nosso trabalho \'e o seguinte: temos que preencher o resto da tabela
de forma que cada linha, cada coluna e cada subtabela tenha os
n\'umeros de 1 a 9 **exatamente uma vez**. Ou seja, em uma dada linha,
coluna ou subtabela n\~ao pode haver repeti\c c\~ao de n\'umeros.


### A solu\c c\~ao

Algo que n\~ao falta no mundo s\~ao jeitos de resolver sudokus com o
computador. Por isso mesmo, vamos fazer do jeito mais simples, que
aproveita o que o computador faz melhor: repetir instru\c c\~oes
simples.

Veja s\'o como iremos fazer: n\'os vamos come\c car no primeiro
quadrado vazio da tabela e colocar o n\'umero $1$. Brilhante, n\~ao?
Depois, n\'os vamos checar se j\'a havia um $1$ na mesma linha, coluna
ou submatriz daquele quadrado. Se n\~ao, maravilha, n\'os vamos para o
pr\'oximo quadrado vazio e colocamos, advinhe, outro $1$!

[http://i.imgur.com/l2sJi.gif]

O que acontece \'e que se encontrarmos o mesmo n\'umero na linha,
coluna ou subtabela, n\'os simplesmente tentamos com o pr\'oximo e
depois o pr\'oximo e depois o pr\'oximo, at\'e que consigamos encaixar
um n\'umero no maldito quadrado que n\~ao est\'a repetido. N\'os
fazemos isso at\'e o final da tabela e, bumba meu boi, resolvemos um
sudoku!

[http://i.imgur.com/pm8gm.gif]

O \'unico problema \'e que podemos, em algum quadrado, n\~ao conseguir
colocar nenhum n\'umero (ou seja, tentamos at\'e $9$ e todos os
n\'umeros j\'a apareciam na mesma linha, coluna ou subtabela). :( Mas
n\~ao se despespere! Basta deixarmos esse quadrado em branco e
voltarmos para o \'ultimo quadrado que preenchemos com algum n\'umero
e colocar o pr\'oximo n\'umero nele. Se n\~ao conseguirmos colocar
nada nesse quadrado tamb\'em, voltamos para o anterior e colocamos o
pr\'oximo n\'umero nele e assim at\'e conseguirmos colocar algum
n\'umero sem problemas!

Eu admito, n\~ao \'e o jeito mais elegante de se resolver um
sudoku. OK, \'e o mais porco. Mas acredite em mim quando eu digo que
funciona!

[http://i.imgur.com/CgrMo.gif]

No pr\'oximo post dessa s\'erie n\'os vamos converter essa coisa de
colocar $1$, depois $2$ e ir para o pr\'oximo e deixar em branco e
voltar em problemas menores, para depois juntarmos tudo e resolver um
sudoku.

Ent\~ao aguarde o pr\'oximo epis\'odio, nesse mesmo canal, nesse mesmo
hor\'ario para vermos como vamos, como dizia nosso amigo Jack, ir por
partes.

[http://i.imgur.com/YtKWRKk.gif]
