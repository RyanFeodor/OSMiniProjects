#include <stdio.h> 
#define TOTAL 32      // total disk blocks 
#define RESERVED 8    // blocks 0-7 reserved for inodes / metadata 
int used[TOTAL];      // 0 = free, 1 = allocated 
struct { char name[20]; int size; } f[] = {{"Alice_OS.pdf", 4}, {"Bob_DBMS.docx", 6},     {"Carol_CN.zip", 3}, {"Dave_AI.pdf", 5}, {"Eve_Thesis.pdf", 8}};  
int allocate(int size) {                        // find 'size' contiguous free blocks     
for (int s = RESERVED; s + size <= TOTAL; s++) {         
int ok = 1;         
for (int i = s; i < s + size && ok; i++) ok = !used[i];         
if (ok) { for (int i = s; i < s + size; i++) used[i] = 1; return s; }     
}     
return -1;                                  // no contiguous run large enough 
} 
int main() {     
printf("%-16s %-8s %s\n", "SUBMISSION", "SIZE(kB)", "BLOCKS");     
for (int n = 0; n < 5; n++) {         
int s = allocate(f[n].size);         
if (s < 0) printf("%-16s %-8d REJECTED (no contiguous space)\n", f[n].name, f[n].size);         
else       
printf("%-16s %-8d %d-%d\n", f[n].name, f[n].size, s, s + f[n].size - 1);     } } 
