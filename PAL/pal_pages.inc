// pawn-algorithms-library.inc (PAL)
//      github.com/mateus-bsod

/*

stock PAL::GetPageBoundsIter(page, Iterator:itens, bool:itens_tem[], start, end, total_items, ITEMS_PER_PAGE)
stock PAL::GetPageBounds(page, start, end, total_items, ITEMS_PER_PAGE)
stock PAL::GetTotalPages(total_items, ITEMS_PER_PAGE)
stock PAL::PrevPage(playerid, pagevar, min = 0)
stock PAL::NextPage(playerid, pagevar, TotalItems, ITEMS_PER_PAGE)

 */

#if !defined _PAL_INCLUDED
    #define _PAL_INCLUDED
    #define PAL:: PAL_
#endif

#if !defined _PAL_PAGES_INCLUDED
    #define _PAL_PAGES_INCLUDED
#endif


//#if defined _inc_y_foreach
#if defined _Y_ITERATE_FOUND
    stock PAL_GetPageBoundsIter(page, Iterator:itens, bool:itens_tem[], start, end, total_items, ITEMS_PER_PAGE)
    {
        start = page * ITEMS_PER_PAGE;
        end = start + ITEMS_PER_PAGE;
        if(end > total_items) end = total_items;
        foreach(new x : itens)
        {
            itens_tem[x] = true;
        }
    }
#endif

stock PAL_GetPageBounds(page, start, end, total_items, ITEMS_PER_PAGE)
{
    start = page * ITEMS_PER_PAGE;
    end = start + ITEMS_PER_PAGE;
    if(end > total_items) end = total_items;
}

stock PAL_GetTotalPages(total_items, ITEMS_PER_PAGE)
{
    return (total_items + ITEMS_PER_PAGE - 1) / ITEMS_PER_PAGE;
}

stock PAL_PrevPage(playerid, pagevar, min = 0)
{
    if(pagevar > min)
    {
        pagevar = pagevar-1;
        return 1;
    }
    return 0;
}

stock PAL_NextPage(playerid, pagevar, TotalItems, ITEMS_PER_PAGE)
{
    new start, end;
    PAL_GetPageBounds((pagevar+1), start, end, TotalItems, ITEMS_PER_PAGE);
    if(!end/*|| end == start*/)return 0;
    else if(end >= start)
    {
        pagevar = pagevar+1;
        return 1;
    }
    return 0;
}
