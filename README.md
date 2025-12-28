# pawn-algorithms-library
PAL (Pawn Algorithms Library) is designed to extend a_samp.inc by adding a broad set of high-level algorithms and utilities that are not available in the default SA-MP library.

- [PAL — Pawn Algorithms Library](#-pal--pawn-algorithms-library)
- [String Functions](#palpal_strinc)

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
