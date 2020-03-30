Here is a simple generator for LP test instances.

We consider an LP of the following style:

<img src="https://latex.codecogs.com/gif.latex?\begin{array}{rcl}&space;\max&space;&:&&space;c^T&space;x&space;\\&space;\text{s.t.}&space;&:&&space;Ax&space;\le&space;b&space;\\&space;&&space;&&space;x&space;\ge&space;0&space;\end{array}" title="\begin{array}{rcl} \max &:& c^T x \\ \text{s.t.} &:& Ax \le b \\ & & x \ge 0 \end{array}" />
The decision variable is <img src="https://latex.codecogs.com/gif.latex?$x&space;\in&space;R^n$" title="$x \in R^n$">
and the input data are <img src="https://latex.codecogs.com/gif.latex?$A&space;\in&space;R^{m&space;\times&space;n},&space;b&space;\in&space;R^m,&space;c&space;\in&space;R^n$" title="$A \in R^{m \times n}, b \in R^m, c \in R^n.$">

If we would like to generate an LP instance with 2 constraints, 4 variables and seed 1024 , execute
```
g++ -o lpgenerator.exe lpgenerator.cpp
./lpgenerator.exe 2 4 1024   
```

Then, problem-00002-00004-001024.txt contains lines like below:
```
2
4
224.647633,152.735865
8.423495,-8.058010,3.134649,1.519242
8.161801,7.050230,2.459731,7.800731
-0.342647,7.526406,2.667390,8.750367
```
The first line is the number of constraints (<img src="https://latex.codecogs.com/gif.latex?m" />),
the second is the number of variables (<img src="https://latex.codecogs.com/gif.latex?n" />),
the third is the right-hand-side vector (<a href="https://www.codecogs.com/eqnedit.php?latex=b&space;\in&space;R^m" target="_blank"><img src="https://latex.codecogs.com/gif.latex?b&space;\in&space;R^m" title="b \in R^m" /></a>),
the fourth is the coeffcient vector (<a href="https://www.codecogs.com/eqnedit.php?latex=c&space;\in&space;R^n" target="_blank"><img src="https://latex.codecogs.com/gif.latex?c&space;\in&space;R^n" title="c \in R^n" /></a>),
and the rest lines are the coeffcients in the matrix (<img src="https://latex.codecogs.com/gif.latex?A&space;\in&space;R^{m&space;\times&space;n}" title="A \in R^{m \times n}" />).




