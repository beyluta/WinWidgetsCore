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

    export size_t *getVRAMInformation()
    {
        size_t total;
        size_t free;

        cudaMemGetInfo(&free, &total);
        return new size_t[2]{total, free};
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

    /*
    ** Function: getVRAMInformation
    ** Explanation: Returns the total and free VRAM in bytes.
    ** Return value: An array of size_t with the total and free VRAM in bytes.
    */
    size_t *vramInfo = getVRAMInformation();
    std::cout << "getVRAMInformation: " << vramInfo[0] << " " << vramInfo[1] << std::endl;
    delete[] vramInfo;

    return 0;
}