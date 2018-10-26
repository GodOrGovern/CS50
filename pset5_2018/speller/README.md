# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

    From Oxford English Dictionary: "an artificial long word said to mean a lung disease caused by inhaling very fine ash and sand dust"

## According to its man page, what does `getrusage` do?

    From the getrusage() man page: "[it] shall provide measures of the resources used by the current process or its terminated and waited-for child processes"

## Per that same man page, how many members are in a variable of type `struct rusage`?

    There are 16 members in a variable of type struct rusage

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

    It is a waste of memory to duplicate their values for the calculate() function when passing by reference works equally well

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

    1 The for loop iterates over each character of the provided text file, stopping when the EOF signal is reached
        1.1 If the character is alphabetic or an apostrophe (in the latter case, the apostrophe cannot be the first character of the word) it is appended to an array called word, the index of which is then incremented by one
            1.1.1 If the value of index becomes larger than the allowed length of words (45 characters), the rest of the word is skipped and the index is set to 0
        1.2 Otherwise, if the word contains a number, the rest of the word is skipped and the index is set to 0
        1.3 Otherwise, if the index is greater than 0, it is assumed that a full word has been found; a NULL terminator is added to word[], the word counter is incremented, the spelling of the word is evaluated with the check() function, the index is set to 0
            1.3.1 If the word is misspelled, it is printed and the misspellings counter is incremented
    
## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

    It would be much more difficult to ensure only words with alphabetic characters (and apostrophes) are spell-checked, as numbers and other characters can be formatted into chars 

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

    Passing const ensures the variable cannot be changed, which is desirable for the check() and load() functions as any changes to their function arguments could render the functions themselves ineffectual
