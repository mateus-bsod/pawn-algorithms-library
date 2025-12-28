// pawn-algorithms-library.inc (PAL)
//      github.com/mateus-bsod

/*

stock PAL::GetPageBoundsIter(page, Iterator:itens, bool:itens_tem[], start_page, end_page, total_items, itens_per_page_)
stock PAL::GetPageBounds(page, start_page, end_page, total_items, itens_per_page_)
stock PAL::GetTotalPages(total_items, itens_per_page_)

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
    stock PAL_GetPageBoundsIter(page, Iterator:itens, bool:itens_tem[], start_page, end_page, total_items, itens_per_page_)
    {
        start_page = page * itens_per_page_;
        end_page = start_page + itens_per_page_;
        if(end_page > total_items) end_page = total_items;
        foreach(new x : itens)
        {
            itens_tem[x] = true;
        }
        return 1;
    }
#endif

stock PAL_GetPageBounds(page, &start_page, &end_page, total_items, itens_per_page_)
{
    if (itens_per_page_ <= 0 || total_items <= 0)
    {
        start_page = 0, end_page = 0;
        return 0;
    }
    if (start_page >= total_items)
    {
        start_page = 0, end_page = 0;
        return 0;
    }

    start_page = page * itens_per_page_;
    end_page = start_page + itens_per_page_;
    if(end_page > total_items) end_page = total_items;
    return 1;
}

stock PAL_GetTotalPages(total_items, itens_per_page_)
    return (total_items + itens_per_page_ - 1) / itens_per_page_;