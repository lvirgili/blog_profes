# Binario, a "lingua" do computador

## O computador e **burro**

Muitos alunos comecam a fazer aulas de programacao achando que o
computador e uma entidade super-poderosa capaz de milagres depois de
umas poucas linhas escritas.

Nada poderia estar mais errado. O computador e uma maquina idiota!
Tanto e que ele so sabe falar duas "palavras": 0 e 1.

!<http://i.imgur.com/rYx08.gif>

Quando nos programamos e tornamos nosso codigo executavel, o que
fazemos, de forma bastante abstrata, e transformar as palavras que nos
entendemos em um monte de zeros e uns. Esses zeros e uns sao as
palavras que o computador entende!

Logo, e fundamental entendermos o que podemos fazer com apenas zeros e
uns e qual e a relacao entre eles e os numeros que usamos no nosso
dia-a-dia.

## Bases

### Base 10

Nao sei se voce ja reparou, mas usualmente os seres humanos tem 10
dedos, 5 em cada mao.

![http://i.imgur.com/wm9Srgj.gif]

Nao e de se estranhar, entao, que nos usemos 10 numeros para contar:
0, 1, 2, 3, ... ate 9. Usando apenas esses numeros, nos conseguimos
expressar todas as quantidades numericas, nao e? Afinal, 178 nada mais
e que um - sete - oito. Como usamos 10 numeros para expressar
quaisquer outros numeros, dizemos que usamos **base 10** para contar.

Agora, como sabemos que 178 significa cento e setenta e oito? E bem
facil! Voce lembra do material dourado, aqueles quadradinhos que a
gente usava na segunda(?) serie:

![http://paje.fe.usp.br/~labmat/edm321/1999/material/imagens/mdb1.JPG]

Como ele nos conseguiamos expressar numeros, certo? Por exemplo, para
fazermos 178 nos pegariamos 8 quadradinhos (que valem um), 7 tirinhas
(que valem 10) e 1 quadrado (que vale 100). Logo, temos $8 + ( 7 \times 10
) + (1 \times 100 )$, o que da 178!

Um numero em base 10 e exatamente isso: dizemos quantas unidades,
quantas dezenas, quantas centenhas, quantos milhares e assim por
diante, um numero tem.

Vamos fazer mais um exemplo, 1256:

$1256 = ( 1 \times 1000 ) + ( 2 \times 100 ) + ( 5 \times 10 ) + ( 6 \times 1 )$

Ou seja, 1256 e composto por 6 unidades, 5 dezenas, 2 centenas e um
milhar.

Voce percebeu que o numero "comeca" na direita? A unidade, que sao
quantos quadradinhos sozinhos tem no numero, e o numero mais a
direita! Depois, a esquerda da unidade, vem a dezena, que representa
quantos "dezes" tem no numero, e assim por diante.

Se voce ja sabe potencias, deve ter percebido que estamos compondo o
numero em funcao de potencias de 10: quantas unidades sao quantos $10
^ 0$ temos no numero; quantas dezenas significa quantos $10 ^ 1$
temos; centenas quantos $10 ^ 2$, e assim por diante.

Antes de continuar, pense na decomposicao dos seguintes numeros em
unidades, dezenas e etc.:

1) 1234
2) 7
3) 749

### Base 2

Tambem nao sei se voce ja reparou, mas o computador nao tem dedo
nenhum. Mas ele nao usa base 0!

![http://i.imgur.com/ZpTnG8C.gif]

O computador usa base 2. Por que? Eletrecidade! O computador consegue
representar 0 e 1 pois ele "converte" voltagens especificas dentro
dele para numeros.

Sabendo disso, como um numero e representado no computador? Exatamente
do mesmo jeito que nos represetamos em base 10, mas em base 2! Em base
10 nos falamos quantas unidades, dezenas, centenas, milhares e assim
por diante "cabem" no numero, certo? Em base 2, e extamente a mesma
coisa, mas ao inves de dezenas, centenas e etc. falamos quantos
"dois's", quantos "quatros", quantos "oitos" e assim por diante cabem!

Como base 2 e analoga a base 10, estamos fazendo exatamente a mesma
coisa: quantos $2 ^ 0$ cabem no numero, depois quantos $2 ^ 1$, $2 ^
2$ e assim ate acabar.

So mais uma diferenca entre a base 10: se ela usa 10 numeros para
compor todos os outros numeros, quantos numeros voce acha que a base 2
usa? Muito bem, 2!

![http://i.imgur.com/RVyP9.gif]

Entao, em binario so podemos usar 0 ou 1 como coeficientes (os numeros
que vem na frente das potencias de 2). Vamos fazer um exemplo, 101010.

O que 101010 quer dizer? Se ele fosse um numero decimal ele seria:

$101010 = ( 1 \times 10 ^ 5 ) + ( 0 \times 10 ^ 4 ) + ( 1 \times 10 ^ 3 ) + ( 0 \times 10 ^ 2
) + ( 1 \times 10 ^ 1 ) + ( 0 \times 10 ^ 0 )$

Mas queremos em binario! A unica coisa que muda sao as potencias:

$101010 = ( 1 \times 2 ^ 5 ) + ( 0 \times 2 ^ 4 ) + ( 1 \times 2 ^ 3 ) + ( 0 \times 2 ^ 2
) + ( 1 \times 2 ^ 1 ) + ( 0 \times 2 ^ 0 )$

Fazendo as contas, temos que o numero binario 101010 e igual $32 + 8 +
2 = 42$ em decimal, ou seja, a resposta para a vida, o universo e tudo
o mais!

![http://i.imgur.com/B0wld.gif]

Mais um exemplo:

$111 = ( 1 \times 2 ^ 2 ) + ( 1 \times 2 ^ 1 ) + ( 1 \times 2 ^ 0 )$

Logo, 111, em binario, representa o numero $4 + 2 + 1 = 7$ em base 10!

Espero que voce tenha percebido a similaridade entre a base 10 e a
base 2: ambas utilizam potencias (de 10 na base 10 e de 2 na base 2)
para compor os numeros. Contudo, a base 10 usa 10 digitos (de 0 a 9),
enquanto a base 2 usa apenas zeros e uns.

Para terminarmos, o que os numeros em binario a seguir representam em
base 10?

1) 11001
2) 100
3) 111100

Agora voce ja entende a classica piada: so existem 10 tipos de pessoas
no mundo, as que sabem binario e as que nao!

![http://i.imgur.com/10gvO.gif]





