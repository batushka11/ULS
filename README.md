# Ucode-Connect Track C uls
----
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
----

## About the program
Create a program that works as a system utility ls and implements basic functionality of this command:
 * the usage: usage: uls [-l] [file ...]
 * list of directory contents without flags
 * processing of *file* operands for files and directories
 * the *-l* flag, which is one of the most useful flags
 * the view of extended file attributes and access control lists (ACL)
 * error handling, as in the original *ls* . Output uls as the program name instead of ls where necessary
 * the multicolumn output format when the option *-l* isn't specified


## Example of console output
```shell
>./uls -z | cat -e
uls: illegal option -- z
usage: uls [-l] [file ...]

>./uls xxx
uls: xxx: No such file or directory

>./uls
dir1 dir2 dir3 file1 file2 file3 file4 file5

>./uls | cat -e
dir1$
dir2$
dir3$
file1$
file2$
file3$
file4$
file5$

>./uls dir1 dir2 file1 file2 file3
file1 file2 file3
dir1:
A.txt  E.txt  I.txt M.txt  Q.txt  U.txt  Y.txt
B.txt  F.txt  J.txt N.txt  R.txt  V.txt  Z.txt
C.txt  G.txt  K.txt O.txt  S.txt  W.txt
D.txt  H.txt  L.txt P.txt  T.txt  X.txt

dir2: # empty directory
>./uls -l | cat -e
total 0
drwxr-xr-x 4 neo staff 128 May 17 15:15 dir1$
drwxr-xr-x 2 neo staff  64 May 17 14:57 dir2$
drwxr-xr-x 2 neo staff  64 May 17 14:57 dir3$
-rw-r--r-- 1 neo staff   0 May 17 14:56 file1$
-rw-r--r-- 1 neo staff   0 May 17 14:56 file2$
-rw-r--r-- 1 neo staff   0 May 17 14:56 file3$
-rw-r--r-- 1 neo staff   0 May 17 14:56 file4$
-rw-r--r-- 1 neo staff   0 May 17 14:56 file5$
```

## Bulding the program
```shell
make install
```

## Note
The program builds only on MacOS