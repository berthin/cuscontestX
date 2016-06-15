README
======

Archivos principales & Organizacion
-----------------------------------
* "./problem-set/" carpeta que contiene todos los archivos tex, pdf, imagenes, inputs, outputs y soluciones correspondientes al problem-set.
* "./problem-set/main.tex" contiene la 'carátula'.
* "./problem-set/problems.tex" contiene la configuracion del problem-set.
* "./problem-set/problems/" carpeta que contiene los problemas (archivos latex)
* "./problem-set/problems/template.tex" modelo de un problema.
* "./problem-set/images/" contenedor de imagenes usadas para la descripcion de los problemas y caratula.
* "./problem-set/input/" carpeta donde estan los inputs.
* "./problem-set/ouput/" carpeta donde estan los ouputs.
* "./problem-set/soluciones/" carpeta donde estan las soluciones (CPP, JAVA, PYTHON, C#).

Para agregar un nuevo problema
------------------------------
* ``$cp ./problem-set/problems/template.tex ./problem-set/problems/NOMBRE-DEL-PROBLEMA.tex``
* Editar "./problem-set/problems.tex"
```
\begin{document}
[...lista de problemas previos...]
\input problems/NOMBRE-DEL-PROBLEMA
\end{document}
```
* En caso de que se requiran imagenes, colocarlas en "./problem-set/images/", y para agregarlas unicamente
```
 \begin{figure}[h]
   \centering
   \includegraphics[width=5cm]{images/figure-name.pdf}
   \caption{Caption-figure.}
   \label{fig:label-figure}
\end{figure}
```
Compilar
--------
* ``$ cd problem-set && make && cd ..`` o simplemente  ``$make$ si es que se encuentran dentro de "./problem-set/"
* Los archivos generados luego de compilar son:
    * "./problem-set/main.pdf" (solo caratula)
    * "./problem-set/problems.pdf" (solo problemas)
    * "./problem-set/problem-set.pdf" (Archivo principal que contiene la caratula y los problemas)
* Como ultimo paso, editar el archivo ''./problem-set/CusContestVariablesLatex.in'' bajo el siguiente orden:
```
DIA-DEL-CONCURSO
MES-DEL-CONCURSO
ANhO-DEL-CONURSO
CUSCONTEST-EDICION
NUMERO-DE-PAGINAS
NUMERO-DE-PROBLEMAS
```
Requerimientos
--------------
* [`make`](http://linux.die.net/man/1/make)
* [`pdfunite`](http://manpages.ubuntu.com/manpages/precise/man1/pdfunite.1.html)
* [`pdflatex`](https://help.ubuntu.com/community/LaTeX)
