br=0
for x in   a  b  c
do
  for y # for y in input_args
  do
    if test $y -lt $#
      then  br=` expr $br + 1`
        echo $br
      else continue
        echo $y
    fi
  done
  break
done

# Expected:
# 1
# 2