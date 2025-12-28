// pawn-algorithms-library.inc (PAL)
//      github.com/mateus-bsod



#if !defined _PAL_INCLUDED
    #define _PAL_INCLUDED
    #define PAL:: PAL_

    //#tryinclude <pal_pages>
    #tryinclude <PAL/pal_pages>
    //#tryinclude <../PAL/pal_pages>
    
    //#tryinclude <pal_sort>
    #tryinclude <PAL/pal_sort>
    //#tryinclude <../PAL/pal_sort>
    
    //#tryinclude <pal_str>
    #tryinclude <PAL/pal_str>
    //#tryinclude <../PAL/pal_str>

    //#tryinclude <pal_search>
    #tryinclude <PAL/pal_search>
    //#tryinclude <../PAL/pal_search>

#endif

#define _PAL_VERSION     (1000)
#define _PAL_DEBUG       (true)
#define _PAL_VERSION_URL "https://raw.githubusercontent.com/mateus-bsod/pawn-algorithms-library/refs/heads/main/version"

#if defined _PAL_VERSION 
    stock PAL::GetVersion()
        return _PAL_VERSION ;
#endif

stock PAL::Log()
{
    #if defined _PAL_DEBUG
        return _PAL_DEBUG;
    #endif
}

public OnGameModeInit()
{
    #if defined MyLib_OnGameModeInit
        MyLib_OnGameModeInit();
    #endif

    if(PAL::Log()) 
    {
        print("+-------------------------------+");
        print("|                               |");
        print("|                               |");
        print("|                               |");
        print("|  pawn-algorithms-library.inc  |");
        print("|                               |");
        print("|    Creator:                   |");
        print("|     github.com/mateus-bsod    |");
        print("|                               |");
        print("|                               |");
        print("|                               |");
        print("+-------------------------------+");
    }

    HTTP(0, HTTP_GET, _PAL_VERSION_URL, "", "_PAL_OnVersionResponse");
    return 1;
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit MyLib_OnGameModeInit

#if defined MyLib_OnGameModeInit
    forward MyLib_OnGameModeInit();
#endif

forward _PAL_OnVersionResponse(index, response_code, data[]);
public _PAL_OnVersionResponse(index, response_code, data[])
{
    if (response_code != 200)
    {
        if(PAL::Log()) print("[pawn-algorithms-library.inc]: Error when searching for version.");
        return 1;
    }

    new version = strval(data);
    if (version == _PAL_VERSION)
    {
        if(PAL::Log()) print("[pawn-algorithms-library.inc]: OK, Loaded.");
    }
    else if (_PAL_VERSION < version)
    {
        if(PAL::Log()) printf("[pawn-algorithms-library.inc]: Outdated (New Version %d / You Version %d)! Update at https://github.com/mateus-bsod/pawn-algorithms-library", version, _PAL_VERSION);
    }
    else if (_PAL_VERSION > version)
    {
        if(PAL::Log()) printf("[pawn-algorithms-library.inc]: That seems strange to me, but okay.");
    }
    return 1;
}