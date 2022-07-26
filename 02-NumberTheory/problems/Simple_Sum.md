# Simple Sum

$$\sum_{i=1}^{n} \frac{n}{\gcd(i, n)}$$

## Solution 1: $O(\sqrt n)$

Note que $\gcd(i, n)$ tiene que ser algun divisor de $n$.

Asi, sea $k = \gcd(i, n)$ y, por tanto $k \vert n$:

$$ \sum_{i=1}^{n} \frac{n}{\gcd(i, n)} = \sum_{k\vert n} \frac{n}{k} \cdot \varphi(n/k) = \sum_{k\vert n} k \cdot \varphi(k) $$

Donde $\varphi(n/k)$ es la cantidad de numeros en el rango $1 - n$ tal que $\gcd(i, n) = k$:

$$ \sum_{i=1}^{n} \Big\vert \gcd(i, n) = k \Big\vert = \sum_{p=1}^{n/k}\Big\vert \gcd(p, n/k) = 1 \Big\vert = \varphi(n/k) $$

Es decir, $\varphi(n)$ es la cantidad de numeros coprimos con $n$ en el rango de $1$ a $n$. Esta funcion es llamada *Euler Totient Function*.

Ahora es suficiente con iterar sobre cada divisor de $n$ en tiempo $O(\sqrt n)$ y sumar $k \cdot \varphi(k)$:

```cpp
int ans = 0;
for(int i=1; i*i<=n; i++){
    if(n%i == 0){
        ans += i * phi(i);
        if(i != n/i) ans += (n/i) * phi(n/i);
    }
}
```

Para calcular $\varphi(n)$:

$$ \varphi(n) = n\prod_{p\vert n} \bigg(1-\frac{1}{p}\bigg) $$

Si conocieramos los factores primos de un numero $n$, $\varphi(n)$ se puede calcular en $O(\log n)$. Sin embargo, podemos modificar la criba para obtener un array con los valores de $\varphi(n)$:

```cpp
int phi[N];
void sieve(){
	phi[1] = 1;
	for(int i=2; i<N; i++){
		if(phi[i] == 0){
			phi[i] = i-1;
			for(ll j=2LL*i; j<N; j+=i){
				if(phi[j] == 0) phi[j] = j;
				phi[j] = phi[j]/i*(i-1);
			}
		}
	}
}
```
