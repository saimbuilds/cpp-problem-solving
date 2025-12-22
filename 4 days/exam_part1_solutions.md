# PART 1: SOLUTIONS (Condensed)

1. **Dangling Pointer:** UNDEFINED BEHAVIOR - accessing deleted memory
2. **Return Local:** UNDEFINED BEHAVIOR - returning stack array
3. **Memory Leak:** YES - leaked 3 arrays (9 ints total)
4. **Mystery:** `20` (p[4]=16, q[2]=4, 16+4=20)
5. **Use After Delete:** UNDEFINED BEHAVIOR
6. **Func Pointer:** `5` (arr={1,2,3,4}, 1+4=5)
7. **Memory Leak + Output:** `300` (100+200), YES leak of 3 ints
8. **Create Matrix:** `8` (m[0][2]=3, m[1][1]=5, 3+5=8)
9. **Pointer Increment:** `0 6` (arr={0,2,4,6})
10. **Process Replace:** `6` (arr={5,4,3,2,1}, 5+1=6)
11. **Pointer Array:** `30` (10+20)
12. **Return Offset:** `200 300`, LEAK - need `delete[] (p-1);`
13. **Array Sum:** `34` (arr={1,4,9,16,25}, p=9, q=25, 9+25=34)
14. **Mystery Double:** `10` (arr={2,4,6,8}, 2+8=10)
15. **Matrix Row:** `3` (p={1,2,3}, 1+2=3)
16. **Create Offset:** `32` (arr={10,13,16,19}, q=13, q+2=19, 13+19=32)
17. **Swap Pointers:** `17` (p points to q's array, q to p's, 2+15=17)
18. **Func Reverse:** `50` (arr reversed to {40,30,20,10}, 40+10=50)
19. **2D Offset:** `7` (p=3, q=4, 3+4=7)
20. **Mystery Diagonal:** `20` (diagonal: 1,3,5,7, sum=16... wait: i=0:1, i=1:3, i=2:5, i=3:7, sum=1+3+5+7=16)

**Actually #20:** `16` (diagonal elements: 1,3,5,7)

**Next:** Part 2
