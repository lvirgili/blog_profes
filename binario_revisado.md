# Binário, a "língua" do computador

## O computador é **burro**

Muitos alunos começam as aulas de programação achando que o computador
é uma entidade super-poderosa capaz de realizar milagres com umas
poucas linhas escritas.

Nada poderia estar mais errado. O computador é uma máquina idiota!
Tanto é que ele só sabe falar duas "palavras": 0 e 1.

[http://i.imgur.com/rYx08.gif]

Quando programamos e tornamos nosso código executável, o que fazemos,
de forma bastante abstrata, é transformar as palavras que nós
entendemos em um monte de zeros e uns. Esses zeros e uns são as
palavras que o computador entende!

Logo, é fundamental entender o que podemos fazer com apenas zeros e
uns, e qual é a relação entre eles e os números que usamos no nosso
dia a dia.

## Bases

### Base 10

Não sei se você já reparou, mas usualmente os seres humanos tem 10
dedos, 5 em cada mão.

[http://i.imgur.com/wm9Srgj.gif]

Não é de se estranhar, então, que nós usemos 10 números para contar:
0, 1, 2, 3, ... até o 9. Usando apenas esses números, conseguimos
expressar todas as quantidades numéricas, não é? Afinal, 178 é nada
mais que **um - sete - oito**. Como usamos 10 números para expressar
quaisquer outros números, dizemos que usamos **base 10** para contar.

Mas como sabemos que 178 significa cento e setenta e oito? É bem
fácil! Você lembra do material dourado, aqueles quadradinhos que
usávamos no primário?

[http://paje.fe.usp.br/~labmat/edm321/1999/material/imagens/mdb1.JPG]

Com ele, nós conseguíamos expressar números, certo? Por exemplo, para
fazer 178, pegaríamos 8 quadradinhos (que valem um cada), 7 tirinhas
(que valem 10 cada) e 1 quadrado (que vale 100 cada). Logo, temos $8 +
( 7 \times 10 ) + (1 \times 100 )$, o que da 178!

Um número na base 10 é exatamente isso: dizemos quantas unidades,
dezenas, centenas, milhares etc., um número tem.

Vamos fazer mais um exemplo, 1256:

$1256 = ( 1 \times 1000 ) + ( 2 \times 100 ) + ( 5 \times 10 ) + ( 6
\times 1 )$

Ou seja, 1256 e composto por 6 unidades, 5 dezenas, 2 centenas e um
milhar.

Você percebeu que o número "começa" na direita? A unidade, que são
quantos quadradinhos sozinhos têm no numero, é o numero mais à
direita! Depois, à esquerda da unidade, vem a dezena, que representa
quantos "10" tem no número, e assim por diante.

Se você já sabe potência, deve ter percebido que estamos compondo o
número em função de potências de 10: quantas unidades são quantos $10
^ 0$ temos no numero; quantas dezenas significa quantos $10 ^ 1$
temos; centenas quantos $10 ^ 2$, e assim por diante.

Antes de continuar, pense na decomposição dos seguintes números em
unidades, dezenas etc.:

1) 1234 2) 7 3) 749

### Base 2

Também não sei se você já reparou, mas o computador não tem dedo
nenhum. Mas ele não usa base 0!

[http://i.imgur.com/ZpTnG8C.gif]

O computador usa base 2. Por quê? Eletricidade! O computador consegue
representar apenas 0 e 1, pois ele "converte" voltagens especificas
dentro dele para números.

Sabendo disso, como um número é representado no computador? Exatamente
do mesmo jeito que nós representamos na base 10, mas em base 2! Na
base 10, falamos quantas unidades, dezenas, centenas, milhares etc.
"cabem" no número, certo? Em base 2, é exatamente a mesma coisa, mas
em vez de dezenas, centenas etc., falamos quantos "dois", quantos
"quatros", quantos "oitos", assim por diante, cabem!

Como base 2 é análoga a base 10, estamos fazendo exatamente a mesma
coisa: quantos $2 ^ 0$ cabem no numero, depois quantos $2 ^ 1$, $2 ^
2$ e assim ate acabar.

Só há uma diferença entre a base 10 e a base 2: se ela usa 10 números
para compor todos os outros números, quantos números você acha que a
base 2 usa? Muito bem, 2!

[http://i.imgur.com/RVyP9.gif]

Então, em binário, só podemos usar 0 ou 1 como coeficientes (os
números que vem na frente das potências de 2). Vamos fazer um exemplo,
101010.

O que 101010 quer dizer? Se ele fosse um número decimal, ele seria:

$101010 = ( 1 \times 10 ^ 5 ) + ( 0 \times 10 ^ 4 ) + ( 1 \times 10 ^
3 ) + ( 0 \times 10 ^ 2 ) + ( 1 \times 10 ^ 1 ) + ( 0 \times 10 ^ 0 )$

Mas queremos em binário! A única coisa que muda são as potências:

$101010 = ( 1 \times 2 ^ 5 ) + ( 0 \times 2 ^ 4 ) + ( 1 \times 2 ^ 3
) + ( 0 \times 2 ^ 2 ) + ( 1 \times 2 ^ 1 ) + ( 0 \times 2 ^ 0 )$

Fazendo as contas, temos que o número binário 101010 é igual a $32 +
8 + 2 = 42$ em decimal, ou seja, a resposta para a vida, o universo e
tudo o mais!

[http://i.imgur.com/B0wld.gif]

Mais um exemplo:

$111 = ( 1 \times 2 ^ 2 ) + ( 1 \times 2 ^ 1 ) + ( 1 \times 2 ^ 0 )$

Logo, 111, em binário, representa o numero $4 + 2 + 1 = 7 $ em base
10!

Espero que você tenha percebido a similaridade entre a base 10 e a
base 2: ambas utilizam potências (de 10 na base 10 e de 2 na base 2)
para compor os números. Contudo, a base 10 usa 10 dígitos (de 0 a 9),
enquanto a base 2 usa apenas zeros e uns.

Para terminarmos, o que os números em binário a seguir representam em
base 10?

1) 11001
2) 100
3) 111100

Agora você já entende a clássica piada: só existem 10 tipos de pessoas
no mundo, as que sabem binário e as que não!

[http://i.imgur.com/10gvO.gif]
