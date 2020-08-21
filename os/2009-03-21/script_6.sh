# if compiled directory doesn't exist in /home, it will be created
if  test  -d  /home/compiled
then  :
else
  mkdir  /home/compiled
fi

# get all .c files in home directory
l_files=` ls  $HOME/*.c `

# get count of processes that have running terminals
proc=` ps  |  wc  -l `

# while the count is less than 5
while [  $proc  -lt  5  ]
do
  # will be executed once and it will create an executable for the fist .c file in l_files
  # the executable will be have the same name as the c file but with a suffix of .exe
  # the compilation will be run as a background process, because of the ampersand &
  for  i  in  $l_files
  do
    name=$i.exe
    cc  -o  $name  $i  &
    break
  done
  # im not sure if i will be accessible here
  # but if it is, the first .c file will be moved to /home/compiled
  mv  $i  /home/compiled
  # count of running processes will be updated if the compilation hasn't completed yet, this count will be increased by 1
  proc=` ps  |  wc  -l `
  # l_files count will be decreased if i were accessible beforehand
  l_files=` ls  $HOME/*.c `
done
