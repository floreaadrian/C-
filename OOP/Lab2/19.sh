#!/bin/sh
x=0
find . -type f -name "*.c" | while read file ;do
   if [ $x -lt 10 ];then

      if test `wc -l $file | cut -f1 -d ' '` -gt 500; then
          echo $file
          x=$((x+1))
      fi

   else
      break;
   fi
done
