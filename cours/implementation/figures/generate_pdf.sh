#!/bin/bash

for file in *.svg; do out=${file%.svg}.pdf; inkscape $file --export-pdf=$out; done
