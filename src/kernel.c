#include <console.h>
#include <memory.h>

void kmain()
{
    char str[64] = {0};
    memset(str, 'A', 63);
    
    print(str);
}