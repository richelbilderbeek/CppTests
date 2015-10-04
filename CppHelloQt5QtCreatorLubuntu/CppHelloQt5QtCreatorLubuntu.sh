#!/bin/bash
myfile="qmake"
mytarget="CppHelloQt5QtCreatorLubuntu"
myprofile=$mytarget.pro

if [ ! -e $myprofile ]
then
  echo "Qt Creator project '$myprofile' not found"
  exit
fi

$myfile $myprofile

if [ ! -e Makefile ]
then
  echo $mytarget": FAIL (makefile not found)"
  exit
fi

make

if [ -e $mytarget ]
then
  echo $mytarget": SUCCESS"
else
  echo $mytarget": FAIL (executable not found)"
fi

#Cleaning up
rm *.o
rm Makefile
rm $mytarget
rm moc_*.*
rm ui_*.*
