Tower of Hanoi
if there are n disks move from A to C, n-1 A->B, n A->C.
How to put n-1 disks A to B?
using the same way: n-2 A->C, n-1 A->B.
recursively, until n==1.