all:
	pdflatex main.tex
	pdflatex problems.tex
	pdflatex problems.tex
	pdfunite main.pdf problems.pdf warm-up.pdf
	

clean: 
	rm -f *.aux *.bbl *.log *.blg *.dvi *.toc

cleanall: clean
	rm -f problems.pdf main.pdf warm-up.pdf
