SRC=$(wildcard *.md)
PDF=$(SRC:.md=.pdf)

all: $(PDF)

%.pdf: %.md
	pandoc --toc -V theme:metropolis -V defaultfont:1 --slide-level 2 -t beamer -s --template=default.beamer --highlight-style pygments $< -o $@

clean:
	rm -rf $(PDF)