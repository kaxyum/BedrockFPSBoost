#include <Windows.h>
#include "Utils/Utils.h"

int main()
{
    Utils utils;
    utils.setFPSBoost();

    MessageBox(NULL, "successfully boost your fps", "Message", MB_OK | MB_ICONINFORMATION);

    return 0;
}