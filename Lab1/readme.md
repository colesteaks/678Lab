#Lab 1
##### Nicholas Jurden 2415098
I used the supplied *simple.c* file as a resource to answer the questions posed.
## Write up
#### Question 1
Commands as follows:
```
vim simple.c
```
copy 12 lines of code within vim:
```
12yy
```
generate 3 .c files
```
touch a.c b.c c.c
```
paste 12 lines in each file
```
vim a.c
p
:wq
```
```
vim b.c
p
:wq
```
```
vim c.c
p
:wq
```
<hr/>

#### Question 2
I used a buffer to stage another file and then switched to that file once I had the screen vertically split:
```
vim simple.c
:e simple.h
<c-w> v
:bnext
```
now I have two files open in the session, simple.c and simple.h, divided vertically:
![screenshot of vim](/split.png)
<hr/>

#### Question 3
to generate a directory of all functions
```
ctags -R
vim tags
```
see where all functions are declared, find the one I am looking for, go back to *simple.c*
```
vim simple.c
```

<hr/>

#### Question 4
to remove all whitespace, do a find and replace for the universal character for whitespace `\s`
```
vim whitespaceFile.c
:%s/\s//g
```

<hr/>

#### Question 5
another find and replace will solve this problem
```
vim billFile.c
:%s/Bill Self/baskeball genius Bill Self/g
```
