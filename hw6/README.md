== Binary search tree - deletion ==
Data is saved into a node stucture that include its value(int key), and two pointer link to the left and the right child.
為了可以print成tree的樣子, 在struct裡加了int index,去記綠在tree的index編號.
在print()裡implement,透過recursively call setindex(),去把有值的node設上其index,並加到tree[] array裡.
最後用finalprint()把結果印出

time complexity 為 O(n).
主要 insert() -O(n) 和 deleteNode() -O(n)
沒有nested loop.
所以是O(n)