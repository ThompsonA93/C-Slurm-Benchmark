# Dependency Analysis
For a dependence source $S_1$ and a dependence sink $S_2$, we consider: 
- True Dependency: $S_1 \delta S_2$: Write-Read, flow dependency
```
x = ...
... = x
```
- Anti-Dependency: $S_1 \delta^{-1} S_2$: Read-Write, a false dependency
```
... = x
x = ...
```
- Output dependency $S_1 \delta^O S_2$: Write-Write, a false dependency
```
x = ...
x = ...
```

## Examples

```c
// 1. Loop-Independent Dependency
for(i = 2; i <= 4; i++)
    a[i] = b[i] + c[i];         // S1
    d[i] = a[i];                // S2
```
1: $S_1 \delta S_2$
- S1 is dependence source
- S2 is dependence sink
- Distance vector: i-(i) = 0
- Direction vector: d() = 0 <=> '='

```c
// 2. Loop-Carried True Dependency
for(i = 2; i <= 4; i++)
    a[i] = b[i] + c[i];         // S1
    d[i] = a[i-1];              // S2
```
2: $S_1 \delta S_2$
- S1 is dependence source
- S2 is dependence sink
- Distance vector: i-(i-1) = 1
- Direction vector: d() = 1 <=> '<'

```c
// 3. Loop-Carried Anti-Dependency
for(i = 2; i <= 4; i++)
    a[i] = b[i] + c[i];         // S1
    d[i] = a[i+1];              // S2
```
3: $S_1 \delta^{-1} S_2$
- S2 is dependence source
- S1 is dependence sink
- Distance vector: i-(i+1) = -1
- Direction vector: d() = -1 <=> '>'

```c
// 4. Nested Loop-Carried True dependency
for(i = 2; i <= 4; i++)
    for(j = 2; j <= 4; j++)
        a[i][j] = a[i-1][j+1]       // S1
```
4: $S_1 \delta S_1$
- S1 is dependence source
- S1 is dependence sink
- Distance vector: i-(i-1) = 1; j-(j+1) = -1
- Direction vector: d() = 1 <=> '<'; d() = -1 <=> '>'


```c
// 5. Mixed Loop-Carried dependences
for(i = 0; i < N; i++)
    a[i+1] = f[i+1];    // S1
    f[i] = a[i];        // S2

```
5: Array a: $S_1 \delta S_2$
- S1 is dependence source
- S2 is dependence sink
- Distance vector: i-(i-1) = 1
- Direction vector: d() = 1 <=> '<'

Array f: $S_1 \delta^{-1} S_2$
- S2 is dependence source
- S1 is dependence sink
- Distance vector: i-(i+1) = -1
- Direction vector: d() = -1 <=> '>'

# Iteration Vector
An iteration vector $I$ considers nested loops using iteration numbers $i_k$, where $k$ is the nesting level as $I = < i_1, i_2, ..., i_n>$.

We consider the Lexicographic order operator $<_q,\N^n,q \in [0,n[$.

An iteration I precedes iteration J, for $I <_q J \Leftrightarrow i_k = j_k \forall k \in [0,q[ \land i_q < j_q, q\in [0,n[$.\
Exemplary:
* $<1,2,3> <_0 <3,1,2>$
* $<5,5,1> <_1 <5,8,0>$
* $<2,2,2> <_2 <2,2,4>$
* $<1,2,3> \nless_0 <0,4,5>$

## Examples

```c
// 1. Dependency Level
for(i = 0; i < 10; i++)
    for(j = 0; j < 10; j++)
        for(k = 0; k < 10; k++)
            a[i][j][k+1] = a[i][j][k];  // S1
```
1: $S_1 \delta_k S_2$
- Level 'k' dependency, since it is the leftmost non-'=' component in direction vector

```c
// 2. Variable distance vector
for(i = 0; i < 10; i++)
    a[2*i] = b[i] + 1
    c[i] = a[i]
```
2: $S_1 \delta S_2$
- Distance Vector: d() = {1,2,3,4,5} <=> '*'
- Direction Vector: '<'

# Distance vector
For n nested loops, the distance vector $d(I,J)_k = j_k - i_k:\forall k \in [0,n[$ describes dependences among iterations (not array elements). It indicates if a dependence is loop-carried or loop-independent, requiring normalized loops.

$D(I,J)_k = \begin{cases}
    < & d(I, j)_k > 0 \\
    = & d(I, j)_k = 0:\forall k \in [0, n[ \\
    > & d(I, j)_k < 0 \\
\end{cases}$

The leftmost element of all '=' must be '<', otherwise sink before source.

# Dependence testing & parallelize
The previous information can be interpreted as a system of equations.

## Examples
```c
// 1. True dependence test
for(i = 2; i <= 4; i++)
    a[i] = b[i] + c[i];     // S1
    d[i] = a[i-1];          // S2
```
1: $S_1(I) \delta S_2(J)$
- I = <$i_0$>, J = <$j_0$>
- $\exists I,J:2\leq i_0 \leq j_0 \leq 4:i_0 = j_0 - 1$ 

```c
// 2. Anti-dependence test
for(i = 2; i <= 4; i++)
    a[i] = b[i] + c[i];     // S1
    d[i] = a[i+1];          // S2
```
2: $S_2(I) \delta^{-1} S_1(J)$
- I = <$i_0$>, J = <$j_0$>
- $\exists I,J:2\leq i_0 \leq j_0 \leq 4:i_0 = j_0 + 1$ 

```c
// 3. Anti-dependence test
for(i = 0; i < 10; i++)
    a[2*i] = b[i] + c[i];     // S1
    d[i] = a[2*i+1];          // S2
```
2: $S_2(I) \delta^{-1} S_1(J)$
- I = <$i_0$>, J = <$j_0$>
- $\exists I,J:0\leq i_0 \leq j_0 \leq 10: 2*i_0 = 2*j_0 + 1$


... Notably, if the latter index is bigger, we have an anti-dependency. If it is smaller, then we have a true dependency.

(slide 40)
Write before read: View system of equation; F is lefthand, J is righthand (J-1 => True dependence, J+1 => Anti-dependence)

(slide 43)
The first Index always carries the dependency

(slide 44, 45)
If loop index does not appear in lefthandside of an equation, its distance is unconstrained - thus ''*''.

(Slide 47)
Complications & Unknown variables & Boundaries

(Slide 49)
'=' can be parallelized.

(Slide 52)
Inner loops can be parallelized, if the inner loop must be executed sequentially

# Program transformation
(Slide 55 - Reordering)
Cache dependency: Columns before rows decreases performance - Cache misses
- Safe: Semantically same
- Valid: Safe dependencies

# Dependency elimination
(Slide 60)

