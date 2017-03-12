
Skv is a key-value database based on leveldb.

Features in developing:
  A, String data type, list data type, hash data type.
  

Features will support:
  A, Set data type, sorted set data type.
  B, Strong consistency between master and slave(based on slog and wait-commit).
  C, Lua embeded.
  D, leveldb embeded.
  E, sentinel mechanism for high availability.


updated  Jan.31,2017

Tt is proved valigrind can not detect the memory leak problem in server programm.
valgrind -v --tool=memcheck --leak-check=full ./a.out
