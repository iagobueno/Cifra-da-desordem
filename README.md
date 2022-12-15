# Cifra da Desordem

## Introdução

A ideia da Cifra da Desordem é embaralhar o alfabeto baseado em uma chave e então usar técnicas de substituição já conhecidas.

## Algoritmo

### Estruturas

Foram utilizadas na implementação:

- Uma lista circular com todas as letras do alfabeto e os algarismos:

`abcdefghijklmnopqrstuvwxyz0123456789`

- Um buffer para guardar a lista embaralhada. Exemplo:
	
`a8ds734jf...`

- Uma hash table que será construída no final, indicando qual letra vira qual. Exemplo:

|   Esta letra   |  Vira esta |    
|----------------|------------|
|       a        |     x      |
|       g        |     k      |
|       f        |     3      |

### Chave

Dado nossa lista circular:

`abcdefghijklmnopqrstuvwxyz0123456789`

Iremos utilizar uma chave para manipular essa lista e criar uma tabela Hash de substituição.
A Chave é uma string qualquer composta de letras e números: `albini`, `iago99`, `k3y`.

Neste exemplo, usarei a string `arara13`.

Removemos as letras repetidas da chave:

|   Chave   |  Nova chave sem letras repetidas |    
|-----------|----------------------------------|
|  arara13  |               ar13               |

Salvamos o tamanho da nossa nova chave % 36, que é o tamanho da lista circular:

```
iterador = tamanho_nova_chave % 36
iterador = 4 % 36
iterador = 4
```

As letras que aparecem na chave serão removidas da nossa lista circular e acrescentadas ao início de um buffer.

**A** bcdefghijklmnopq **R** stuvwxyz0 **1** 2 **3** 456789

|               lista                  |   lista sem as letras da chave   | buffer |    
|--------------------------------------|----------------------------------|--------|
| abcdefghijklmnopqrstuvwxyz0123456789 | bcdefghijklmnopqstuvwxyz02456789 |  ar13  |


Agora, baseado no iterador, passamos por nossa lista removendo as letras e acrescentando ao fim do buffer.
Neste caso, a cada 4 interações removemos uma letra da lista. Até acabar nosso alabeto.

### Exemplo de interação

#### primeira interação

**B** cdefghijklmnopqstuvwxyz02456789 | cont = 1

b **C** defghijklmnopqstuvwxyz02456789 | cont = 2

bc **D** defghijklmnopqstuvwxyz02456789 | cont = 3

bcd **E** fghijklmnopqstuvwxyz02456789 | **cont = 4**

Neste momento, a letra 'E' sai da lista circular e vai para o fim do buffer.

#### segunda iteração

bcd **F** ghijklmnopqstuvwxyz02456789 | cont = 1

bcdf **G** hijklmnopqstuvwxyz02456789| cont = 2

bcdfg **H** ijklmnopqstuvwxyz02456789 | cont = 3

bcdfgh **I** jklmnopqstuvwxyz02456789 | **cont = 4**

Neste momento, a letra 'I' sai da lista circular e vai para o fim do buffer.

#### enésima iteração

Este comportamento se repete até a lista acabar.
Vale lembrar que a lista é circular, então quando chegar ao fim da lista ele apenas volta ao começo e continua.

#### Buffer e a Hash Table

Neste exemplo, o buffer final ficaria da seguinte forma:

`ar13eimqvz59fkpw28gnu4clx7jydth60bso`

Agora, basta substituir cada letra pela adjacente, como na cifra de César.
Para isso, criamos uma hash table em que cada letra será trocada pela adjacente.
No nosso exemplo:

|   Esta letra   |  Vira esta |    
|----------------|------------|
|       a        |     r      |
|       r        |     1      |
|       1        |     3      |
|      ...       |    ...     |
|       o        |     a      |

Texto claro de exemplo:

O milho cultivado para a produção da pipoca é de uma variedade especial.

#### Decifra

A decifra é análoga. A partir da chave, percorremos a lista para criar o buffer, montamos a tabela
hash com a letra anterior e substituímos cada letra pela letra anterior.

ar13eimqvz59fkpw28gnu4clx7jydth60bso



















