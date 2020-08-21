count=1
for i in 5 1 4 2
 do for j
  do if test $i -ge $#
    then count=`expr $count \* $i`
        echo $count $j >> f1
    else while true
        # will print input params
        do echo $* # -> ab cd ef
          break 3
        done
    fi
  done
  done
read k1 k2

# below line will print:
# 25 cd
# 125 ef
while cat f1 | grep $k2
do set $k1 $count # set will delete third param which is ef, only $k1 $count will be the params
  shift # shift will remove $k1 as param, therefore we will have only 1 param: $count
  echo $2 # ->
  echo $1 $i # -> 125 1
  exit
done
  echo FIN