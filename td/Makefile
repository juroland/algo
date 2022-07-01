SRC=$(wildcard *.md)
PDF=$(SRC:.md=.pdf)

all: $(PDF)

%.pdf: %.md
	pandoc -t latex $< -o $@ -V documentclass:scrartcl -V geometry:margin=1in -V fontsize=10pt -V mainfont=Cantarell --latex-engine=xelatex

clean:
	rm -rf $(PDF)pandoc -t latex td4.md -o td4.pdf
