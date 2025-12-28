// pawn-algorithms-library.inc (PAL)
//      github.com/mateus-bsod

// https://www.geeksforgeeks.org/dsa/interpolation-search/
// https://www.geeksforgeeks.org/dsa/jump-search/
// https://en.wikipedia.org/wiki/Jump_search

#if !defined _PAL_INCLUDED
    #define _PAL_INCLUDED
    #define PAL:: PAL_
#endif

#if !defined _PAL_SEARCH_INCLUDED
    #define _PAL_SEARCH_INCLUDED
#endif

#define _PAL_SEARCH_INVALID (-1)

/*

stock PAL::Search_Jump(arr[], x, n)
stock PAL::Search_Binary(const arr[], size, value)
stock PAL::Search_First(const arr[], size, value)
stock PAL::Search_Last(const arr[], size, value)
stock PAL::Search_Linear(const arr[], size, value)
stock PAL::Search_interpolation(arr[], lo, hi, x)


 */

stock PAL::Search_Jump(arr[], x, n)
{
    new step = floatsqroot(n);
    new prev = 0;

    while (arr[min(step, n)-1] < x)
    {
        prev = step;
        step += floatsqroot(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x)
    {
        prev++;
        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x) return prev;
    return -1;
}

stock PAL::Search_Binary(const arr[], size, value)
{
    new low = 0, high = size - 1, mid;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid] == value) return mid;
        if(arr[mid] < value) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}


stock PAL::Search_First(const arr[], size, value)
{
    for(new i = 0; i < size; i++)
        if(arr[i] == value)
            return i;
    return -1;
}


stock PAL::Search_Last(const arr[], size, value)
{
    for(new i = size - 1; i >= 0; i--)
        if(arr[i] == value)
            return i;
    return -1;
}


stock PAL::Search_Linear(const arr[], size, value)
{
    for(new i = 0; i < size; i++)
        if(arr[i] == value)
            return i;
    return _PAL_SEARCH_INVALID;
}

//
// arr[] ==> Array where elements need to be searched
// x     ==> Element to be searched
// lo    ==> Starting index in arr[]
// hi    ==> Ending index in arr[]
//
stock PAL::Search_interpolation(arr[], lo, hi, x)
{
    new pos;
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        pos = lo
              + (((hi - lo) / (arr[hi] - arr[lo]))
                 * (x - arr[lo]));

        if (arr[pos] == x) return pos;
        if (arr[pos] < x) return PAL::Search_interpolation(arr, pos + 1, hi, x);
        if (arr[pos] > x) return PAL::Search_interpolation(arr, lo, pos - 1, x);
    }
    return -1;
}