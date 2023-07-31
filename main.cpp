#include "main.h"

extern "C"
{
    export bool isAnyApplicationFullscreen()
    {
        HRESULT hr;
        IDirectDraw7 *pDDraw = NULL;

        hr = DirectDrawCreateEx(NULL, (void **)&pDDraw, IID_IDirectDraw7, NULL);
        if (SUCCEEDED(hr))
        {
            hr = pDDraw->TestCooperativeLevel();
            if (hr == DDERR_EXCLUSIVEMODEALREADYSET)
            {
                pDDraw->Release();
                return true;
            }
        }

        pDDraw->Release();
        return false;
    }
}

/*
** Write all tests here. Preferably with the name of the function, a brief explanation, and print its return values.
*/
int main()
{
    /*
    ** Function: isAnyApplicationFullscreen
    ** Explanation: Checks if any application (or game) is in fullscreen mode.
    ** Return value: true if any application is in fullscreen mode, false otherwise.
    */
    std::cout << "isAnyApplicationFullscreen: " << isAnyApplicationFullscreen();

    return 0;
}