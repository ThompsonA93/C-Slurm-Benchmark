# Dependency Analysis
For a dependence source $S_1$ and a dependence sink $S_2$, we consider: 
- True Dependency: $S_1 \delta S_2$
- Anti-Dependency: $S_1 \delta^{-1} S_2$
- Output dependency: $S_1 \delta^O S_2$

## Iteration Vector
An iteration vector $I$ considers nested loops using iteration numbers $i_k$, where $k$ is the nesting level as $I = < i_1, i_2, ..., i_n>$.

We consider the Lexicographic order operator $<_q,\N^n,q \in [0,n[$.

An iteration I precedes iteration J, for $I <_q J \Leftrightarrow i_k = j_k \forall k \in [0,q[ \land i_q < j_q, q\in [0,n[$.\
Exemplary:
* $<1,2,3> <_0 <3,1,2>$
* $<5,5,1> <_1 <5,8,0>$
* $<2,2,2> <_2 <2,2,4>$
* $<1,2,3> \nless_0 <0,4,5>$

## Distance vector
For n nested loops, the distance vector $d(I,J)_k = j_k - i_k:\forall k \in [0,n[$ describes dependences among iterations (not array elements). It indicates if a dependence is loop-carried or loop-independent, requiring normalized loops.

$D(I,J)_k = \begin{cases}
    < & d(I, j)_k > 0 \\
    = & d(I, j)_k = 0:\forall k \in [0, n[ \\
    > & d(I, j)_k < 0 \\
\end{cases}$

The leftmost element of a direction vector must not be '>'; This would indicate a sink before source.