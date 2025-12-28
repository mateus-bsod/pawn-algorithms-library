// pawn-algorithms-library.inc (PAL)
//      github.com/mateus-bsod

/*

stock PAL::Str_IsEmpty(const text[])
stock PAL::Str_IsNumeric(const text[])
stock PAL::Str_IsAlpha(const text[])
stock PAL::Str_ToUpper(text[])
stock PAL::Str_ToLower(text[])
stock PAL::Str_Trim(text[])
stock PAL::Str_StartsWith(text[], prefix[])
stock PAL::Str_CountChar(text[], ch[])
stock PAL::Str_Replace(text[], find[], replace[])
stock PAL::Str_Explode(const text[], dest[][], max_parts, delim = '|')
stock PAL::Str_HasDigit(text[])
stock PAL::Str_HasSymbol(const text[])

*/

#if !defined _PAL_INCLUDED
    #define _PAL_INCLUDED
    #define PAL:: PAL_
#endif

#if !defined _PAL_STR_INCLUDED
    #define _PAL_STR_INCLUDED
#endif

stock PAL::Str_IsEmpty(const text[])
    return ((!(text[0])) || (((text[0]) == '\1') && (!(text[1]))));


stock PAL::Str_IsNumeric(const text[])
{
    for(new i = 0, j = strlen(text); i < j; i++)
    {
        if(text[i] > '9' || text[i] < '0') return 0;
    }
    return 1;
}

stock PAL::Str_IsAlpha(const text[])
{
    for(new i = 0; text[i] != EOS; i++)
    {
        if((text[i] < 'A' || text[i] > 'Z') &&
           (text[i] < 'a' || text[i] > 'z'))
            return 0;
    }
    return 1;
}

stock PAL::Str_ToUpper(text[])
{
    //for(new  i = 0; i < sizeof(text) ++i)
    for(new i = 0; text[i] != EOS; i++)
        text[i] = toupper(text[i]);
    return 1;
}

stock PAL::Str_ToLower(text[])
{
    //for(new  i = 0; i < sizeof(text) ++i)
    for(new i = 0; text[i] != EOS; i++)
        text[i] = tolower(text[i]);
    return 1;
}


stock PAL::Str_Trim(text[])
{
    new start = 0;
    new end = strlen(text) - 1;

    while(text[start] == ' ') start++;
    while(end >= start && text[end] == ' ') end--;

    if(start > 0)
        strdel(text, 0, start);
    text[end - start + 1] = EOS;
    return 1;
}

stock PAL::Str_StartsWith(text[], prefix[])
{
    if (strfind(text, prefix, true) == 0)
        return 1;
    return 0;
}

stock PAL::Str_CountChar(text[], ch[])
{
    new idx = 0;
    for(new i = 0; text[i] != EOS; i++)
    {
        if(text[i] == ch[0]) idx++;
    }
    return idx;
}

stock PAL::Str_HasDigit(text[])
{
    new idx = strlen(text);
    for(new i = 0; text[i] != EOS; i++)
    {
        if(text[i] > '9' || text[i] < '0') idx--;
    }
    return idx;
}

stock PAL::Str_Replace(text[], find[], replace[])
{
    new local = 0;
    while((local=strfind(text, find, true)) != -1)
    {
        strdel(text, local, local + strlen(find));
        strins(text, replace, local, sizeof replace);
    }
    return 1;
}

stock PAL::Str_Explode(const text[], dest[][], max_parts, delim = '|')
{
    new part = 0, idx = 0;

    for(new i = 0; text[i] != EOS && part < max_parts; i++)
    {
        if(text[i] == delim)
        {
            dest[part][idx] = EOS;
            part++;
            idx = 0;
            continue;
        }
        dest[part][idx++] = text[i];
    }
    dest[part][idx] = EOS;
    return 1;
}

stock PAL::Str_HasSymbol(const text[])
{
    for(new i = 0; text[i] != EOS; i++)
    {
        if(text[i] == ' ') continue;
        if(!((text[i] >= '0' && text[i] <= '9') ||
             (text[i] >= 'A' && text[i] <= 'Z') ||
             (text[i] >= 'a' && text[i] <= 'z')))
        {
            return 1;
        }
    }
    return 0;
}
