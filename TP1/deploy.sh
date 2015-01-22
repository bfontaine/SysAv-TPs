#! /bin/bash

set -e
set -x

TARGET=Baptiste_Fontaine_TP1

rm -rf $TARGET $TARGET.tgz

make -C rendu/src clean

pushd rendu
pandoc --template tpl.tex --latex-engine=xelatex rapport.md -o rapport.pdf
popd

cp -r rendu $TARGET
tar czvf ${TARGET}.tgz --exclude '*.md' --exclude '*.tex' $TARGET

scp ${TARGET}.tgz lu:

set +x
