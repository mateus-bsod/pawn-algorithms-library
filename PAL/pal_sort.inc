// pawn-algorithms-library.inc (PAL)
//      github.com/mateus-bsod

#if !defined _PAL_INCLUDED
    #define _PAL_INCLUDED
    #define PAL:: PAL_
#endif

#if !defined _PAL_SORT_INCLUDED
    #define _PAL_SORT_INCLUDED
#endif


/*

stock PAL::BubbleSort_Float(Float:arr[], length = sizeof(arr))
stock PAL::BubbleSort(arr[], length = sizeof(arr))

*/

stock PAL_BubbleSort_Float(Float:arr[], length = sizeof(arr))
{
    new swapped, Float:temp;
    do {
        swapped = 0;
        for(new i = 0; i < length - 1; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
    } while(swapped);
}

stock PAL_BubbleSort(arr[], length = sizeof(arr))
{
    new swapped, temp;
    do {
        swapped = 0;
        for(new i = 0; i < length - 1; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
    } while(swapped);
}