# Binário, o retorno, ou como converter de binário para decimal

[http://i.imgur.com/C0j81Al.jpg]

## Cenas do último episódio

No meu
[último post](https://br.portalprofes.com/lvirgili/blog/binario-a-lingua-do-computador),
expliquei como funcionam as bases 2 e 10. Se
você ainda não leu, vou dar um tempo para você ler.

[http://i.imgur.com/BZOGC.gif]

## Convertendo de base 2 para base 10

Como eu sou um excelente professor, você já sabe converter de base 2
para base 10! (Assumindo que você fez os exercícios :P)

[http://i.imgur.com/iEN2gIh.gif]

Você não percebeu? Mas você já sabe! Vamos revisar o exemplo que
estava no post anterior.

O que o número $101010_b$ (o "bezinho" significa que o número está em
binário) representa em base 10? Nós já fizemos, lembra?

$101010 = ( 1 \times 2 ^ 5 ) + ( 0 \times 2 ^ 4 ) + ( 1 \times 2 ^ 3
) + ( 0 \times 2 ^ 2 ) + ( 1 \times 2 ^ 1 ) + ( 0 \times 2 ^ 0 )$

Ou seja, a partir da direita, nós fazemos a primeira potência de 2, no
caso, $2^0$ multiplicada pelo coeficiente, que é o dígito mais a
direita, no caso 0; depois nos fazemos $2^1$, a segunda potência,
vezes o segundo dígito da esquerda para direita, que é 1, *und so
weiter* (meus conhecimentos de alemão vêm de aulas de matemática e,
aparentemente, *und so weiter* quer dizer "assim por
diante"). Depois disso, nós somamos tudo e bang!, temos 42, que é o
que $101010_b$ representa em binário!

[http://i.imgur.com/OvWYeH4.gif]

Vamos fazer outro número, o $101_b$:

$101 = ( 1 \times 2 ^ 2 ) + ( 0 \times 2 ^ 1 ) + ( 1 \times 2 ^ 0 )$
$    = 4 + 0 + 1 = 5$

Logo, $101_b = 5_10$.

Fácil, certo? Tudo vem do fato que a representação é conveniente para
fazer contas. E você ainda pode ignorar todos as potências
multiplicadas por $0$ :)

# Convertendo de base 10 para base 2

O inverso já não é tão facil, mas ainda assim é bem simples!

Vamos pensar: se nós usamos multiplicação para ir da base 2 para base
10, o que nós precisamos para fazer o **inverso**? Hum,
inverso... inverso da multiplicação... Isso! Divisão! Nós vamos
dividir!

[http://i.imgur.com/qtmXq.gif]

Não só, queremos também ir da base 10 para a base 2, então vamos
dividir os números em base 10 por... 2! Várias vezes!

Ou seja, o processo é o seguinte: pegamos o número em base 10 e
dividimos ele por 2, do jeito que fazíamos na segunda série. Por
exemplo, se o número for 5, $5 \div 2$ é igual a 2 e sobra 1. Vamos
deixar esse 1 que sobrou guardado na nossa "lista": {1}. Depois,
dividimos o resultado da primeira divisão por 2 de novo: pegamos o 2 e
dividimos por 2: $2 \div 2$ é 1 e sobra 0. Colocamos o nosso segundo 1
de resto na nossa lista, {1, 0}. Depois fazemos isso de novo: pegamos
o resultado anterior, que era 1, e dividimos por 2: $1 \div 2$ tem
resultado 0 e sobra 1. Colocamos esse 1 na nossa lista, que agora tem
{1, 0, 1} e paramos, pois chegamos a um resultado 0. Para termos o
número 5 em binário, basta olharmos os elementos da lista, os restos,
mas **ao contrário**, $5_10 = 101_b$! (O exemplo foi meio infeliz,
dado que a lista é igual ao contrário XD).

A imagem a seguir vai ilustrar o processo:

[http://i.imgur.com/3vTFChF.png]

Façamos a conversão de 42 para binário:

- Passo 1) Dividimos 42 por 2: resultado é 21 e o resto é igual
a 0. Colocamos 0 na nossa lista {0}.

- Passo 2) Dividimos o resultado do passo 1 por 2: $21 \div 2$ dá 10 e
sobra 1. Colocamos 1 na nossa lista, que passa a ter {0, 1}.

- Passo 3) Dividimos o resultado de passo 2 por 2: $10 \div 2$. O
resultado é 5 e sobra 0. Colocamos 0 na lista, {0, 1, 0}.

- Passo 4) Dividimos o resultado do passo 3 por 2: $5 \div 2$, que dá
  2 e sobra 1. O 1 vai para a lista: {0, 1, 0, 1}.

- Passo 5) Estamos acabando! Pegamos o 2, o resultado do passo 4, e
  dividimos por 2: $2 \div 2$, que dá 1 e e sobra 0. Colocamos o 0 na
  lista: {0, 1, 0, 1, 0}

- Passo 6) O penúltimo! Divimos o 1 que deu no passo 5 por 2, e obtemos 0
  com resto 1. Colocamos esse 1 na lista {0, 1, 0, 1, 0, 1} e paramos,
  pois o resultado deu 0.

- Passo 7) Para acabar, invertemos a lista e temos o nosso número:
  $101010_b = 42_10$.

E é isso!

Para treinar, converta os seguintes números para binário:

1) 16 2) 31 3) 2

Agora você já sabe converter de uma base para a outra! Parabéns!

[http://i.imgur.com/Jdvdr.gif]
