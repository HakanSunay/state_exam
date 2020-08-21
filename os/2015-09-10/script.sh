# input params 12 34 56
# when prompted provide 5 6

var=1
for  i   in    4  3  2  1
do for  j # in 12 34 56
    do if test $i -gt $#
            then  var=` expr $var  \*  $i` # var=1*4=4;  var=4*4=16; var=16*4=64
                          echo $var   $j   >>  ff # 4 12 in ff;  16 34 in ff; 64 56 in ff
            else continue
       fi
    done
done

# i is 1
# j is 12
# var is 64

while true
do echo $* # -> 12 34 56
    break
done

read  k1 k2 # 5 6

while  cat ff  |  grep $k2 # -> 16 34; 64 56

do  set $k1 $var # params become: 5 64
    shift # 5 64 -> 64
    echo $2 # NOTHING ( empty line )
    grep  $i  ff
    # -> 4 12
    # -> 16 34
    exit
    echo $1
done

wc -l < ff

echo END

# My guess:
# 12 34 56
# 16 34
# 64 56
#
# 4 12
# 16 34

# Actual:
# matches