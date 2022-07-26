---
marp: true
---

# Bitmask
## PCFIM

--------

## Desplazamiento de bits y negacion

$$
x = 1000 = 000000000000000000000001111101000
$$
$$
y = 4
$$

- `x >> y`: `000000000000000000000000000111110`
- `x << y`: `000000000000000000011111010000000`
- `~x`    : `111111111111111111111110000010111`

---------

## Operaciones con bits (BITWISE)

## Bitwise AND (`&`)

|`&`|1|0|
|---|-|-|
|1|1|0|
|0|0|0|

```cpp
int x = 3;  // 011 Representación binaria
int y = 4;  // 100 Representación binaria
int z = x & y // 000 Resultado de BITWISE AND
```

-----------

## Bitwise OR (`|`):

|$\vert$|1|0|
|-------|-|-|
|1|1|1|
|0|1|0|

```cpp
int x = 7;  // 111 Representación binaria
int y = 4;  // 100 Representación binaria
int z = x | y // 111 Resultado de BITWISE OR
```

-----------

## Bitwise XOR (`^`):

|`^`|1|0|
|---|-|-|
|1|0|1|
|0|1|0|

```cpp
int x = 10; // 1010 Representación binaria
int y = 4;  // 0100 Representación binaria
int z = x ^ y // 1110 Resultado de BITWISE XOR
```

-----------

### Verificar si el $j$-th bit es 1

```cpp
x & (1<<j)
```

### Prender el $j$-th bit

```cpp
x |= (1<<j)
```

### Apagar el $j$-th bit

```cpp
x &= ~(1<<j)
```

-------------

## 0-1 Knapsack problem

Dada una mochila con capacidad $C$, considerando tener $n$ objetos con sus respectivos pesos $w_i$ y valores $v_i$, determine el maximo valor que se puede llevar en ella sin que la suma de los pesos de los objetos sea mayor a $C$.

```cpp
for(int mask=0; mask<(1<<n); mask++){
    int peso_actual = 0;
    int valor_actual = 0;
    for(int i=0; i<n; i++){
        if(mask & (1<<i)){
            peso_actual += w[i];
            valor_actual += v[i];
        }
    }
    if(peso_actual <= C){
        max_valor = max(max_valor, valor_actual);
    }
}
```

------------

## Extra

```
Bits(-x) = Bits(~(x-1))

x&(-x) = 2^(bit menos significativo de x)
x&(x-1) = x - x&(-x)
```

### Iterar sobre submascaras

```cpp
for(int mask=0; mask<(1<<n); mask++){
    for(int submask=m; submask; submask=(submask-1)&mask){
        ...
    }
}
```