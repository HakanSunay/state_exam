# run with 3 4 5 as params
# provide 6 7 when prompted

br=0
br=`expr $br + $2` # br = 4
set 3 5 7
shift # 3 5 7 --> 5 7
for  j # in 5 7
do for  var # in 5 7
   do if test $br -lt $2
         then br=` expr $br  \*  $2` # br=4 * 7
                    echo $br $var   $j   >>  file # 28 5 5 into file
         else br=`expr $br - $2` # br=28-7=21
                    echo $var $br $j >> file # 7 21 5 into file
      fi
   done
   echo $* # -> 5 7
   break
done
read  a1 a2 # 6 7
until cat file | grep $a1
do  echo $# # -> 2
    grep $1 file
    # above will print
    # -> 28 5 5
    # -> 7 21 5
    exit # termination
    echo END
done
echo $3
wc -l < file
echo FINAL

# My guess:
# 5 7
# 2
# 28 5 5
# 7 21 5

# Actual:
# matches my guess