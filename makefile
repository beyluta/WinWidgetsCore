all:
	g++ -o WidgetsDotNetCore main.cpp -lddraw -ldxguid
run:
	./WidgetsDotNetCore
dll:
	g++ -shared -o WidgetsDotNetCore.dll main.cpp -lddraw -ldxguid