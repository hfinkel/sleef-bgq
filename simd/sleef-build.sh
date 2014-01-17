#!/bin/sh

# Builds the patched SLEEF from http://shibatch.sourceforge.net/

REV=20130827
DEST=/home/projects/llvm/sleef-$REV
CC=/home/projects/llvm/bin/bgclang

for f in sleefsimddp sleefsimdsp; do
	$CC -O3 -fPIC -I. -DADD_UNDERSCORES -DNO_EXT_STRUCTS -DENABLE_QPX -c $f.c -g -o $f.o
done

ar cr libsleef.a sleefsimddp.o sleefsimdsp.o
$CC sleefsimddp.o sleefsimdsp.o -o libsleef.so.1.0 -shared -Wl,-soname,libsleef.so.1
ln -s libsleef.so.1.0 libsleef.so.1
ln -s libsleef.so.1 libsleef.so

mkdir -p $DEST
mkdir -p $DEST/lib
mkdir -p $DEST/include

for f in libsleef.a libsleef.so.1.0 libsleef.so.1 libsleef.so; do
	cp $f $DEST/lib/
done

cp qpxmath.h $DEST/include/
cp qpxmath.include $DEST/include/

