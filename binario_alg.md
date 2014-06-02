# Bin\'ario, a aventura final, ou implementando os algoritmos de convers\~ao

## *Previously, on LV's binary's saga*

Nos meus dois
[\'ultimos](https://br.portalprofes.com/lvirgili/blog/binario-a-lingua-do-computador)
[posts](https://br.portalprofes.com/lvirgili/blog/binario-o-retorno-ou-como-converter-de-binario-para-decimal)
, expliquei como funciona a famosa base 2, ou n\'umeros bin\'arios, e
como n\'os podemos converter n\'umeros da base 10 para a base 2 e
vice-versa. Se voc\^e ainda n\~ao leu (como n\~ao?!), vai l\'a dar uma
lida que eu espero!

[http://i.imgur.com/ddoV4Ny.gif]

## O algoritmo para ir da base 2 para a base 10

Agora que voc\^e j\'a sabe converter da base 2 para a base 10 na
m\~ao, voc\^e tamb\'em j\'a sabe o algoritmo! Coincid\^encia, n\~ao?

[http://i.imgur.com/MC4LE6X.gif]

Afinal, s\'o precisamos, a partir da unidade (o d\'igito mais \`a
direita do n\'umero), multiplicar o coeficiente pela pot\^encia de
2 adequada e somar tudo! Por exemplo:

$101010 = ( 1 \times 2 ^ 5 ) + ( 0 \times 2 ^ 4 ) + ( 1 \times 2 ^ 3
) + ( 0 \times 2 ^ 2 ) + ( 1 \times 2 ^ 1 ) + ( 0 \times 2 ^ 0 )$

Vamos escrever o programa que faz essa conta, para isso, usaremos a
linguagem [python][1] (padr\~ao 3), j\'a que ela \'e bem simples:

~~~ {.python .numberLines}
def binario_para_decimal ( n ):
    numero_em_decimal = 0
    expoente = 0
    while n > 0:
        dig = n % 10
        n = n // 10
        numero_em_decimal += dig * ( 2 ** expoente )
        expoente += 1

    return numero_em_decimal
~~~

Vamos entender o programa:

- Na linha 1 definimos a fun\c c\~ao, que \'e muito criativamente
  chamada de "binario_para_decimal". Ela recebe um n\'umero n como
  par\^ametro, que n\'os assumimos que \'e um n\'umero em
  bin\'ario;

- As linhas 2 e 3 inicializam a vari\'avel numero_em_decimal, que
  armazena, impressionantemente, o n\'umero em decimal, e o expoente
  da pot\^encia de 2 que estamos usando.

  A vari\'avel n\'umero em decimal \'e inicializada com 0, pois vamos
  somar cada um dos d\'igitos multiplicados pela sua pot\^encia de 2,
  sendo 0 o elemento neutro da adi\c c\~ao. J\'a expoente come\c ca
  com 0 pois \'e o primeiro expoente!

- Nas linhas 4 a 8, fazemos a m\'agica da transforma\c c\~ao em si!
  Para conseguirmos o d\'igito certo de n, basta calcularmos o resto
  de sua divis\~ao por 10, o que fazemos na linha 5. Na linha 6, n\'os
  dividimos n por 10, j\'a que n\~ao precisamos mais do d\'igito que
  acabamos de armazenar na vari\'avel dig.

  Na linha 7, n\'os somamos o d\'igito multiplicado pela
  pot\^encia de 2 correta, que \'e marcada pela vari\'avel expoente, a
  qual n\'os aumentaremos toda vez que fizermos uma conta.

- Para acabar, retornamos o valor armazenado na vari\'avel
  numero_em_decimal na linha 10.


Vejamos alguns exemplos:

~~~ {.python}
print(binario_para_decimal(111))
# Imprime 7
print(binario_para_decimal(101010))
# Imprime 42
print(binario_para_decimal(100))
# Imprime 4
print(binario_para_decimal(111111))
# Imprime 63
~~~

F\'acil, certo? Simplemente "traduzimos" a soma que a gente j\'a sabia
para python!

[https://i.imgur.com/EZxyUSP.gif]

## *There and back again*

Agora que sabemos ir da base 2 para a base 10, vamos fazer o caminho
inverso!

[http://i.imgur.com/rfbEp.gif]

Felizmente, converter um n\'umero para bin\'ario \'e muito f\'acil,
j\'a que s\'o precisamos dividir o n\'umero por 2 at\'e n\~ao poder
mais e pegar os restos, como  j\'a tinhamos visto antes.

A figura abaixo vai (de novo!) ajudar a gente:

[http://i.imgur.com/3vTFChF.png]

Vamos direto ao c\'odigo dessa vez, j\'a que s\'o vamos dividir o
n\'umero e colocar na nossa lista!

~~~ {.python .numberLines}
def decimal_para_binario ( n ):
    resto = n % 2
    lista =  [ resto ]
    n = n // 2
    while n != 0:
        resto = n % 2
        lista.append(resto)
        n = n // 2

    lista.reverse()
    lista = map(str, lista)
    numero = reduce(lambda x, y: x + y, lista)
    return numero

~~~

Na linha 3, n\'os colocamos o primeiro resto da divis\~ao de n por 2 na
nossa lista de restos, assim como vimos no post anterior (falei que
era para voc\^e ler!). Na linha 4, dividimos n por 2, j\'a que a
pr\'oxima divis\~ao \'e a do resultado por 2, e guardamos em n mesmo.

O while da linha 5 vai repetir isso: colocar o resto da divis\~ao de n
por 2 na lista e dividir n por 2 e guardar em n novamente, o que
fazemos nas linhas 6 e 7, respectivamente. N\'os paramos quando n for
0.

As linhas 10 a 12 s\'o invertem a lista e fazem ela se transformar no
n\'umero em bin\'ario mesmo, mas n\~ao s~ao importantes nesse momento:
basta saber que precisamos inverter a lista, j\'a que os restos
aparecem na ordem contr\'aria.

Vamos ver alguns exemplos:

~~~ {.python}
print(decimal_para_binario(42))
# Imprime 101010
print(decimal_para_binario(2))
# Imprime 10
print(decimal_para_binario(32))
# Imprime 100000
print(decimal_para_binario(63))
# Imprime 111111
~~~

Assim terminamos nossa aventura pelo bin\'ario. Parab\'ens!

[http://i.imgur.com/J6WkGPI.gif]



[1]: https://www.python.org/  "python"
