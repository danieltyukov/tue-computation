// // Remove the first occurrence of remName in the startPos list.
// // Move the last name in the startPos list to the position of the name that you want to remove.
// // Do nothing if the name is not in the startPos list.

// // Example
// // startPos = ["one", "two", "three", "four"]
// // removeName("two")
// // startPos = ["one", "four", "three"]

// // avoid having address pointing to zero page

// // temporary nrNames

// int index = lookupNamePos(names, startPos, *nrNames, remName);
// if (index != -1)
// {
//     // remove the name from the startPos list
//     for (int i = 0; i < *nrNames; i++)
//     {
//         if (startPos[i] - names == index)
//         {
//             // move the last name in the startPos list to the position of the name that you want to remove
//             startPos[i] = startPos[*nrNames - 1];
//             startPos[*nrNames - 1] = NULL;
//             *nrNames = *nrNames - 1;
//             break;
//         }
//     }
// }
// // ==1485466==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000 (pc 0x55995606b507 bp 0x7ffc26774ad0 sp 0x7ffc26774ab0 T0)
// // ==1485466==The signal is caused by a WRITE memory access.
// // ==1485466==Hint: address points to the zero page.