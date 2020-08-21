# https://www.unix.com/302219737-post3.html

for  var  in  a1  a2  a3
do
  set  $var
done
shift
listpar=`echo  $*`
if  [  -n  "$listpart"  ]
then
  true
else
  false
fi
echo $?
echo $listpar


# Real output:
#
# 1
#

# I expected:
# 0
# a2 a3