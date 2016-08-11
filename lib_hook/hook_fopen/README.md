1.try direct way(It is already CORRECT)

gcc -shared -fPIC fopen_h.c -o libfopen_h.so -ldl (Notice -ldl should be behind,then could be linked)<br/>
LD_PRELOAD=libfopen_h.so ./main fopen_h.c

2.try dlsym way

gcc -shared -fPIC fopen_gnu_h.c -o libfopen_gnu_h.so<br/>
LD_PRELOAD=libfopen_gnu_h.so ./main fopen_h.c

3.take hook to two part( fopen_h.c and dlsym.c )

gcc -shared -fPIC fopen_gnu_h.c dlsym.c -o libfopen_gnu_h.so<br/>
LD_PRELOAD=libfopen_gnu_h.so ./main fopen_h.c

GDB with PRELOAD
	http://stackoverflow.com/questions/10448254/how-to-use-gdb-with-ld-preload

Program received signal SIGSEGV, Segmentation fault.
0x00007ffff7de48e2 in _dl_lookup_symbol_x (undef_name=0x7ffff7bd8915 "dlsym",<br/>
    undef_map=0xffffffffffffffff, ref=0x7fffffffd9f8, symbol_scope=0x387, <br/>
    version=0x0, type_class=0, flags=2, skip_map=0x0) at dl-lookup.c:731<br/>
731	dl-lookup.c: 沒有此一檔案或目錄.

看起來是我的，hook 沒寫好 dlsym 都找不太到

關鍵字：
Function Interposition in Linux 

