# Cifra de Desordem de Trafalgar

## Introdução

A ideia da cifra da desordem é embaralhar o alfabeto baseado em uma chave e então usar técnicas de substituição já conhecidas.

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

### Funcionamento

Dado nossa lista circular:

`abcdefghijklmnopqrstuvwxyz0123456789`

Iremos utilizar uma chave para manipular essa lista e criar uma tabela Hash de substituição.

A Chave é uma palavra qualquer do dicionário. Por exemplo:

`amar`

Guardamos o tamanho da chave(quantidade de carácteres) % 36, pois ele será nosso iterador

```
iterador = tamanho_da_palavra % 36
iterador = 4 % 36
iterador = 4
```

\* 36 é o tamanho da lista.

E removemos as letras repetidas da chave:

| Chave |  Chave sem letras repetidas |    
|-------|-----------------------------|
|  amar |             amr             |

Removemos essas letras da chave da nossa lista circular e colocamos no início de um buffer.

**a** bcdefghijkl **m** nopq **r** stuvwxyz0123456789

|               lista                  |   lista sem as letras da chave    | buffer |    
|--------------------------------------|-----------------------------------|--------|
| abcdefghijklmnopqrstuvwxyz0123456789 | bcdefghijklnopqstuvwxyz0123456789 |   amr  |


Agora, baseado no iterador, passamos por nossa lista removendo as letras e acrescentando ao fim do buffer.
Neste caso, a cada 4 interações removemos uma letra da lista. Até acabar nosso alabeto.

### Exemplo de interação

##### primeira interação

**b**cdefghijklnopqstuvwxyz0123456789 | cont = 1

b**c**defghijklnopqstuvwxyz0123456789 | cont = 2

bc**d**efghijklnopqstuvwxyz0123456789 | cont = 3

bcd**e**fghijklnopqstuvwxyz0123456789 | **cont = 4**

Neste momento, a letra 'e' sai da lista circular e vai para o fim do buffer

|              lista               | buffer |
|----------------------------------|--------|
| bcdfghijklnopqstuvwxyz0123456789 |  amre  |

##### segunda interação

bcd**f**ghijklnopqstuvwxyz0123456789 | cont = 1

bcdf**g**hijklnopqstuvwxyz0123456789 | cont = 2

bcdfg**h**ijklnopqstuvwxyz0123456789 | cont = 3

bcdfgh**i**jklnopqstuvwxyz0123456789 | cont = 4

Neste momento, a letra 'i' sai da lista circular e vai para o fim do buffer

|              lista              | buffer |
|---------------------------------|--------|
| bcdfghjklnopqstuvwxyz0123456789 |  amrei |

Este comportamento se repete até a lista acabar.
Vale lembrar que a lista é circular, portanto não há exatamente um "fim" dela.

#### Buffer e a Hash Table

Neste exemplo, o buffer final ficaria da seguinte forma:

`amreinsw048djpv16cktz7gq2bo3hyl95fxu`

Agora, basta substituir cada letra pela adjacente, como na cifra de César.
Para isso, criamos uma hash table em que cada letra será trocada pela adjacente.
No nosso exemplo:

|   Esta letra   |  Vira esta |    
|----------------|------------|
|       a        |     m      |
|       m        |     r      |
|       r        |     e      |
|      ...       |    ...     |
|       u        |     a      |

Texto claro de exemplo:

Sir Arthur Conan Doyle nasceu em Edimburgo, na Escócia, em 1859.

Wne Mezyae K3sms J3l9i smwkia ir Ijnroaeq3, sm Iwk3knm, ir 6DF5.

#### Decifra

A decifra é análoga. A partir da chave, percorremos a lista para criar o buffer, montamos a tabela
hash com a letra anterior e substituímos cada letra pela letra anterior.
