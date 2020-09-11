#include <cstdlib>
#include <Windows.h>

int main( )
{    
    ShellExecute(NULL, _T("open"), _T("\"C:\\Program Files\\ThrottleStop\\ThrottleStop.exe\""), NULL, NULL, SW_RESTORE);
    
    return 0;
}