#include <stdio.h> 
#include <string.h> 
char files[20][20]; 
int n = 0;                        // one directory for the whole hospital 
int find(char *f) { 
for (int i = 0; i < n; i++) if (!strcmp(files[i], f)) return i; return -1; } 
void create(char *f) { 
if (find(f) >= 0) printf("Create %-12s -> FAILED (name already used)\n", f); 
else { strcpy(files[n++], f); printf("Create %-12s -> created\n", f); } } 
int main() { 
create("report.pdf"); 
create("xray.pdf"); 
create("ecg.pdf"); 
create("report.pdf");                             // another department, same name -> clash 
printf("Search ecg.pdf     -> %s\n", find("ecg.pdf") >= 0 ? "found" : "not found"); 
printf("Search lab.pdf     -> %s\n", find("lab.pdf") >= 0 ? "found" : "not found"); 
int k = find("xray.pdf"); 
strcpy(files[k], files[--n]);       // delete: move last file into the gap 
printf("Delete xray.pdf    -> deleted\nDisplay:"); 
for (int i = 0; i < n; i++) printf(" %s", files[i]); printf("\n"); } 
