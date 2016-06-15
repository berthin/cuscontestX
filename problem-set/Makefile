file1 = main
file2 = problems

all:
	pdflatex ${file1}.tex
	pdflatex ${file2}.tex
	pdfunite ${file1}.pdf ${file2}.pdf problem-set.pdf
	
clean:
	rm -f *.aux *.out *.idx *.log

cleanall:
	clean
