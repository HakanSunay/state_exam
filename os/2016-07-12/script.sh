# 1 3 5 as input params
# c d when prompted

br=1
br=`expr $br  \*  $2` # br=1*3=3
a=$3 # a=5
set  ab  bc  cd  de # 1 3 5  -> ab bc cd de
shift # ab bc cd de -> bc cd de
while true
do echo $* # -> bc cd de;
  for  j # in bc cd de
  do  if test $# -lt $br
  then  br=` expr $br  /  2` #br=8/2=4; br=4/2=2
    echo $br   $j   >>  file # 4 cd go into file; 2 de go into file
    else br=`expr $br + $a` #br=3+5=8;
       echo  $br  $j   >>  file # 8 bc go into file;
      fi
  done
break
done
#file now has:
# 8 bc
# 4 cd
# 2 de
read  a1 a2 # c d
# below line outputs to stdout:
# 8 bc
# 4 cd
while cat file  |  grep $a1
do   echo $a $a2 # -> 5 d
       wc -l file # -> 3 file
       tail -5c file # -> 2 de
       exit
       echo FIN
done
echo $a  $a1
wc -c  file
tail -2l file

# My guess:
# bc cd de
# 8 bc
# 4 cd
# 5 d
# 3 file
# 2 de

# Actual:
# matches