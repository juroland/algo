LATEX_SRC=$(wildcard */*.tex)
LATEX_PDF=$(LATEX_SRC:.tex=.pdf)

FIGURE_SRC=$(wildcard */figures/*.svg)
FIGURE_PDF=$(FIGURE_SRC:.svg=.pdf)

all: $(FIGURE_PDF) $(LATEX_PDF)

%.pdf: %.svg
	rsvg-convert -f pdf -o $@ $<

%.pdf: %.tex
	rubber --pdf $<

clean:
	rubber --pdf --clean $(SRC)
	rm -rf $(FIGURE_PDF)
