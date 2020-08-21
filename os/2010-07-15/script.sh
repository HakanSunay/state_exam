# running this with b1 b2 b3 as input params
# and then when prompted for input, providing b2

if test -z $5
then echo $1 # -> b1
         for var
         do
           echo  $var >> fniz
         done
else echo $2
        while true
        do echo LOOP
           break
        done
fi
cat fniz
# above line outputs, content of fniz file:
# -> b1
# -> b2
# -> b3
read string
until cat fniz | grep $string # this condition is true, because we get b2 as input and that is present in the file, therefore do done section is never reached, but this will return -> b2
do
  set  $2  b1
  echo  `grep  $2  fniz `
  echo  END
  exit
done
set $3  $1  1 # $1 becomes b3, $2 becomes b1, $3 becomes 1
echo OK $3 # -> OK 1
echo  ` grep  $1  fniz ` # -> b3
exit
echo  OK

# My guess:
# b1
# b1
# b2
# b3
# b2
# OK 1
# b3