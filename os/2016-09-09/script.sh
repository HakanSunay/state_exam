# input params ab bc cd
# provide b c when prompted for read

count=1
for  i   in    6   1   4   2
do
  for each # in ab bc cd
  do if test $i   -gt  $#
    then  count=` expr $count  \*  $i` #count=1*6=6;count=6*6=36;count=36*6=216
      echo $count   $each  >>  f1 # 6 ab go into f1; 36 bc go into f1; 216 cd go into f1
    else until false
      do echo $* # -> ab bc cd
      break 3 # will break all outer loops
      done
    fi
  done
done
read  k1 k2 # b c
# below line will print
# 6 ab
# 36 bc
while   cat f1  |  grep $k1
do  set $k1 $k2 $count # b c 216
  shift # b c 6 -> c 216
  echo $1 $2 # -> c 216
  grep $2 f1 > f2 # 216 cd goes into f2
  wc -c f2 # -> 12 f2
  exit
  echo END
done
wc -l  f1
tail -2l f1
echo FIN

# My guess:
# ab bc cd
# 6 ab
# 36 bc
# c 216
# 7 f2

# Actual: matches
