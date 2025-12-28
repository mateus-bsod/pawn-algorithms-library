![test](https://repository-images.githubusercontent.com/1124227725/e3fb5c45-cfa4-4454-84ff-5d121aa6ba15)

#
PAL (Pawn Algorithms Library) is designed to extend a_samp.inc by adding a broad set of high-level algorithms and utilities that are not available in the default SA-MP library.

#

- [PAL — Pawn Algorithms Library](#license)
  - `PAL/`pal_sort.inc             [Sort Functions](#palpal_sortinc)
  - `PAL/`pal_str.inc             [String Functions](#palpal_strinc)
  - `PAL/`pal_search.inc          [Search Functions](#palpal_searchinc)
  - `PAL/`pal_pages.inc           [Pages Functions](#palpal_pagesinc)

# PAL/pal_sort.inc
```pawn
stock PAL::BubbleSort_Float(Float:arr[], length = sizeof(arr))
stock PAL::BubbleSort(arr[], length = sizeof(arr))
```
#### Example of Use (PAL/pal_sort.inc):
```pawn
new Float:distances[] =
{
    12.5,
    3.2,
    9.8,
    1.1,
    7.75,
    4.0
};

printf("Before sort:");
for (new i = 0; i < sizeof(distances); i++)
{
    printf("%.2f", distances[i]);
}

PAL::BubbleSort_Float(distances);

printf("After sort:");
for (new i = 0; i < sizeof(distances); i++)
{
    printf("%.2f", distances[i]);
}
```
```pawn
Before sort:
12.50
3.20
9.80
1.10
7.75
4.00
After sort:
1.10
3.20
4.00
7.75
9.80
12.50
```
#### Example of Use (PAL/pal_sort.inc):
```pawn
new numbers[] = { 5, 12, 3, 7, 3, 9, 20, 1, 15 };

printf("Before sort:");
for (new i = 0; i < sizeof(numbers); i++)
{
    printf("%d", numbers[i]);
}

PAL::BubbleSort(numbers);

printf("After sort:");
for (new i = 0; i < sizeof(numbers); i++)
{
    printf("%d", numbers[i]);
}

```
```pawn
Before sort:
5
12
3
7
3
9
20
1
15
After sort:
1
3
3
5
7
9
12
15
20
```

# PAL/pal_pages.inc
```pawn
stock PAL::GetPageBoundsIter(page, Iterator:itens, bool:itens_tem[], start_page, end_page, total_items, itens_per_page_)
stock PAL::GetPageBounds(page, start_page, end_page, total_items, itens_per_page_)
stock PAL::GetTotalPages(total_items, itens_per_page_)
```
#### Example of Use (PAL/pal_pages.inc):
```pawn
new total_items = 30, page = 0, start, end;

PAL::GetPageBounds( page, start, end, total_items, 10);
printf("Page %d | Items %d to %d", page + 1, start, end);
page++;

PAL::GetPageBounds(page, start, end, total_items, 10);
printf("Page %d | Items %d to %d", page + 1, start, end);
page++;

PAL::GetPageBounds(page, start, end, total_items,10);
printf("Page %d | Items %d to %d", page + 1, start, end);

new total_pages = PAL::GetTotalPages( total_items, 10);
printf("Total pages: %d", total_pages);
```
```pawn
Page 1 | Items 0 to 10
Page 2 | Items 10 to 20
Page 3 | Items 20 to 30
Total pages: 3
```

# PAL/pal_search.inc
```pawn
stock PAL::Search_Jump(arr[], x, n)
stock PAL::Search_Binary(const arr[], size, value)
stock PAL::Search_First(const arr[], size, value)
stock PAL::Search_Last(const arr[], size, value)
stock PAL::Search_Linear(const arr[], size, value)
stock PAL::Search_interpolation(arr[], lo, hi, x)
```
#### Example of Use (PAL/pal_search.inc):
```pawn
new numbers[] = {
    5,12,3,7,3,9,20,33,42,18,27,14,6,2,11,8,19,25,31,44,
    52,41,36,29,23,17,10,4,1,13,15,16,21,22,24,26,28,30,32,34,
    35,37,38,39,40,43,45,46,47,48,49,50,51,53,54,55,56,57,58,59,
    60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,
    80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,
    100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175,180,185,190,195,
    200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,
    400,420,440,460,480,500,520,540,560,580,600,620,640,660,680,700,720,740,760,780,
    800,820,840,860,880,900,920,940,960,980,1000
};

new numbers_sorted[] = {
    1,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
    20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,
    40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,
    60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,
    80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,
    100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175,180,185,190,195,
    200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,
    400,420,440,460,480,500,520,540,560,580,600,620,640,660,680,700,720,740,760,780,
    800,820,840,860,880,900,920,940,960,980,1000
};

// ----------------------------
// BENCH CONFIG
// ----------------------------

new runs = 100000;
new start, total;
new Float:avg_ms;
new index;
new value = 980;

// ----------------------------
// LINEAR SEARCH
// ----------------------------

start = GetTickCount();
for (new i = 0; i < runs; i++)
{
    index = PAL::Search_Linear(numbers, sizeof numbers, value);
}
total = GetTickCount() - start;
avg_ms = float(total) / float(runs);

printf("\n[Linear Search]");
printf("Index: %d", index);
printf("Average time: %.5f ms", avg_ms);

// ----------------------------
// BINARY SEARCH
// ----------------------------

start = GetTickCount();
for (new i = 0; i < runs; i++)
{
    index = PAL::Search_Binary(numbers_sorted, sizeof numbers_sorted, value);
}
total = GetTickCount() - start;
avg_ms = float(total) / float(runs);

printf("\n[Binary Search]");
printf("Index: %d", index);
printf("Average time: %.5f ms", avg_ms);

// ----------------------------
// JUMP SEARCH
// ----------------------------

start = GetTickCount();
for (new i = 0; i < runs; i++)
{
    index = PAL::Search_Jump(numbers_sorted, value, sizeof numbers_sorted);
}
total = GetTickCount() - start;
avg_ms = float(total) / float(runs);

printf("\n[Jump Search]");
printf("Index: %d", index);
printf("Average time: %.5f ms", avg_ms);

// ----------------------------
// INTERPOLATION SEARCH
// ----------------------------

start = GetTickCount();
for (new i = 0; i < runs; i++)
{
    index = PAL::Search_interpolation(
        numbers_sorted,
        0,
        sizeof numbers_sorted - 1,
        value
    );
}
total = GetTickCount() - start;
avg_ms = float(total) / float(runs);

printf("\n[Interpolation Search]");
printf("Index: %d", index);
printf("Average time: %.5f ms", avg_ms);

// ----------------------------
// FIRST OCCURRENCE
// ----------------------------

start = GetTickCount();
for (new i = 0; i < runs; i++)
{
    index = PAL::Search_First(numbers_sorted, sizeof numbers_sorted, 3);
}
total = GetTickCount() - start;
avg_ms = float(total) / float(runs);

printf("\n[First Occurrence]");
printf("Index: %d", index);
printf("Average time: %.5f ms", avg_ms);

// ----------------------------
// LAST OCCURRENCE
// ----------------------------

start = GetTickCount();
for (new i = 0; i < runs; i++)
{
    index = PAL::Search_Last(numbers_sorted, sizeof numbers_sorted, 3);
}
total = GetTickCount() - start;
avg_ms = float(total) / float(runs);

printf("\n[Last Occurrence]");
printf("Index: %d", index);
printf("Average time: %.5f ms", avg_ms);

```
```pawn
[Linear Search]
Index: 169
Average time: 0.00687 ms

[Binary Search]
Index: 169
Average time: 0.00088 ms

[Jump Search]
Index: 169
Average time: 0.00915 ms

[Interpolation Search]
Index: 169
Average time: 0.04095 ms

[First Occurrence]
Index: 2
Average time: 0.00016 ms

[Last Occurrence]
Index: 3
Average time: 0.00686 ms
```

# PAL/pal_str.inc
```pawn
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
```
#### Example of Use (PAL/pal_str.inc):
```pawn
new bct[] = "    Mateus.Gosta.De.BlackMetal    ";

PAL::Str_Trim(bct);
printf(bct);                                                           // Print Result: Mateus.Gosta.De.BlackMetal

printf("%d", PAL::Str_CountChar(bct, "A"));                            // Print Result: 0
printf("%d", PAL::Str_CountChar(bct, "a"));                            // Print Result: 4
printf("%d", PAL::Str_HasDigit(bct));                                  // Print Result: 0
printf("%d", PAL::Str_HasDigit("3 jogos para 3 tigres infelizes"));    // Print Result: 2
printf("%d",PAL::Str_HasSymbol("Mateus123"));                          // Print Result: 0
printf("%d",PAL::Str_HasSymbol("Mateus@123"));                         // Print Result: 1
printf("%d",PAL::Str_HasSymbol("Black Metal"));                        // Print Result: 0
printf("%d",PAL::Str_HasSymbol("Black_Metal"));                        // Print Result: 1
printf("%d",PAL::Str_HasSymbol("123!"));                               // Print Result: 1

PAL::Str_ToLower(bct);
printf(bct);                                                           // Print Result: mateus.gosta.de.blackmetal

PAL::Str_ToUpper(bct);
printf(bct);                                                           // Print Result: MATEUS.GOSTA.DE.BLACKMETAL

PAL::Str_Replace(bct, "Gosta", "Odeia");
printf(bct);                                                           // Print Result: MATEUS.Odeia.DE.BLACKMETAL

PAL::Str_Replace(bct, ".", "-");
printf(bct);                                                           // Print Result: MATEUS-Odeia-DE-BLACKMETAL

new parts[4][32];
PAL::Str_Explode(bct, parts, 4, '-');
printf("%s", parts[0]);                                                // Print Result: MATEUS 

printf("%s", (PAL::Str_StartsWith(bct, "Mateus") ? "true" : "false")); // Print Result: true
printf("%s", (PAL::Str_IsAlpha(bct) ? "true" : "false"));              // Print Result: false (tem caracteries especiais)
printf("%s", (PAL::Str_IsNumeric(bct) ? "true" : "false"));            // Print Result: false
printf("%s", (PAL::Str_IsEmpty(bct) ? "true" : "false"));              // Print Result: false

```

# License
PAL exists to extend the life of the Pawn language. The goal of this project is not ownership or control, but evolution. The code is intentionally open, simple, and reusable so anyone can take it, modify it, improve it, and adapt it to their own needs.

PAL is designed to grow alongside SA-MP, extending a_samp.inc with new algorithms, utilities, and abstractions that make Pawn more practical and relevant over time. Reuse, refactoring, and enhancement are not only allowed but encouraged. The project assumes that its best future comes from being shared, studied, and rewritten by the community.

The focus is on usefulness, longevity, and collaboration. PAL does not aim to reinvent Pawn, but to keep it alive by giving developers better tools to work with the language they already use.
