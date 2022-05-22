# Pentaminos
*Algoritmo que resolve o problema de preencher tabuleiros com pentaminós, utilizando backtrack implementado com uma pilha.*

![image](https://user-images.githubusercontent.com/93349105/169685500-e06030d0-8a59-471a-a415-905dbd98244b.png)

A entrada deste algoritmo será dada por uma matriz A(m×n) representando o tabuleiro que deverá ser
coberta de pentaminós, tal que a(ij) = 0 se a figura deverá ser coberta e a(ij) = 1 caso contrário. A
saída deverá indicar se é possível colocar os 12 pentaminós para cobrir o tabuleiro e, nesse caso,
onde colocar cada um dos elementos.

Veja abaixo um exemplo:

Entrada:
```
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```
A saída pode ser (há várias soluções):
```
U U X P P P L L L L F T T T W W Z V V V

U X X X P P L N N F F F T W W Y Z Z Z V

U U X I I I I I N N N F T W Y Y Y Y Z V
```
Ou, por xemplo, a entrada:
```
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 1 1 0 0 0
0 0 0 1 1 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
```


