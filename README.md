
# OS-EX1
First Execise in OS Curse at Ariel University.<br />

## How to run the script ->  
the script tests all the functions of this assignemnt -[click here to see the script](https://github.com/amitmelamed/OS-EX1/blob/main/myScript.sh)
```
git clone https://github.com/amitmelamed/OS-EX1
cd os-EX1
./myScript.sh
```

used link:
https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/

Q1<br />
:Write a compare file program. Use FILE * API to read and compare the files.<br />
<Usage : cmp <file1> <file2<br />
Output : “Identical\n” or “Not identical\n or “Usage : cmp <file1> <file2>”. <br />
  <br />
Our Algorithm:<br />
  1.Open 2 input files<br />
  2.Check for valid files<br />
  3.For each Character In <file1><br />
  3.1 Copy to <file2><br />
  4.Close Input Files<br />
  <br />
 Q2<br />
  
  Write a copy file program. Use file descriptor API (open(2), read(2), write(2), close(2)) 
Usage : copy <file1><file2>
Output : file is copied. Or “Usage : copy <file1> <file2>”.
  
  Our Algorithm:<br />
  1.Open 2 input files<br />
  2.Check for valid files<br />
  3.For each Character In <file1><br />
  3.1 Compare to File 2 Char untill EOF <file2><br />
  3.2 Return Not Identical if we found missmatch
  4.Return Identical
  5.Close Input Files<br />
  <br />
  
 Q3 & Q4<br />
  3.	Support copying of symbolic links in copy. Use -l to copy link contents. Without -l copy the file linked by the symbolic link. Use readlink(2), stat(2), getopt(3)

note: -l means lower case 'L'

4.	Support enoding the file using codec library. Code two simple encoders.

Each encoderlib has two funcs 

a.	int encode(char * src, char * dst, int len)

b.	int decode(char * src, char * dst, int len)

codec1.so : Encoder converts uppercase chars to lowercase and vise versa. Doesn’t change all other chars.<br />

codec2.so : Encoder calculates NEG value of each char.<br />
  
  We implemented Decode and Encode functions 2 times, each time in different Dynamic Library.<br />
  The 2 different DL are codec1 and codec2 and they contains 2 different Implemantation to encode and decode functions.<br />
  encode.c and decode.c algorithm are similar: <br />
  1.Declaring the function pointer<br />
  2.Making Dynamic Library address by ./lib(input).so<br />
  3.open DL using dlopen(address)<br />
  4.pulling the function from our DL to our function pointer<br />
  5.call the function we created<br />
  
  
  

  
 
