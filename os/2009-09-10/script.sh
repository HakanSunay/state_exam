# on which line and what is being displayed to stdout

count=0
for  var  in  a1  a2  a3
 do
   echo  $var > fxxx
 done
 cat  fxxx # -> a3
 listpar=` grep a3 fxxx `
 echo $listpar > fyyy
 until cat fyyy | grep a2 > /dev/null # the first loop iter will return false, therefore we will go in the do - done section, since until executes if condition is false
 do
   count=` expr $count + 1 `
   echo a2 >> fyyy # next iter a2 will be successfully grepped and the loop will terminate
 done
echo $count # -> 1
echo $listpar # -> a3

# My output guess:
# a3
# 1
# a3

# Actual output:
# a3
# 1
# a3
