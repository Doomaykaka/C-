#include <windows.h>
#include <stdio.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    int answer = MessageBox(NULL, "Block windows?", "Message for user", MB_YESNO);

    if(answer == IDYES){
        LockWorkStation();
    } else {
        MessageBox(NULL, "Its saad", "Message for user", MB_OK);
    }
}
