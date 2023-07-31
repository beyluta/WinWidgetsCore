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
                return true;
            }
        }

        return false;
    }
}

int main()
{
    std::cout << "Is any game running: " << isAnyApplicationFullscreen();
    return 0;
}