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
        size_t total = 0;
        size_t free = 0;
        int count;

        cudaError_t error = cudaGetDeviceCount(&count);

        if (error == cudaSuccess)
        {
            for (int i = 0; i < count; i++)
            {
                if (cudaSetDevice(i) == cudaSuccess)
                {
                    error = cudaMemGetInfo(&free, &total);

                    if (error != cudaSuccess)
                    {
                        return new size_t[2]{total, free};
                    }
                }
            }
        }

        return new size_t[2]{total, free};
    }

    export void freeVRAMInformation(size_t *vramInfo)
    {
        delete[] vramInfo;
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
    std::cout << "isAnyApplicationFullscreen: " << isAnyApplicationFullscreen() << std::endl;

    /*
    ** Function: getVRAMInformation
    ** Explanation: Returns the total and free VRAM in bytes.
    ** Return value: An array of size_t with the total and free VRAM in bytes.
    */
    size_t *vramInfo = getVRAMInformation();
    std::cout << "total: " << vramInfo[0] << " free: " << vramInfo[1] << std::endl;
    delete[] vramInfo;

    return 0;
}