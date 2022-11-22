# This is an example of Amit and Netanel first OS assignment
echo 'make all ->
'

make all # compiles all the binary
echo 'make clean ->
'

make clean # clean all the binary and .o and exectuable files

echo ' 

make cmp ->
' # for nice formatting

make cmp   # compiles and create the runnable file of cmp.c

# Examples for cmp

echo ' 

' # for nice formatting
echo 'Hello there,
How are you?' > mytext1.txt

echo 'Hello there,
How are you????' > mytext2.txt

./cmp mytext1.txt mytext2.txt  # not identical

echo 'Hello there,
How are you?' > mytext2.txt

./cmp mytext1.txt mytext2.txt  # identical

./cmp mytext1.txt mytext2.tx  # Usage : cmp <file1> <file2>

echo ' 

make copy ->
' # for nice formatting

make copy  # compiles and create the runnable file of copy.c

echo ' 

' # for nice formatting

# Examples of copy

./copy mytext1.txt mycopy1.txt # copy mytext1.txt to mycopy1.txt

ln -s mytext1.txt mylink.txt # creating a symbolic link called mylink.txt that points to mytext.txt

./copy mylink.txt mycopy2.txt # copy mylink.txt as a regular copy because no -l flag was  not sent

./copy mylink.txt mycopy2.txt -l # copy mylink.txt path of the file it points because -l flag was sent

rm mycopy1.txt

./copy mytext1.txt mycopy1.txt -l # copy mytext1.txt to mycopy.txt regular although -l was sent

./copy mylink.txt mycopy2.txt -f # Usage : copy <file1> <file2> -l because the flag was incorrect

echo ' 

make encode ->
' # for nice formatting

make encode # compiles and create the runnable file of encode.c and the lib files

echo ' 

' # for nice formatting

./encode codec1 HELLOworldMYnameISnetanel # helloworldmynameisnetanel

./encode codec1 HELLO@world#MY%name!IS*netanel # hello@world#my%name!is*netanel

./encode codec2 blaBLA  # no idea how this should look like
echo ' 

make decode ->
' # for nice formatting

make decode # compiles and create the runnable file of decode.c and the lib files

echo ' 

' # for nice formatting

./decode codec1 helloworldmynameisnetanel # HELLOWORLDMYNAMEISNETANEL

./decode codec1 HELLOworldMYnameISnetanel # HELLOWORLDMYNAMEISNETANEL

./decode codec1 HELLO@world#MY%name!IS*netanel # HELLO@WORLD#MY%NAME!IS*NETANEL

./decode codec2 BLAbla # no idea how this should look like

echo ' 

' # for nice formatting
make clean
rm mytext1.txt mytext2.txt mycopy1.txt mycopy2.txt mylink.txt