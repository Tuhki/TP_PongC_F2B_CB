Build Options:
>Linker settings
>>Link librairies
	C:\SDL2-2.0.5\i686-w64-mingw32\lib\libSDL2main.a
	C:\SDL2-2.0.5\i686-w64-mingw32\lib\libSDL2.dll.a
	C:\SDL2-2.0.5\SDL2_ttf-2.0.14\i686-w64-mingw32\lib\libSDL2_ttf.dll.a
>>Other linker options
	-lmingw32

>Search directories
>>Compiler
	C:\SDL2-2.0.5\i686-w64-mingw32\include
	C:\SDL2-2.0.5\SDL2_ttf-2.0.14\i686-w64-mingw32\include
>>Linker
	C:\SDL2-2.0.5\i686-w64-mingw32\lib
	C:\SDL2-2.0.5\SDL2_ttf-2.0.14\i686-w64-mingw32\lib



Si jamais les raquettes vont trop vite, il suffit de supprimer les dep->x++; et dep->y++; (ou --) qui se répètent dans le même if dans les procédures gérant leurs déplacements. Idem pour balle->x et balle->y -- et ++.
Je les ai mis en plusieurs exemplaires car le jeu était très lent sinon ; et je n'ai donc pas eu à utiliser de delay.