#! /bin/bash

set -e
set -x

TARGET=Fontaine_Sagot_TP%TPNUM%

rm -rf $TARGET $TARGET.tgz

make -C rendu/src clean

pushd rendu
pandoc --template tpl.tex --latex-engine=xelatex rapport.md -o rapport.pdf
popd

cp -r rendu $TARGET
tar czvf ${TARGET}.tgz --exclude '*.md' --exclude '*.tex' $TARGET

scp ${TARGET}.tgz lu:

set +x
