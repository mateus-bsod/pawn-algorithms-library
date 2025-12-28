// pawn-algorithms-library.inc (PAL)
//      github.com/mateus-bsod

/*


 */

#if !defined _PAL_INCLUDED
    #define _PAL_INCLUDED
    #define PAL:: PAL_
#endif

#if !defined _PAL_ARRAY_INCLUDED
    #define _PAL_ARRAY_INCLUDED
#endif

#if defined _PAL_SORT_INCLUDED
    stock PAL::Arr_SearchInt(arr[], value, size = sizeof(arr), bool:bubblesort = false, bool:last = false)
    {
        if(!bubblesort)
        {
            for(new i = 0; i < size; i++)
            {
                if(arr[i] == value)
                    return i;
            }
        }
        else
        {
            new index;
            PAL_BubbleSort(arr);
            index = last ? PAL::Search_Last(arr, size, value) : PAL::Search_First(arr, size, value);
            return index;
        }
        return (-1);
    }
#endif


//

stock PAL::Array_Clear(arr[], size = sizeof arr, value = 0)
{
    for(new i = 0; i < size; i++)
        arr[i] = value;
}

stock PAL::Array2D_Clear(arr[][], size1, size2, value = 0)
{
    for(new i = 0; i < size1; i++)
        for(new j = 0; j < size2; j++)
            arr[i][j] = value;
}

stock PAL::Array_Copy(const source[], dest[], size = sizeof(source))
{
    for(new i = 0; i < size; i++)
        dest[i] = source[i];

    return 1;
}

stock PAL::Array2D_Copy(const source[][], dest[][], size1 = sizeof(source), size2 = sizeof(source))
{
    for(new i = 0; i < size1; i++)
        for(new j = 0; j < size2; j++)
            dest[i][j] = source[i][j];
    return 1;
}
