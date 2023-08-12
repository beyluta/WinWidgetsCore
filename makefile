all:
	g++ -o WidgetsDotNetCore main.cpp -lddraw -ldxguid -I"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.2\include" -L"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.2\lib" -L"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.2\lib\x64" -lcudart
run:
	./WidgetsDotNetCore
dll:
	g++ -shared -o WidgetsDotNetCore.dll main.cpp -lddraw -ldxguid -I"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.2\include" -L"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.2\lib" -L"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.2\lib\x64" -lcudart