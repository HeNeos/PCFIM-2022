---
marp: true
---

# Binary Search
## PCFIM

------------

## Ejemplo 1

Dado un array **ordenado** de $n$ elementos. Responder $q$ queries, la $i$-th querie es: encontrar el primer elemento en el array que es mayor o igual a $x_{i}$.

### Task 1: $n \leq 10^{6}, q \leq 10^{2}$
### Task 2: $n \leq 10^{6}, q \leq 10^{6}$

------------

## Ejemplo 2

Dado un array **ordenado** de $n$ elementos. Responder $q$ queries, la $i$-th querie es: encontrar la posicion del primer elemento en el array que es igual a $x_{i}$ o $-1$ si no existe.

--------------

## Busqueda 0-1

Imaginen los problemas anteriores como un array de $0$'s y $1$'s. Ahora el problema se traduce a:

*encontrar el primer elemento que es 1*

Binary search se puede aplicar sobre funciones monotonas, o equivalentemente sobre un array de $0$'s y $1$'s. Note que:

- $0$: `false`
- $1$: `true`

-------------

## Binary sobre `double`

### Ejemplo

Encuentre la solucion ($x$) de:

$ax^{4} + bx^{3} + cx^{2} + dx + e = 0$

- $0 \leq a, b, c, d, e \leq 10$
- Se garantiza que $e \leq x$

-----------

## Binary sobre la respuesta

Se define un espacio de busqueda: `low`$\leq S \leq$`high`, y una funcion a *probar* $test$. Tal que, 

- si $test(x) = 1$, entonces $\forall y \in S\big \vert x\leq y$, $test(y)=1$.

- si $test(x) = 0$, entonces $\forall y \in S\big \vert y\leq x$, $test(y)=0$.

Si una *variable o funcion* cumple con estas condiciones, puede calcularse el primer elemento para el cual la respuesta es 1, usando binary search.

-------------

## Derivada discreta

Sea el polinomio: $p(x) = ax^2 + bx + c$. Se genera una coleccion ordenada de puntos aleatorios $x = [x_{0}, x_{1}, x_{2}, \ldots, x_{n-1}]$ y $y = [p(x_{0}), p(x_{1}), p(x_{2}), \ldots, p(x_{n-1})]$. Encontrar el minimo valor en el array $y$.