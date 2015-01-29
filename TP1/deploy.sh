#! /bin/bash -ex

TARGET=Fontaine_Sagot_TP1

rm -rf $TARGET $TARGET.tgz

make -C rendu/src clean man

pushd rendu
pandoc --template tpl.tex --latex-engine=xelatex rapport.md -o rapport.pdf
popd

cp -r rendu $TARGET
tar czvf ${TARGET}.tgz --exclude '*.md' --exclude '*.tex' \
  --exclude '*.dSYM' --exclude '.gitignore' $TARGET
