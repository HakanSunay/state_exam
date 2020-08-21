# input params ab cd ef gh
# when prompted provide 3 1

# grep will get try to get all lines containing "line" from x1
# 5 line five
# 8 line eight
# 9 line nine
# 10 line ten
# wc -l will transform to 4 and save it to a file named f2
grep `head  -1 f1` `tail -1 f1` | wc -l > f2
a=`cat f2` # a=4
echo $a $3 # -> 4 ef
set  9  7  5  3 # ab cd ef gh -> 9 7 5 3
shift 2 # 9 7 5 3 -> 5 3
for j in 1  2  3  4  5
do for i #in 5 3
  do if test $a -lt $i
    then cat f1 f2 > f3 #f3 will contain the merged content of both f1 and f2
      wc -l f3 # -> 2 f3
      echo $i  $j  $a >> f4 # 5 1 4 go to f4
    else tee f2 f3 < f1 # content of f1 will be copied to f2 and f3 and sent to stdout
      wc -w f2 # -> 2 f2
      echo $i  $j  $a >> f4 # 3 1 4 go to f4
    fi
  done
  echo $# >> f4 # 2 go to f4 (in append mode)
  break
done
# f4:
# 5 1 4
# 3 1 4
# 2
read key1 key2 # 3 1
while cat f4 | grep $key2 # -> 5 1 4; 3 1 4
do  sort f4 # sorted output 2; 3 1 4; 5 1 4
  a=`wc -c < f4` # piping input will remove the filename from result
  echo -n "Character count: $a" # -> 14
  exit
done
grep $key1 f4
b=`wc -l < f4`
echo -n "Lines count: $b"
