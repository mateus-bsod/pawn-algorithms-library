// pawn-algorithms-library.inc (PAL)
//      github.com/mateus-bsod

/*

[in @version 1000]
+ stock PAL::Str_IsEmpty(const text[])
+ stock PAL::Str_IsNumeric(const text[])
+ stock PAL::Str_IsAlpha(const text[])
+ stock PAL::Str_ToUpper(text[])
+ stock PAL::Str_ToLower(text[])
+ stock PAL::Str_Trim(text[])
+ stock PAL::Str_StartsWith(text[], prefix[])
+ stock PAL::Str_CountChar(text[], ch[])
+ stock PAL::Str_Replace(text[], find[], replace[])
+ stock PAL::Str_Explode(const text[], dest[][], max_parts, delim = '|')
+ stock PAL::Str_HasDigit(text[])
+ stock PAL::Str_HasSymbol(const text[])

[in @version 1100]
+ stock PAL::FixText(string[]) [Credits: https://portalsamp.com/showthread.php?tid=1147]

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

stock PAL::Str_Replace(text[], const find[], const replace[])
{
    new local = 0;
    while((local=strfind(text, find, true)) != -1)
    {
        strdel(text, local, local + strlen(find));
        strins(text, replace, local, sizeof(text));
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

stock PAL::FixText(const string[])
{
    new szFixed[1024], iPos, iLen;

    for(iLen = strlen(string); iPos < iLen; iPos ++)
        switch(string[iPos])
        {
            case '%':          szFixed[iPos] = 37;
            case '&':          szFixed[iPos] = 38;
            case '¡':          szFixed[iPos] = 64;
            case '°':          szFixed[iPos] = 124;
            case 'À':          szFixed[iPos] = 128;
            case 'Á':          szFixed[iPos] = 129;
            case 'Â':          szFixed[iPos] = 130;
            case 'Ä', 'Ã':     szFixed[iPos] = 131;
            case 'Ç':          szFixed[iPos] = 133;
            case 'È':          szFixed[iPos] = 134;
            case 'É':          szFixed[iPos] = 135;
            case 'Ê':          szFixed[iPos] = 136;
            case 'Ë':          szFixed[iPos] = 137;
            case 'Ì':          szFixed[iPos] = 138;
            case 'Í':          szFixed[iPos] = 139;
            case 'Î':          szFixed[iPos] = 140;
            case 'Ï':          szFixed[iPos] = 141;
            case 'Ò':          szFixed[iPos] = 142;
            case 'Ó':          szFixed[iPos] = 143;
            case 'Ô':          szFixed[iPos] = 144;
            case 'Ö', 'Õ':     szFixed[iPos] = 145;
            case 'Ù':          szFixed[iPos] = 146;
            case 'Ú':          szFixed[iPos] = 147;
            case 'Û':          szFixed[iPos] = 148;
            case 'Ü':          szFixed[iPos] = 149;
            case 'à':          szFixed[iPos] = 151;
            case 'á':          szFixed[iPos] = 152;
            case 'â':          szFixed[iPos] = 153;
            case 'ä', 'ã':     szFixed[iPos] = 154;
            case 'ç':          szFixed[iPos] = 156;
            case 'è':          szFixed[iPos] = 157;
            case 'é':          szFixed[iPos] = 158;
            case 'ê':          szFixed[iPos] = 159;
            case 'ë':          szFixed[iPos] = 160;
            case 'ì':          szFixed[iPos] = 161;
            case 'í':          szFixed[iPos] = 162;
            case 'î':          szFixed[iPos] = 163;
            case 'ï':          szFixed[iPos] = 164;
            case 'ò':          szFixed[iPos] = 165;
            case 'ó':          szFixed[iPos] = 166;
            case 'ô':          szFixed[iPos] = 167;
            case 'ö', 'õ':     szFixed[iPos] = 168;
            case 'ù':          szFixed[iPos] = 169;
            case 'ú':          szFixed[iPos] = 170;
            case 'û':          szFixed[iPos] = 171;
            case 'ü':          szFixed[iPos] = 172;
            case 'Ñ':          szFixed[iPos] = 173;
            case 'ñ':          szFixed[iPos] = 174;
            case '¿':          szFixed[iPos] = 175;
            case '`':          szFixed[iPos] = 177;
            default:           szFixed[iPos] = string[iPos];
        }

    return szFixed;
} 
